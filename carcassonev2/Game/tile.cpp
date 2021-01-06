#include "tile.h"

Tile::Tile(QPoint coordinates, GameTile tile, int rotateN) :
   rotateN_(rotateN), tileData_(tile), typeVect_(tile.typeVec), typeVectIndexes_(tile.typeIndexes), coordinates_(coordinates)
{
}

void Tile::changeTypeIndexes(int from, int to)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (typeVectIndexes_[i][j] == from) {
                typeVectIndexes_[i][j] = to;
            }
        }
    }
}

void Tile::rotateTile()
{
    std::vector<LandTypes> tmp = {typeVect_[3], typeVect_[0], typeVect_[1], typeVect_[2]};
    typeVect_ = tmp;

    std::vector<std::vector<int>> tmp2 = {typeVectIndexes_[3], typeVectIndexes_[0], typeVectIndexes_[1], typeVectIndexes_[2]};
    typeVectIndexes_ = tmp2;

    rotateN_ = (rotateN_ + 1) % 4;
}

std::vector<TilePosition> Tile::getPossibleFigurePos()
{
    // HUOM NYT JOKAINEN TIILILAATTA TEKEE UUDEN TILEDATABASEN TÄTÄ OPERAATIOTA VARTEN
    // MIETI OPTIMAALISEMPAA RATKAISUA

    TileDatabase* tb = new TileDatabase;
    std::vector<TilePosition> tilepos = tb->getTilePositions(tileData_.id_);
    std::vector<TilePosition> retVect = {};

    qreal xtmp, ytmp, temp;

    for (auto item : tilepos) {
        xtmp = item.xoffset;
        ytmp = item.yoffset;
        int posIndFirst = item.posInIndVec.first;
        for (int i = 0; i < rotateN_; i++) {
            // Translating origin to center (0.5, 0.5)
            xtmp = xtmp - 0.5;
            ytmp = ytmp - 0.5;

            // Rotating around origin and translating origin back to top left corner
            temp = xtmp;
            xtmp = -ytmp + 0.25; // +0.5 for translation and -0.25 to make this point top left corner
            ytmp = temp + 0.5;

            posIndFirst = (posIndFirst + 1) % 4;
        }
        TilePosition tmp = {xtmp, ytmp, item.type, {posIndFirst, item.posInIndVec.second}};
        retVect.push_back(tmp);
    }

    delete tb;
    tb = nullptr;
    return retVect;
}
