#include "servereventhandler.h"


std::shared_ptr<Player> ServerEventHandler::newPlayer(QString nick)
{
    ColorPallet color = availableColors.back();
    availableColors.pop_back();
    PlayerID id = 1;
    bool finished = false;

    while (!finished) {
        finished = true;
        for (auto player : playerList) {
            if (player->getID() == id) {
                id ++;
                finished = false;
                break;
            }
        }
    }
    std::shared_ptr<Player> player = std::make_shared<Player>(nick);
    player->setID(id);
    player->setColor(color);

    playerList.push_back(player);

    return player;
}

void ServerEventHandler::playerLeft(std::shared_ptr<Player> player)
{
    int i = 0;
    for (auto p : playerList) {
        if (p->getID() == player->getID()) {
            availableColors.push_back(player->getColor());
            playerList.erase(playerList.begin() + i);
            break;
        }
        i++;
    }
}

void ServerEventHandler::initialize()
{
    playerList = {};
    availableColors = {ColorPallet::black,
                       ColorPallet::yellow,
                       ColorPallet::pink,
                       ColorPallet::blue,
                       ColorPallet::green,
                       ColorPallet::red};
}

void ServerEventHandler::clear()
{
    availableColors = {ColorPallet::black,
                        ColorPallet::yellow,
                        ColorPallet::pink,
                        ColorPallet::blue,
                        ColorPallet::green,
                        ColorPallet::red};
    turnNumber = -1;
    playerList.clear();
    needToCheck = false;
}

void ServerEventHandler::newServerData(QByteArray data)
{
    QDataStream stream(&data, QIODevice::ReadOnly);

    DataType type;

    stream >> type;

    switch (type) {
    case DataType::StartGame: {
        riverPhase_ = tileDB_->getRiverPhase();
        mainPhase_ = tileDB_->getMainPhase();
        riverPhaseBool = true;
        srand(time(NULL));
        newTurn();
        break;
    }
    case DataType::EndTurn: {
        if (mainPhase_.size() == 0) {
            std::vector<std::pair<PlayerID, int>> sb;
            tilehndlr_.calculateFinalPoints(sb);

            QByteArray data;
            data = encoder_->encodePoints(sb);

            emit newData(data);
        } else {
            newTurn();
        }
        break;
    }

    case DataType::TilePlaced: {
        stream >> mostRecentTile;
        needToCheck = true;
        break;
    }
    default: {
        break;
    }
    }
}

void ServerEventHandler::newTurn()
{
    newTurnNumber();
    std::shared_ptr<Player> inTurn = playerList.at(turnNumber);
    GameTile newTile;
    std::vector<QPoint> figuresToRemove = {};
    std::vector<std::pair<PlayerID, int>> scoreBoardupdate = {};

    QByteArray data;

    // Raffling new tile
    if (riverPhaseBool) {
        auto startPiece = riverPhase_.find(tileDB_->getTile(1));
        int n = startPiece.value();
        if (n == 2) {
            newTile = startPiece.key();
            startPiece.value() -= 1;
        } else {
            newTile = raffleNewTile();
        }
    } else {
        auto startPiece = mainPhase_.find(tileDB_->getTile(30));
        int n = startPiece.value();
        if (n == 4) {
            newTile = startPiece.key();
            startPiece.value() -= 1;
        } else {
            newTile = raffleNewTile();
        }
    }

    // Getting possible figures to remove from game
    // Getting possible scoreboardupdates

    if (needToCheck) {
        tilehndlr_.checkReadyness(mostRecentTile, figuresToRemove, scoreBoardupdate);
        needToCheck = false;
    }

    data = encoder_->encodeNewTurnData(inTurn, newTile, figuresToRemove, scoreBoardupdate);
    emit newData(data);
}

GameTile ServerEventHandler::raffleNewTile()
{
    GameTile nextPiece;
    int randNum;
    while(true) {
        if (riverPhaseBool) {
            randNum = 1 + (rand() % 9);
            if(randNum == 1 && riverPhase_.size() != 1) { continue; }
            auto tile = riverPhase_.find(tileDB_->getTile(randNum));
            if (tile == riverPhase_.end()) {continue;}
            nextPiece = tile.key();
            tile.value() -= 1;
            if (tile.value() == 0) { riverPhase_.erase(tile); }

            if (riverPhase_.size() == 0) {riverPhaseBool = false;}

        } else {
            randNum = 10 + (rand() % 24);
            auto tile = mainPhase_.find(tileDB_->getTile(randNum));
            if (tile == mainPhase_.end()) {continue;}
            nextPiece = tile.key();
            tile.value() -= 1;
            if (tile.value() == 0) { mainPhase_.erase(tile); }
        }
        return nextPiece;
    }
}

void ServerEventHandler::newTurnNumber()
{
    turnNumber++;
    if (turnNumber == int(playerList.size())) {
        turnNumber = 0;
    }
}
