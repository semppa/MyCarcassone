#include "client.h"

Client::Client(NetWorkController* controller)
{
    controller_ = controller;
    socket = new QTcpSocket(this);
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

bool Client::connect(QString hostname, qint16 port, QString nick)
{
    qDebug() << "[CLIENT] Trying to connect..";

    socket->connectToHost(hostname, port);

    if (!socket->waitForConnected(15000)) {
        qDebug() << "[CLIENT] Could not connect";
        return false;
    }

    qDebug() << "[CLIENT] Connected!";

    QByteArray asd;
    asd.append(nick);
    socket->write(asd);
    socket->flush();
    return true;
}

void Client::sendData(QByteArray data)
{
    socket->write(data);
    socket->flush();
}

void Client::disconnectServer()
{
    socket->disconnectFromHost();
}

void Client::readyRead()
{
    QByteArray data = socket->readAll();
    controller_->newData(data);
}
