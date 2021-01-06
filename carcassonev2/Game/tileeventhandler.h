#ifndef TILEEVENTHANDLER_H
#define TILEEVENTHANDLER_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Game/tile.h"
#include <QHash>
#include <QDebug>

struct TileNode {  // A node to make search algorithms easier/faster
    std::shared_ptr<Tile> node_;
    std::vector<TileNode*> neighbours_;
};

// Hash function to make qpoint possible being a key in QHash container (unordered map)
inline uint qHash (const QPoint & key)
{
    return qHash (QPair<int,int>(key.x(), key.y()) );
}

class TileEventHandler
{
public:
    static TileEventHandler& getInstance() {
        static TileEventHandler instance;
        return instance;
    }

    bool tileFits(std::shared_ptr<Tile> refTile);
    void tilePlaced(std::shared_ptr<Tile> tile);;

    void checkReadyness(QPoint fromTileCoords, std::vector<QPoint> &figsToRemove, std::vector<std::pair<PlayerID, int>> &sb);

    bool figureSpaceOccupied(std::shared_ptr<Figure> figure);
    std::shared_ptr<Tile> getTileFromCoords(QPoint coords);

    void calculateFinalPoints(std::vector<std::pair<PlayerID, int>> &sb);

    void addFigureToDB(std::shared_ptr<Figure> fig);
    void removeFigFromDB(std::shared_ptr<Figure> fig);

    void debug();
    void clear();

private:
    TileEventHandler() {};
    void operator=(const TileEventHandler&);

    // Containers
    std::unordered_set<TileNode*> placedTiles_;
    std::unordered_map<std::shared_ptr<Tile>, TileNode*> uTileMap_;
    QHash<QPoint, std::shared_ptr<Tile>> tileByCoordDB;
    std::vector<std::vector<std::pair<TileNode*, int>>> readyCastles;
    std::unordered_map<int, std::vector<std::shared_ptr<Figure>>> figuresOnLand;

    // Private functions
    std::vector<std::shared_ptr<Tile>> getNeighbours(std::shared_ptr<Tile> ref);
    std::unordered_set<TileNode*> checkReadinessRecursive(TileNode* cur, std::unordered_set<TileNode*> checked, LandTypes type, int last);
    // void figuresOnPath(TileNode* cur, std::unordered_set<TileNode*> checked, std::pair<int,int> last, std::unordered_set<std::shared_ptr<Figure>> &figures);
    void checkMonasteryReadiness(TileNode* from, std::vector<QPoint> &figsToRemove, std::vector<std::pair<PlayerID, int>> &sb, bool cont);
    void changeFieldIndexes(TileNode* cur);
    void mergeLands(TileNode* cur, int from, int to);
    void getFirstLandInd(TileNode* node, int castleIndex, std::unordered_set<int> &inds);
    int getCastleIndexForTile(TileNode* node, std::unordered_set<TileNode*> castlePieces);
    void changeDBKey(int from, int to);
    void giveUniqueTileIndexes(TileNode* node);

    // Variables
    TileNode* FINISHED = new TileNode;
    TileNode* NOTFINISHED = new TileNode;

    int uniqueLandIndex = 10;
};

#endif // TILEEVENTHANDLER_H
