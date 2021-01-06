#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <Misc/player.h>
#include <Game/tile.h>
#include <QObject>
#include <QDebug>
#include "Graphics/figuregraphicsitem.h"

class FigureGraphicsItem;

class DataController : public QObject
{
    Q_OBJECT
public:
    static DataController& getInstance() {
        static DataController instance;
        return instance;
    }

    std::shared_ptr<Player> getPlayerPTR() {return player_;}
    void setPlayerPTR(std::shared_ptr<Player> p) {player_ = p;}

    void addPeer(std::shared_ptr<Player> player);
    void removePeer(std::shared_ptr<Player> player);
    std::vector<std::shared_ptr<Player>> getPeers() {return peers_;};
    std::shared_ptr<Player> getPlayerPTR(PlayerID id);

    void setInTurn(PlayerID id) {inTurn_ = id;}
    bool myTurn() {return inTurn_ == player_->getID();}

    void setCurTile(GameTile tile);
    GameTile getCurTile() {return curTile_;}

    void clear();

private:
    DataController() {};
    void operator=(DataController const &t);

    std::shared_ptr<Player> player_;
    std::vector<std::shared_ptr<Player>> peers_;

    PlayerID inTurn_;
    GameTile curTile_;

};

#endif // DATACONTROLLER_H
