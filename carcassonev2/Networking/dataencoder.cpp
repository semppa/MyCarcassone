#include "dataencoder.h"

DataEncoder::DataEncoder()
{
}

QByteArray DataEncoder::encodePlayerData(std::shared_ptr<Player> player, DataType protocallEnum)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    stream << protocallEnum;
    stream << player->getID();
    stream << player->getNick();
    stream << player->getColor();

    return data;
}

QByteArray DataEncoder::encodeTileData(std::shared_ptr<Tile> tile, DataType protocallEnum)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    stream << protocallEnum;
    stream << tile->getCoordinates();
    stream << tile->getRotationNum();
    stream << tileDB_->getID(tile->getTileData());

    return data;
}

QByteArray DataEncoder::encodeNewTurnData(std::shared_ptr<Player> inTurn, GameTile tile,
                                          std::vector<QPoint> figuresToRemove, std::vector<std::pair<PlayerID, int>> scoreBoardUpdates)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    stream << DataType::NewTurn;
    stream << inTurn->getID();
    stream << inTurn->getNick();
    stream << inTurn->getColor();
    stream << tileDB_->getID(tile);

    stream << int(figuresToRemove.size());
    for (auto figcoords : figuresToRemove) {
        stream << figcoords;
    }

    stream << int(scoreBoardUpdates.size());
    for (auto data : scoreBoardUpdates) {
        stream << data.first;
        stream << data.second;
    }

    return data;
}

QByteArray DataEncoder::encodePoints(std::vector<std::pair<PlayerID, int> > scoreBoardUpdates)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    stream << EndGame;
    stream << int(scoreBoardUpdates.size());
    for (auto data : scoreBoardUpdates) {
        stream << data.first;
        stream << data.second;
    }

    return data;
}
