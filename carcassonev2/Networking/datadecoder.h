#ifndef DATADECODER_H
#define DATADECODER_H

#include <QByteArray>
#include <QDataStream>
#include <Misc/player.h>
#include <Game/tile.h>

class DataDecoder
{
public:
    DataDecoder();

    std::shared_ptr<Player> decodePlayerInformation(QDataStream &stream);

    std::shared_ptr<Tile> decodeTileInfo(QDataStream &stream);

    void setTileDB(std::shared_ptr<TileDatabase> t) {tileDB_ = t;}

private:
    std::shared_ptr<TileDatabase> tileDB_;
};

#endif // DATADECODER_H
