#ifndef SERVEREVENTHANDLER_H
#define SERVEREVENTHANDLER_H
#include "Misc/player.h"
#include "vector"
#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include "time.h"
#include "Networking/dataencoder.h"
#include "Controller/datacontroller.h"
#include "Game/tileeventhandler.h"

class ServerEventHandler : public QObject
{
    Q_OBJECT
public:
    static ServerEventHandler& getInstance() {
        static ServerEventHandler instance;
        return instance;
    }

    std::shared_ptr<Player> newPlayer(QString nick);
    void playerLeft(std::shared_ptr<Player> player);
    void initialize();

    void clear();

    void newServerData(QByteArray data);
    void setTileDB(std::shared_ptr<TileDatabase> tdb) {tileDB_ = tdb;}
    void setEncoder(std::shared_ptr<DataEncoder> encoder) {encoder_ = encoder;}

signals:
    void newData(QByteArray data);

private:
    ServerEventHandler() {};
    void operator=(ServerEventHandler const&);

    std::vector<std::shared_ptr<Player>> playerList;
    int turnNumber = -1;
    void newTurnNumber();
    void newTurn();
    GameTile raffleNewTile();

    QMap<GameTile, int> riverPhase_;
    QMap<GameTile, int> mainPhase_;
    bool riverPhaseBool;

    std::vector<ColorPallet> availableColors = {ColorPallet::black,
                                                ColorPallet::yellow,
                                                ColorPallet::pink,
                                                ColorPallet::blue,
                                                ColorPallet::green,
                                                ColorPallet::red};

    std::shared_ptr<DataEncoder> encoder_;
    std::shared_ptr<TileDatabase> tileDB_;

    QPoint mostRecentTile;

    bool needToCheck = false;       // Flag that tells if new tile was placed and readiness needs to
                                    // be checked (toggled on at onTilePlaced and off after each check)

    TileEventHandler &tilehndlr_ = TileEventHandler::getInstance();

};

#endif // SERVEREVENTHANDLER_H
