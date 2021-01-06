#ifndef FIGURE_H
#define FIGURE_H

#include <QString>
#include "Game/tile.h"
#include "Misc/player.h"
#include <QPoint>
#include <memory>

class Tile;

class Figure
{
public:
    Figure(std::shared_ptr<Tile> onTile, TilePosition pos, QString sprite);

    LandTypes getLandtype();

    TilePosition getPos() {return pos_;}
    std::shared_ptr<Tile> getTile() {return onTile_;}
    QString getSprite() {return sprite_;}

    void setOwner(PlayerID id) {owner_ = id;}
    PlayerID getOwner() {return owner_;}

private:
    std::shared_ptr<Tile> onTile_;
    TilePosition pos_;
    PlayerID owner_;

    QString sprite_;
};

#endif // FIGURE_H
