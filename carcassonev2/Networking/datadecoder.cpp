#include "datadecoder.h"

DataDecoder::DataDecoder()
{
}

std::shared_ptr<Player> DataDecoder::decodePlayerInformation(QDataStream &stream)
{
    //QDataStream stream(&data, QIODevice::ReadOnly);
    // DataType type;

    QString nick;
    ColorPallet color;
    PlayerID id;

    stream >> id >> nick >> color;

    std::shared_ptr<Player> tmp = std::make_shared<Player>(nick);
    tmp->setID(id);
    tmp->setColor(color);

    return tmp;
}

std::shared_ptr<Tile> DataDecoder::decodeTileInfo(QDataStream &stream)
{
    QPoint coordinates;
    int rotationN;
    TileID id;

    stream >> coordinates >> rotationN >> id;

    GameTile tileData = tileDB_->getTile(id);

    std::shared_ptr<Tile> tmp = std::make_shared<Tile>(coordinates, tileData, 0);
    for (auto i = 0; i < rotationN; i++) { tmp->rotateTile();}
    return tmp;
}
