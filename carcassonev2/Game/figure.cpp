#include "figure.h"

Figure::Figure(std::shared_ptr<Tile> onTile, TilePosition pos, QString sprite) : onTile_(onTile), pos_(pos), sprite_(sprite)
{
}

LandTypes Figure::getLandtype()
{
    return pos_.type;
}

