#include "datacontroller.h"

void DataController::addPeer(std::shared_ptr<Player> player)
{
    peers_.push_back(player);
}

void DataController::removePeer(std::shared_ptr<Player> player)
{
    int i = 0;
    for (auto p : peers_) {
        if (p->getID() == player->getID()) {
            peers_.erase(peers_.begin() + i);
            break;
        }
        i ++;
    }
}

std::shared_ptr<Player> DataController::getPlayerPTR(PlayerID id)
{
    if (id == player_->getID()) {
        return player_;
    }

    for(auto peer : peers_) {
        if (peer->getID() == id) {
            return peer;
        }
    }
    return nullptr;
}

void DataController::setCurTile(GameTile tile)
{
    curTile_ = tile;
}


void DataController::clear()
{
    peers_ = {};
    inTurn_ = -1;

}

