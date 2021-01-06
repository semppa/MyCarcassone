#ifndef TILEDATABASE_H
#define TILEDATABASE_H

#include <QMap>
#include <QString>
#include <vector>

using TileID = int;
enum LandTypes { river, road, field, castle, monastery};

struct TilePosition {
    qreal xoffset;
    qreal yoffset;
    LandTypes type;
    std::pair<int,int> posInIndVec;
};

struct GameTile {
    TileID id_;
    std::vector<LandTypes> typeVec;
    std::vector<std::vector<int>> typeIndexes;
    QString sprite;
    bool monastery = false;
    bool sign = false;

    GameTile() {
        id_ = -1;
        typeVec = {};
        typeIndexes = {};
        sprite = "";
    }

    GameTile(TileID id, std::vector<LandTypes> types,  std::vector<std::vector<int>> indx, QString sprites_, bool monastery_ = false, bool sign_ = false) {
        id_ = id;
        typeVec = types;
        typeIndexes = indx;
        sprite = sprites_;
        monastery = monastery_;
        sign = sign_;
    }

    bool operator==(const GameTile &other) {
        return id_ == other.id_;
    }

    bool operator<(const GameTile& rhs) const {
        return id_ < rhs.id_;
    }
};


inline const QString fromLandTypeToQString(LandTypes t) {
    switch (t) {
        case river:     return QString("river");
        case road:      return QString("road");
        case field:     return QString("field");
        case castle:    return QString("castle");
        case monastery: return QString("monastery");
    default:            return QString("");
    }
}

class TileDatabase
{

public:
    TileDatabase();

    GameTile getTile(TileID id);
    TileID getID(GameTile tile);

    QMap<GameTile, int> getRiverPhase() {return riverPhase_;}
    QMap<GameTile, int> getMainPhase() {return mainPhase_;}

    std::vector<TilePosition> getTilePositions(TileID tileID);

private:
    QMap<TileID, GameTile> allTilesByID_;

    QMap<GameTile, int> riverPhase_;
    QMap<GameTile, int> mainPhase_;

    const TileID ERROR_ID = -1;
    const GameTile ERROR_TILE = {ERROR_ID, {}, {}, ""};
};

#endif // TILEDATABASE_H
