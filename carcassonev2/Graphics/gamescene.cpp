#include "gamescene.h"

GameScene::GameScene(QWidget *parent, double scale) :
    QGraphicsScene(parent), mapScale_(scale)
{
    resize();
    setBackgroundBrush(Qt::lightGray);
}

GameScene::~GameScene()
{
    for(auto gItem : figureGraphicsItems_) {
        delete gItem;
    }
    for (auto gItem : phFigures_) {
        delete gItem;
    }

    if (placeHolder_ != nullptr) {
        delete placeHolder_;
    }

    if (selectedFigure != nullptr) {
        delete selectedFigure;
    }
}

void GameScene::resize()
{
    QRect area(-5000, -5000, 10000, 10000);
    setSceneRect(area);
}

void GameScene::drawItem(std::shared_ptr<Tile> t)
{
    MapItem* m = new MapItem(t, mapScale_);

    addItem(m);
    m->setPos(t->getCoordinates() * mapScale_);
    m->show();
}

FigureGraphicsItem* GameScene::drawFigure(std::shared_ptr<Figure> figure)
{
    FigureGraphicsItem* item = new FigureGraphicsItem(figure, mapScale_/4);
    addItem(item);

    item->setPos(figure->getTile()->getCoordinates() * mapScale_);

    TilePosition figPos = figure->getPos();
    item->moveBy(figPos.xoffset * mapScale_, figPos.yoffset * mapScale_);

    figureGraphicsItems_.push_back(item); // Has to be here to save figure placed by other players

    return item;
}

void GameScene::drawPlaceHolderTile(std::shared_ptr<Tile> curTile)
{
    placeHolder_ = new MapItem(curTile, mapScale_);
    addItem(placeHolder_);
    placeHolder_->setPos(curTile->getCoordinates() * mapScale_);
    placeHolder_->setOpacity(0.5);
    placeHolder_->setZValue(-1);
}

void GameScene::updatePlaceHolderTile(QPoint newCoords)
{
    placeHolder_->setPos(newCoords*mapScale_);
}

void GameScene::removePlaceHolderTile()
{
    if (placeHolder_) {
        removeItem(placeHolder_);
        delete placeHolder_;
        placeHolder_ = nullptr;
    }
}

void GameScene::hidePlaceHolderTile()
{
    if(placeHolder_) {
        placeHolder_->hide();
    }
}

void GameScene::drawPossibleFigurePos(std::shared_ptr<Tile> tile)
{
    // Get all possible locations from tile
    std::vector<TilePosition> positions = tile->getPossibleFigurePos();

    // Draw figure with opacity 0.3 to all possible locations
    QString sprite ="sprites/figure-" + toQString(datactrl_.getPlayerPTR()->getColor()) + "-transparent.png";

    for(auto pos : positions) {
        std::shared_ptr<Figure> phFig = std::make_shared<Figure>(tile, pos, sprite);

        if (pos.type != monastery) {
            if (tilehndlr_.figureSpaceOccupied(phFig)) { continue;}
        }

        // Drawing item and moving to correct position
        FigureGraphicsItem* gItem = new FigureGraphicsItem(phFig, mapScale_/4);
        addItem(gItem);
        gItem->setPos(tile->getCoordinates() * mapScale_);
        gItem->moveBy(pos.xoffset * mapScale_, pos.yoffset * mapScale_);
        gItem->setOpacity(0.3);
        phFigures_.push_back(gItem);
    }
}

void GameScene::removePossibleFigurePos(FigureGraphicsItem* ignore)
{
    for (auto item : phFigures_) {
        if (item == ignore) {continue;}

        removeItem(item);
        delete item;
        item = nullptr;
    }

    phFigures_ = {};
}

void GameScene::removeFigure(std::shared_ptr<Figure> figure)
{
    for (int i = 0; i < int(figureGraphicsItems_.size()); i++) {
        if (figureGraphicsItems_.at(i)->getFigureObj() == figure) {
            removeItem(figureGraphicsItems_.at(i));
            figureGraphicsItems_.erase(figureGraphicsItems_.begin() + i);
            return;
        }
    }
}

void GameScene::rotateCCW()
{
    if (placeHolder_ != nullptr) {
        for (int i = 0; i < 3; i ++) {
            placeHolder_->rotate();  // :D
        }
    }
}

bool GameScene::placeFigure(FigureGraphicsItem *item)
{
    if (selectedFigure == item && item != nullptr) {
        removePossibleFigurePos(selectedFigure);
        figureGraphicsItems_.push_back(item);
        selectedFigure = nullptr;
        return true;
    }
    return false;
}

void GameScene::highlightFigure(FigureGraphicsItem *item)
{
    if (item == selectedFigure || item == nullptr) {return;} // Item is already selected or not qgraphicsitem

    // Searching if item is in phfigures
    for (auto aitem : phFigures_) {
        if (aitem == item) {
            if (selectedFigure == nullptr) {
                selectedFigure = item;
                selectedFigure->setOpacity(1);
            } else {
                item->setOpacity(1);
                selectedFigure->setOpacity(0.3);
                selectedFigure = item;
            }
            return;
        }
    }

    // Item isnt figure or it is figure but not in phfigures. Therefore
    // no item should be selected
    if (selectedFigure != nullptr) {
        selectedFigure->setOpacity(0.3);
        selectedFigure = nullptr;
    }
}

void GameScene::debug()
{
    qDebug() << "--Placeholder Items--";
    for (auto item : phFigures_) {
        qDebug() << item->getFigureObj()->getTile()->getCoordinates();
    }

    qDebug() << "--Figures on container--";
    for (auto item : figureGraphicsItems_) {
        qDebug() << item->getFigureObj()->getTile()->getCoordinates();
    }
}

void GameScene::updateFigPTR(std::shared_ptr<Figure> figPTR)
{
    for(auto fig : figureGraphicsItems_) {
        if (figPTR->getTile()->getCoordinates() == fig->getFigureObj()->getTile()->getCoordinates()) {
            fig->updateFigPTR(figPTR);
            return;
        }
    }
}

void GameScene::rotateCW()
{
    if (placeHolder_ != nullptr) {
        placeHolder_->rotate();
    }
}

