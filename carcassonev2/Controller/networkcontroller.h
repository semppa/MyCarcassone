#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QDataStream>
#include <Misc/player.h>
#include <Misc/DataEnums.h>
#include <QByteArray>
#include <Networking/datadecoder.h>
#include <Networking/dataencoder.h>
#include <Controller/datacontroller.h>
#include <QObject>
#include "Networking/client.h"
#include "Networking/server.h"
#include "Game/tileeventhandler.h"

class Client;
class Server;

class NetWorkController : public QObject
{
    Q_OBJECT
public:
    NetWorkController();

    void newData(QByteArray &data);

    void sendMessage(QString sender, QString message);

    void createServer(QString nick);
    bool joinServer(QString ip, qint16 port, QString nick);
    void leaveServer();
    void startGame();
    void tilePlaced(std::shared_ptr<Tile> tile);
    void figurePlaced(std::shared_ptr<Figure> figure);
    void endTurn();

    // void clear();

signals:
    void sendData(QByteArray data);

    void newMessage(QString msg);
    void newPlayer(QString nick);
    void playerDisconnected(QString nick);
    void closeServerWindow();
    void openGameWindow();
    void changeInTurnLabel(PlayerID id);
    void placeTile(std::shared_ptr<Tile> tile);
    void placeFigure(std::shared_ptr<Figure> figure);
    void tileToBePlaced(GameTile tile);
    void removeFigure(std::shared_ptr<Figure> fig);
    void updateScoreBoard();
    void endGame();

    void disconnect();


private:
    std::shared_ptr<DataDecoder> decoder_;
    std::shared_ptr<DataEncoder> encoder_;

    DataController& datactrl_ = DataController::getInstance();
    TileEventHandler& tilehndlr = TileEventHandler::getInstance();

    std::shared_ptr<TileDatabase> tileDB_;

    Server* serv_ = nullptr;
    Client* client_ = nullptr;
};

#endif // NETWORKCONTROLLER_H
