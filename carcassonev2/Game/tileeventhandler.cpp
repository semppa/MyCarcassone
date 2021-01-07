#include "tileeventhandler.h"
#include <string>

bool TileEventHandler::tileFits(std::shared_ptr<Tile> refTile)
{
    if(placedTiles_.size() == 0) {return true;}

    std::vector<std::shared_ptr<Tile>> neighbours = getNeighbours(refTile);

    if (!neighbours[0] && !neighbours[1] && !neighbours[2] && !neighbours[3]) {
        return false;
    }

    bool riverPhase = false;
    bool riverOK = false;
    std::vector<LandTypes> typevec = refTile->getTypeVect();
    for(auto value : typevec) {if (value == river) {riverPhase = true; break;}}

    for(int i = 0; i < 4; i++) {
        if (neighbours[i] != nullptr) {
            if (neighbours[i]->getTypeVect()[(i + 2) % 4] != typevec[i]) {return false;}
            if (typevec[i] == river) { riverOK = true;}
        }
    }

    if ((riverPhase && riverOK) || !riverPhase) {
        return true;
    }

    return false;
}

void TileEventHandler::tilePlaced(std::shared_ptr<Tile> tile) {
    TileNode* n = new TileNode;
    n->node_ = tile;

    auto neighbourVect = getNeighbours(tile);
    std::vector<TileNode*> tmp = {nullptr, nullptr, nullptr, nullptr};
    for (int i = 0; i < 4; i++) {
        if (neighbourVect[i] != nullptr) {
            // Making tile next a neighbour
            tmp[i] = uTileMap_.find(neighbourVect[i])->second;

            // Making myself a neighbour to next tile
            uTileMap_.find(neighbourVect[i])->second->neighbours_[(2 + i) % 4] = n;
        }
    }
    n->neighbours_ = tmp;

    // By default any tile has fields indexed seperately, but because in game the fields might combine
    // these indexes needs to be changed.
    giveUniqueTileIndexes(n);
    changeFieldIndexes(n);

    placedTiles_.insert(n);
    uTileMap_[tile] = n;
    tileByCoordDB.insert(tile->getCoordinates(), tile);
}

void TileEventHandler::checkReadyness(QPoint fromTileCoords, std::vector<QPoint> &figsToRemove, std::vector<std::pair<PlayerID, int>> &sb)
{
    std::shared_ptr<Tile> fromTile = getTileFromCoords(fromTileCoords);
    std::vector<LandTypes> typevec = fromTile->getTypeVect();
    TileNode* refNode = uTileMap_.find(fromTile)->second;

    checkMonasteryReadiness(refNode, figsToRemove, sb, true);

    std::unordered_set<TileNode*> accumulator = {FINISHED};

    for (int i = 0; i < 4; i++) {
        LandTypes refType = typevec[i];
        if (refType == river || refType == field) {continue;}

        bool unique = true;
        for (int j = i - 1; j > -1; j--) {
            if(fromTile->getTypeIndVect()[j][1] == fromTile->getTypeIndVect()[i][1]) { unique = false;}
        }
        if (!unique) { continue; }

        auto vect = checkReadinessRecursive(refNode, accumulator, refType, i);
        if (vect.find(NOTFINISHED) != vect.end()) { continue;}

        // Whatever we checked just got finished. Now time to awards player that have figures on tiles (road or castle)
        vect.erase(FINISHED);

        // Adding finished castle to database, so it can be used to calculate points after game
        if (refType == castle) {
            std::vector<std::pair<TileNode*, int>> tmp;
            for(auto piece : vect) {
                tmp.push_back({piece, getCastleIndexForTile(piece, vect)});
            }
            readyCastles.push_back(tmp);
        }

        // Getting figures that are on finished product
        int landIndex = refNode->node_->getTypeIndVect()[i][1];
        auto figuresitem = figuresOnLand.find(landIndex);

        if (figuresitem == figuresOnLand.end()) { continue;} // Even though something did finish, there are no figures and nobody gets points


        // Calculating points for finished product
        int typefactor = 1;
        if (refType == castle && int(vect.size()) != 2) {
            typefactor = 2;
        }
        int points = 0;
        for (auto tile : vect) {
            points += typefactor;
            if (refType == castle && tile->node_->getTileData().sign) {
                points += typefactor;
            }
        }

        // Calculating number of figures owned by player to QMap
        QMap<PlayerID, int> nFigsTmp;
        for(auto figure : figuresitem->second) {
            figsToRemove.push_back(figure->getTile()->getCoordinates());
            if (nFigsTmp.find(figure->getOwner()) != nFigsTmp.end()) {
                nFigsTmp[figure->getOwner()] += 1;
            } else {
                nFigsTmp[figure->getOwner()] = 1;
            }
        }

        // Calculating who has most figures and placing them to winners container
        int max = -1;
        std::vector<PlayerID> winners;
        for (auto key : nFigsTmp.keys()) {

            if (nFigsTmp[key] == max) {
                winners.push_back(key);
            }
            if(nFigsTmp[key] > max) {
                winners = {key};
                max = nFigsTmp[key];
            }
        }

        // Awarding winners
        for (auto winner : winners) {
            sb.push_back({winner, points});
        }

        // Now this side is finished so its time to move on to next side ->

    } // For loop of tile sides
}

bool TileEventHandler::figureSpaceOccupied(std::shared_ptr<Figure> figure)
{
    /*
    TileNode* onTileNode = uTileMap_.find(figure->getTile())->second;
    std::pair<int, int> indpair = figure->getPos().posInIndVec;
    std::unordered_set<TileNode*> checked = {};
    std::unordered_set<std::shared_ptr<Figure>> figures;

    figuresOnPath(onTileNode, checked, indpair, figures);


    return figures.size() > 0;
    */

    // Monasteries are checked before this function call

    int index = figure->getTile()->getTypeIndVect()[figure->getPos().posInIndVec.first][figure->getPos().posInIndVec.second];
    if(figuresOnLand.find(index) != figuresOnLand.end()) {
        return true;
    } else {
        return false;
    }
}

std::shared_ptr<Tile> TileEventHandler::getTileFromCoords(QPoint coords)
{
    auto tile = tileByCoordDB.find(coords);
    if (tile != tileByCoordDB.end()) {
        return tile.value();
    } else {
        return nullptr;
    }
}

void TileEventHandler::calculateFinalPoints(std::vector<std::pair<PlayerID, int> > &sb)
{
    // Calculate all figures that remain on map that are on:

    // Fields
    std::unordered_set<std::shared_ptr<Figure>> figures;
    std::unordered_set<int> landIndexes;
    int castli = 0;
    for(auto castle : readyCastles) {
        figures = {};
        landIndexes = {};
        for(auto castlePiece : castle) {
            getFirstLandInd(castlePiece.first, castlePiece.second, landIndexes);
        }

        for(auto ind : landIndexes) {
            auto item = figuresOnLand.find(ind);
            if(figuresOnLand.find(ind) != figuresOnLand.end()) {
                for(auto fig : item->second) {
                    figures.insert(fig);
                }
            }
        }

        if(figures.empty()) {continue;}

        std::vector<PlayerID> figOwners;
        for(auto fig : figures) {
            figOwners.push_back(fig->getOwner());
        }
        std::sort(figOwners.begin(), figOwners.end());

        std::vector<PlayerID> winners;
        PlayerID cur = figOwners[0];
        int curAmount = 0;
        int max = 0;
        for(auto owner : figOwners) {
            if(owner != cur) {
                if (curAmount > max) {
                    winners = {owner};
                    max = curAmount;
                } else if (curAmount == max) {
                    winners.push_back(owner);
                }
                curAmount = 0;
                cur = owner;
            } else {
                curAmount++;
            }
        }
        if (curAmount > max) {
            winners = {cur};
            max = curAmount;
        } else if (curAmount == max) {
            winners.push_back(cur);
        }

        // Giving every player in "winner" vector 4 points
        for (auto winner : winners) {
            qDebug() << winner << "saa 4 pistettä maalla makoilemisesta ja linnasta" << castli;
            sb.push_back({winner, 4});
        }
        castli++;
    }

    // Rest
    for(auto figureItem : figuresOnLand) {
        if(figureItem.first == 5) {
            int points = 1;
            const std::vector<QPoint> monasteryOffsets = {{-1,-1}, {0,-1}, {1,-1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

            for (auto monFig : figureItem.second) {
                QPoint onTileCoords = monFig->getTile()->getCoordinates();
                for(auto offset : monasteryOffsets) {
                    if(getTileFromCoords(onTileCoords + offset) != nullptr) {
                        points++;
                    }
                }
                sb.push_back({monFig->getOwner(), points});
                qDebug() << monFig->getOwner() << "saa" << points << "pistettä luostarista";
                points = 1;
            }
        } else {
            std::vector<std::shared_ptr<Figure>> figVec = figureItem.second;
            if (figVec[0]->getPos().type == field) { continue; }

            std::unordered_set<TileNode*> building = checkReadinessRecursive(uTileMap_.find(figVec[0]->getTile())->second, {}, figVec[0]->getPos().type, figVec[0]->getPos().posInIndVec.first);
            building.erase(NOTFINISHED);
            int points = 0;

            for(auto tile : building) {
                points++;
                if (tile->node_->getTileData().sign && figVec[0]->getPos().type == castle) {
                    points++;
                }
            }

            std::vector<PlayerID> figOwners;
            for(auto fig : figureItem.second) {
                figOwners.push_back(fig->getOwner());
            }
            std::sort(figOwners.begin(), figOwners.end());

            std::vector<PlayerID> winners;
            PlayerID cur = figOwners[0];
            int curAmount = 0;
            int max = 0;
            for(auto owner : figOwners) {
                if(owner != cur) {
                    if (curAmount > max) {
                        winners = {owner};
                        max = curAmount;
                    } else if (curAmount == max) {
                        winners.push_back(owner);
                    }
                    curAmount = 0;
                    cur = owner;
                } else {
                    curAmount++;
                }
            }
            if (curAmount > max) {
                winners = {cur};
                max = curAmount;
            } else if (curAmount == max) {
                winners.push_back(cur);
            }

            for(auto winner : winners) {
                sb.push_back({winner, points});
                qDebug() << winner << "saa" << points << "pistettä tyypistä " + fromLandTypeToQString(figVec[0]->getPos().type);
            }
        }
    }
}

void TileEventHandler::addFigureToDB(std::shared_ptr<Figure> fig)
{
    int ind;
    if (fig->getPos().type == monastery) {
        ind = 5; // Special index reserved for figures in monasteries
    } else {
        ind = fig->getTile()->getTypeIndVect()[fig->getPos().posInIndVec.first][fig->getPos().posInIndVec.second];
    }

    auto item = figuresOnLand.find(ind);
    if (item != figuresOnLand.end()) {
        item->second.push_back(fig);
    } else {
        figuresOnLand[ind] = {fig};
    }
}

void TileEventHandler::removeFigFromDB(std::shared_ptr<Figure> fig)
{
    int ind;
    if (fig->getPos().type == monastery) {
        ind = 5; // Special index reserved for figures in monasteries
    } else {
        ind = fig->getTile()->getTypeIndVect()[fig->getPos().posInIndVec.first][fig->getPos().posInIndVec.second];
    }

    auto item = figuresOnLand.find(ind);
    if (item != figuresOnLand.end()) {
        int i = 0;
        for(auto vecfig : item->second) {
            if(vecfig == fig) {
                item->second.erase(item->second.begin() + i);
                break;
            }
            i++;
        }
        if(item->second.empty()) {
            figuresOnLand.erase(item);
        }
    }
}

void TileEventHandler::debug()
{
    bool ok = true;
    for(auto tile : placedTiles_) {
        for(int i = 0; i < 4; i++) {
            if(tile->neighbours_[i] == nullptr) {continue;}

            for(int j = 0; j < 3; j++) {
                if(tile->node_->getTypeIndVect()[i][j] != tile->neighbours_[i]->node_->getTypeIndVect()[(i+2)%4][2-j]) {
                    ok = false;
                }
            }
        }
    }

    if (ok) {
        qDebug() << "Kaikki ok tyyppivektorien osalta :)";
    } else {
        qDebug() << "Tyyppivektorien osalta joku ei ookoo :(";
    }

    qDebug() << "----------------------- ukkelit taas menee näin -----------------------";
    for(auto item : figuresOnLand) {
        for(auto fig : item.second) {
            QPoint coords = fig->getTile()->getCoordinates();
            qDebug() << "Indeksi" << item.first << "on ukko koordinaatissa" << coords << "mikä on tyyppiä" << fromLandTypeToQString(fig->getPos().type);

        }
    }

    qDebug() << "----------------------- Näistä kun lasketaan pisteet, saadaan seuraava -----------------------";
    std::vector<std::pair<PlayerID, int>> sb;
    calculateFinalPoints(sb);

}

void TileEventHandler::clear()
{
    placedTiles_.clear();
    for (auto tile : uTileMap_) {
        if (tile.second != nullptr) {
            delete tile.second;
        }
    }
    uTileMap_.clear();
    tileByCoordDB.clear();
    for (auto castle : readyCastles) {
        for (auto tile : castle) {
            if(tile.first != nullptr) {
                delete tile.first;
            }
        }
        castle.clear();
    }
    readyCastles.clear();

    figuresOnLand.clear();

    uniqueLandIndex = 10;
}

std::vector<std::shared_ptr<Tile> > TileEventHandler::getNeighbours(std::shared_ptr<Tile> ref)
{
    QPoint refCoords = ref->getCoordinates();

    std::vector<std::shared_ptr<Tile>> returnVect = {nullptr, nullptr, nullptr, nullptr};

    for (auto tile : placedTiles_) {
        QPoint coords = tile->node_->getCoordinates();
        if(        refCoords + QPoint(0,1) == coords) {
            returnVect[0] = tile->node_;
        } else if (refCoords - QPoint(1,0) == coords) {
            returnVect[1] = tile->node_;
        } else if (refCoords - QPoint(0,1) == coords) {
            returnVect[2] = tile->node_;
        } else if (refCoords + QPoint(1,0) == coords) {
            returnVect[3] = tile->node_;
        }
    }
    return returnVect;
}

std::unordered_set<TileNode *> TileEventHandler::checkReadinessRecursive(TileNode *cur, std::unordered_set<TileNode *> checked, LandTypes type, int last)
{
    checked.insert(cur);
    int uniqIndex = cur->node_->getTypeIndVect()[last][1];

    for (int i = 0; i < 4; i++) {
        if(cur->neighbours_[i] == nullptr && cur->node_->getTypeVect()[i] == type && cur->node_->getTypeIndVect()[i][1] == uniqIndex) {
            checked.erase(FINISHED);
            checked.insert(NOTFINISHED);
        }
        // If there is no neighbour in this direction, no need to continue there
        if(cur->neighbours_[i] == nullptr) {continue; }

        // If neighbour is already checked, then no need to continue there
        if(checked.find(cur->neighbours_[i]) != checked.end()) {continue; }

        // If the type of tile isnt correct (i.e. tile has 2 castle ends but are different castle)
        if (uniqIndex != cur->node_->getTypeIndVect()[i][1]) {continue; }

        if(cur->node_->getTypeVect()[i] == type) {
            checked = checkReadinessRecursive(cur->neighbours_[i], checked, type, (i+2)%4);
        }
    }
    return checked;
}

/*
void TileEventHandler::figuresOnPath(TileNode *cur, std::unordered_set<TileNode *> checked, std::pair<int,int> last, std::unordered_set<std::shared_ptr<Figure>> &figures)
{

     * Recursive function that checks how many figures are in certain land (field, castle or road). This is determined
     * by the first pair "last" that gives the indexes to landTypeVect that returns this landIndex.
     *
     * Parameters:
     *      cur = current node being checked
     *      checked = list of nodes that have been checked
     *      last = pair of integers that gives tiles uniqIndex (a.k.a the landindex that we want to check)
     *      figures = container where figures found are placed


    checked.insert(cur); // Ensure same tile isnt being checked twice (necessary to avoid infinte recursive calls)
    int uniqIndex = cur->node_->getTypeIndVect()[last.first][last.second]; // == index we want to check (where we came)

    if (cur->node_->getFig() != nullptr) {
        if (cur->node_->getFig()->getPos().type != monastery) {
            // Getting that on what typeindex the figure is laying on
            std::pair<int,int> indpair = cur->node_->getFig()->getPos().posInIndVec;
            int tileind = cur->node_->getTypeIndVect()[indpair.first][indpair.second];

            // If indexes match, then in this tile has figure that is on landindex that we are trying to check
            if (tileind == uniqIndex) {
                if (figures.find(cur->node_->getFig()) == figures.end()) {
                    figures.insert(cur->node_->getFig());
                }
            }
        }
    }

    // Checking is done and now its time to determine where to continue the search
    for (int i = 0; i < 4; i++) { // loop through every side
        if(cur->neighbours_[i] == nullptr) {continue; }
        if(checked.find(cur->neighbours_[i]) != checked.end()) {continue; }

        for (int j = 0; j < 3; j++) { // loop through every point in side

            // Neighbour on this direction is not nullptr. Thus if current nodes' side has index
            // that we want to check, this means that this the path continues to neighbour
            // (because the tile has to fit)
            if (uniqIndex != cur->node_->getTypeIndVect()[i][j]) {continue; }
            figuresOnPath(cur->neighbours_[i], checked, {(i+2)%4, 2-j}, figures);
        }
    }
}
*/
void TileEventHandler::checkMonasteryReadiness(TileNode *from, std::vector<QPoint> &figsToRemove, std::vector<std::pair<PlayerID, int> > &sb, bool cont)
{
    TileNode *neighbourToCheck;
    bool finished = true;
    for(int i = 0; i < 4; i ++) {
        neighbourToCheck = from->neighbours_[i];
        if (neighbourToCheck == nullptr) {
            finished = false;
        } else {
            if (cont && neighbourToCheck->node_->getMonastery()) {
                checkMonasteryReadiness(neighbourToCheck, figsToRemove, sb, false);
            }
            neighbourToCheck = neighbourToCheck->neighbours_[(i+3) % 4];
            if (neighbourToCheck == nullptr) {
                finished = false;
            } else {
                if (cont && neighbourToCheck->node_->getMonastery()) {
                    checkMonasteryReadiness(neighbourToCheck, figsToRemove, sb, false);
                }
            }
        }
    }

    if (!finished) {return;}
    if(from->node_->getFig() == nullptr) {return;}
    if(from->node_->getFig()->getLandtype() != monastery) {return;}

    figsToRemove.push_back(from->node_->getCoordinates());
    sb.push_back({from->node_->getFig()->getOwner(), 9});
}

void TileEventHandler::changeFieldIndexes(TileNode *cur)
{
    std::unordered_set<int> changedIndexes;
    std::vector<std::vector<int>> tileIndVect = cur->node_->getTypeIndVect();
    for(int i = 0; i < 4; i++) {
        if(cur->neighbours_[i] == nullptr) {continue;}

        std::vector<std::vector<int>> neighbourTileIndVect = cur->neighbours_[i]->node_->getTypeIndVect();

        for(int j = 0; j < 3; j++) {
            int myInd = tileIndVect[i][j];
            int neighInd = neighbourTileIndVect[(i+2)%4][2-j];
            if (myInd != neighInd) {
                if (changedIndexes.find(myInd) != changedIndexes.end()) {
                    mergeLands(cur->neighbours_[i], neighInd, myInd);
                    changeDBKey(neighInd, myInd);
                } else {
                    cur->node_->changeTypeIndexes(myInd, neighInd);
                    changedIndexes.insert(neighInd);
                    tileIndVect = cur->node_->getTypeIndVect(); // Typeindexes have changed so this has to be cached again
                }
            }
        }
    }
}

void TileEventHandler::mergeLands(TileNode *cur, int from, int to)
{
    cur->node_->changeTypeIndexes(from, to);

    for(auto neigbour : cur->neighbours_) {
        if (neigbour == nullptr) {continue;}

        std::vector<std::vector<int>> tileIndVect = neigbour->node_->getTypeIndVect();

        bool tileChecked = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (tileIndVect[i][j] == from) {
                    mergeLands(neigbour, from, to);
                    tileChecked = true;
                    break;
                }
            }
            if(tileChecked) {break;}
        }
    }
}

void TileEventHandler::getFirstLandInd(TileNode *node, int castleIndex, std::unordered_set<int> &inds)
{
    for(int i = 0; i < 4; i++) {
        if(node->node_->getTypeIndVect()[i][1] != castleIndex) { continue;}
        int leftFromCastleIndex = node->node_->getTypeIndVect()[(i + 1) % 4][0];
        int rightFromCastleIndex = node->node_->getTypeIndVect()[(i + 3) % 4][2];

        if(leftFromCastleIndex != castleIndex) {
            if(inds.find(leftFromCastleIndex) == inds.end()) {
                inds.insert(leftFromCastleIndex);
            }
        }

        if(rightFromCastleIndex != castleIndex) {
            if(inds.find(rightFromCastleIndex) == inds.end()) {
                inds.insert(rightFromCastleIndex);
            }
        }
    }
}

int TileEventHandler::getCastleIndexForTile(TileNode *node, std::unordered_set<TileNode *> castlePieces)
{
    for(int i = 0; i < 4; i ++) {
        if(node->node_->getTypeVect()[i] == castle) {
            if(castlePieces.find(node->neighbours_[i]) != castlePieces.end()) {
                return node->node_->getTypeIndVect()[i][1];
            }
        }
    }
    // Should never happen as castlePieces should always contain a finished castle and every piece must have a neighbourpiece
    return -1;
}

void TileEventHandler::changeDBKey(int from, int to)
{
    auto fromItem = figuresOnLand.find(from);

    if(fromItem != figuresOnLand.end()) {

        std::vector<std::shared_ptr<Figure>> tmp = fromItem->second;
        auto toItem = figuresOnLand.find(to);

        if (toItem != figuresOnLand.end()) {
            for(auto fig : tmp) {
                toItem->second.push_back(fig);
            }
        } else {
            figuresOnLand[to] = tmp;
        }
        figuresOnLand.erase(fromItem);
    }
}

void TileEventHandler::giveUniqueTileIndexes(TileNode *node)
{
    std::unordered_set<int> changedIndexes;
    std::vector<std::vector<int>> typevec = node->node_->getTypeIndVect();

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if(changedIndexes.find(typevec[i][j]) == changedIndexes.end() && typevec[i][j] != 0) {
                node->node_->changeTypeIndexes(typevec[i][j], uniqueLandIndex++);
                changedIndexes.insert(typevec[i][j]);
            }
        }
    }
}
