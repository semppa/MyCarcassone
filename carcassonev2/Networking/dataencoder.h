#ifndef DATAENCODER_H
#define DATAENCODER_H

#include <Misc/player.h>
#include <Game/tile.h>
#include <QByteArray>
#include <QDataStream>

class DataEncoder
{
public:
    DataEncoder();

    QByteArray encodePlayerData(std::shared_ptr<Player> player, DataType protocallEnum);

    QByteArray encodeTileData(std::shared_ptr<Tile> tile, DataType protocallEnum);

    QByteArray encodeNewTurnData(std::shared_ptr<Player> inTurn, GameTile tile,
                                 std::vector<QPoint> figuresToRemove, std::vector<std::pair<PlayerID, int>> scoreBoardUpdates);

    QByteArray encodePoints(std::vector<std::pair<PlayerID, int>> scoreBoardUpdates);

    void setTileDB(std::shared_ptr<TileDatabase> t) {tileDB_ = t;}

private:
    std::shared_ptr<TileDatabase> tileDB_;
};

#endif // DATAENCODER_H
