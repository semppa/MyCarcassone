#include "server.h"

Server::Server(NetWorkController* netcontroller, QObject* parent) : QTcpServer(parent)
{
    netctrl_ = netcontroller;

    connect(this, SIGNAL(newConnection()), this, SLOT(newConnection()));
    connect(&sEventHandler_, SIGNAL(newData(QByteArray)), this, SLOT(echoData(QByteArray)));

    encoder_ = std::make_shared<DataEncoder>();
    std::shared_ptr<TileDatabase> tdb = std::make_shared<TileDatabase>();

    encoder_->setTileDB(tdb);
    sEventHandler_.setTileDB(tdb);
    sEventHandler_.setEncoder(encoder_);

    serverDataTypes = {DataType::StartGame, DataType::EndTurn, DataType::TilePlaced};
}

void Server::start(QString nick)
{
    if (listen(QHostAddress::Any, 13370)) {
        host_ = sEventHandler_.newPlayer(nick);
        QByteArray data = encoder_->encodePlayerData(host_, DataType::IConnected);
        netctrl_->newData(data);

        if (isListening()) {
            qDebug() << "[SERVER] Waiting for connection...";
        }
    } else {
        qDebug() << "[SERVER] Could not start server";
    }
}

void Server::newConnection()
{
    QTcpSocket* socket = nextPendingConnection();
    qDebug() << "[SERVER] New User!";

    // Reading nick
    QString nick;
    if (!socket->waitForReadyRead(5000)) {
        qDebug() << "[SERVER] Couldnt get nick";
        nick = "User";
    }
    nick = socket->readAll();

    // Creating player class for new connection
    std::shared_ptr<Player> player = sEventHandler_.newPlayer(nick);

    QByteArray data;

    // Sending player's info to itself
    data = encoder_->encodePlayerData(player, DataType::IConnected);
    socket->write(data);

    // Informing peers about new connection
    data = encoder_->encodePlayerData(player, DataType::NewUserConnected);
    echoData(data);

    // Sending host + peers to new connection
    data = encoder_->encodePlayerData(host_, DataType::NewUserConnected);
    socket->write(data);

    for (auto client : clients_) {
        data = encoder_->encodePlayerData(client.first, DataType::NewUserConnected);
        socket->write(data);
    }
    socket->flush();

    // Sending chat message that someone joined
    QDataStream s(&data, QIODevice::WriteOnly);
    s << DataType::Chat;
    s << QString("[SERVER]");
    s << QString(nick + " connected to the server.");
    echoData(data);

    // Adding new connection to database
    clients_.push_back({player, socket});

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void Server::readyRead()
{
    QTcpSocket* sender_client = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = sender_client->readAll();

    netctrl_->newData(data);

    for (auto client : clients_) {
        client.second->write(data);
        client.second->flush();
    }

    QDataStream s(&data, QIODevice::ReadOnly);
    DataType t;
    s >> t;

    if (serverDataTypes.find(t) != serverDataTypes.end()) {
        sEventHandler_.newServerData(data);
    }
}

void Server::disconnected()
{
    qDebug() << "[SERVER] Someone disconnected";
    QString disc_nick;

    int ind = 0;
    for (auto peer : clients_) {
        if (peer.second == sender()) {
            QByteArray data = encoder_->encodePlayerData(peer.first, DataType::UserDisconnected);
            disc_nick = peer.first->getNick();
            clients_.erase(clients_.begin() + ind);
            echoData(data);
            break;
        }
        ind++;
    }
    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);
    s << DataType::Chat;
    s << QString("[SERVER]");
    s << QString(disc_nick + " disconnected from the server.");
    echoData(data);
}

void Server::closeServer()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << DataType::ServerClosed;
    echoData(data);

    sEventHandler_.clear();
    close();

    qDebug() << "[SERVER] Server closed";
}

void Server::echoData(QByteArray data)
{
    netctrl_->newData(data);

    for (auto client : clients_) {
        client.second->write(data);
        client.second->flush();
    }

    QDataStream s(data);
    DataType t;
    s >> t;

    if (t == DataType::StartGame) {
        pauseAccepting();
    }
    if (serverDataTypes.find(t) != serverDataTypes.end()) {
        sEventHandler_.newServerData(data);
    }
}

