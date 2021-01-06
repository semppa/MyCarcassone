#ifndef TILE_H
#define TILE_H

#include <QString>
#include <QPoint>
#include "Game/tiledatabase.h"
#include "Game/figure.h"
#include <memory>
#include <QDebug>
#include "unordered_set"

class Figure;

class Tile
{
public:
    Tile(QPoint coordinates, GameTile tile, int rotateN);

    QPoint getCoordinates() {return coordinates_;}
    std::vector<LandTypes> getTypeVect() {return typeVect_;}
    std::vector<std::vector<int>> getTypeIndVect() {return typeVectIndexes_;}
    QString getSprite() {return tileData_.sprite;}
    int getRotationNum() {return rotateN_;}
    bool getMonastery() {return tileData_.monastery;}

    GameTile getTileData() {return tileData_;}

    void setFig(std::shared_ptr<Figure> fig) {fig_ = fig;}
    std::shared_ptr<Figure> getFig() {return fig_;}

    void changeTypeIndexes(int from, int to);

    void rotateTile();
    void updateCoords(QPoint newCoords) {coordinates_ = newCoords;}

    std::vector<TilePosition> getPossibleFigurePos();


private:
    int rotateN_;
    GameTile tileData_;
    std::vector<LandTypes> typeVect_;
    std::vector<std::vector<int>> typeVectIndexes_;
    QPoint coordinates_;
    std::shared_ptr<Figure> fig_;
};

#endif // TILE_H
