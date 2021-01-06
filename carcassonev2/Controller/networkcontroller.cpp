#include "networkcontroller.h"

NetWorkController::NetWorkController()
{
    decoder_ = std::make_shared<DataDecoder>();
    encoder_ = std::make_shared<DataEncoder>();
    tileDB_ = std::make_shared<TileDatabase>();

    decoder_->setTileDB(tileDB_);
    encoder_->setTileDB(tileDB_);
}

void NetWorkController::newData(QByteArray &data)
{
    QDataStream stream(data);

    DataType type;

    bool dataArrayEmpty = false;
    int a = 0; // To prevent infinite loops

    while (!dataArrayEmpty && a < 25) {
        stream >> type;
        switch (type) {
        case DataType::Chat: {
            QString nick;
            QString msg;
            stream >> nick >> msg;
            QString message = nick + ": " + msg;
            emit newMessage(message);
            break;
        }
        case DataType::IConnected: {
            std::shared_ptr<Player> new_player = decoder_->decodePlayerInformation(stream);
            datactrl_.setPlayerPTR(new_player);
            emit newPlayer(new_player->getNick());
            break;
        }

        case DataType::NewUserConnected: {
            std::shared_ptr<Player> new_player = decoder_->decodePlayerInformation(stream);
            datactrl_.addPeer(new_player);
            emit newPlayer(new_player->getNick());
            break;
        }

        case DataType::UserDisconnected: {
            std::shared_ptr<Player> disc_player = decoder_->decodePlayerInformation(stream);
            datactrl_.removePeer(disc_player);
            emit playerDisconnected(disc_player->getNick());
            break;
        }

        case DataType::ServerClosed: {
            emit closeServerWindow();
            break;
        }


        case DataType::StartGame: {
            emit openGameWindow();
            break;
        }

        case DataType::NewTurn: {
            PlayerID pId; QString nick; ColorPallet color; TileID tID;
            stream >> pId >> nick >> color >> tID;
            GameTile tile = tileDB_->getTile(tID);

            datactrl_.setInTurn(pId);
            datactrl_.setCurTile(tile);

            emit changeInTurnLabel(pId);
            emit tileToBePlaced(tile);

            int nFiguresToRemove, scoreboardupdates;

            stream >> nFiguresToRemove;

            QPoint figCoords;
            for (int i = 0; i < nFiguresToRemove; i++) {
                stream >> figCoords;
                std::shared_ptr<Tile> tile = tilehndlr.getTileFromCoords(figCoords);
                std::shared_ptr<Figure> fig = tile->getFig();
                tile->setFig(nullptr);

                emit removeFigure(fig);
                datactrl_.getPlayerPTR(fig->getOwner())->modifyFigureCount(1); // Adding the figure back to player
                tilehndlr.removeFigFromDB(fig);
            }

            stream >> scoreboardupdates;

            PlayerID player; int update;
            for (int i = 0; i < scoreboardupdates; i++) {
                stream >> player >> update;
                std::shared_ptr<Player> playerPTR = datactrl_.getPlayerPTR(player);
                playerPTR->increasePoint(update);
            }

            emit updateScoreBoard();
            break;
        }

        case DataType::TilePlaced: {
            std::shared_ptr<Tile> placedTile = decoder_->decodeTileInfo(stream);

            // Tile is not in database already
            if (tilehndlr.getTileFromCoords(placedTile->getCoordinates()) == nullptr) {
                tilehndlr.tilePlaced(placedTile);
            }
            emit placeTile(placedTile);
            break;
        }

        case DataType::FigurePlaced: {
            QPoint tileCoords; QString sprite; qreal xoff, yoff; int posIndFirst, posIndSec; LandTypes landtype; PlayerID ownerID;

            stream >> tileCoords >> xoff >> yoff >> landtype >> posIndFirst >> posIndSec >> sprite >> ownerID;

            std::shared_ptr<Tile> onTile = tilehndlr.getTileFromCoords(tileCoords);
            TilePosition pos = {xoff, yoff, landtype, {posIndFirst, posIndSec}};
            std::shared_ptr<Figure> newFig = std::make_shared<Figure>(onTile, pos, sprite);
            newFig->setOwner(ownerID);
            onTile->setFig(newFig);

            datactrl_.getPlayerPTR(ownerID)->modifyFigureCount(-1);
            tilehndlr.addFigureToDB(newFig);

            emit updateScoreBoard();
            emit placeFigure(newFig);
            break;
        }
        case DataType::EndTurn: {
            break;
        }

        case DataType::EndGame: {
            int nSBUpdates;

            stream >> nSBUpdates;

            PlayerID player; int update;
            for (int i = 0; i < nSBUpdates; i++) {
                stream >> player >> update;
                std::shared_ptr<Player> playerPTR = datactrl_.getPlayerPTR(player);
                playerPTR->increasePoint(update);
            }

            emit endGame();
        }

        } // Switch case
        if(stream.atEnd()) {
            dataArrayEmpty = true;
        }

        a++;
    }
}

void NetWorkController::sendMessage(QString sender, QString message) {
    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);
    s << DataType::Chat << sender << message;

    emit sendData(data);
}

void NetWorkController::createServer(QString nick)
{
    if (serv_ != nullptr) {
        delete serv_;
        serv_ = nullptr;
    }
    serv_ = new Server(this);
    serv_->start(nick);
    connect(this, SIGNAL(disconnect()), serv_, SLOT(closeServer()));
    connect(this, SIGNAL(sendData(QByteArray)), serv_, SLOT(echoData(QByteArray)));
}

bool NetWorkController::joinServer(QString ip, qint16 port, QString nick)
{
    if(client_ != nullptr) {
        delete client_;
        client_ = nullptr;
    }
    client_ = new Client(this);

    connect(this, SIGNAL(sendData(QByteArray)), client_, SLOT(sendData(QByteArray)));
    connect(this, SIGNAL(disconnect()), client_, SLOT(disconnectServer()));
    return client_->connect(ip, port, nick);
}

void NetWorkController::leaveServer()
{
    emit disconnect();
}

void NetWorkController::startGame()
{
    QByteArray data;
    QDataStream s(&data, QIODevice::ReadWrite);

    s << DataType::StartGame;
    emit sendData(data);
}

void NetWorkController::tilePlaced(std::shared_ptr<Tile> tile)
{
    QByteArray data;
    data = encoder_->encodeTileData(tile, DataType::TilePlaced);
    emit sendData(data);
}

void NetWorkController::figurePlaced(std::shared_ptr<Figure> figure)
{
    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);

    s << DataType::FigurePlaced;
    s << figure->getTile()->getCoordinates();
    s << figure->getPos().xoffset;
    s << figure->getPos().yoffset;
    s << figure->getPos().type;
    s << figure->getPos().posInIndVec.first;
    s << figure->getPos().posInIndVec.second;
    s << figure->getSprite();
    s << datactrl_.getPlayerPTR()->getID();

    emit sendData(data);
}

void NetWorkController::endTurn()
{
    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);

    s << DataType::EndTurn;

    emit sendData(data);
}
/*
void NetWorkController::clear()
{
    if (client_ != nullptr) {
        client_->disconnect();
        delete client_;
        client_ = nullptr;
    }

    if (serv_ != nullptr) {
        serv_->closeServer();
        delete serv_;
        serv_ = nullptr;
    }
}
*/
