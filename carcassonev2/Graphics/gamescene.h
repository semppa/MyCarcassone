#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "Graphics/mapitem.h"
#include "Graphics/gameview.h"
#include "Graphics/figuregraphicsitem.h"
#include <QObject>
#include "Controller/datacontroller.h"
#include "Game/tileeventhandler.h"

class GameView;
class FigureGraphicsItem;
class MapItem;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QWidget* parent, double scale = 50);
    ~GameScene();

    void resize();

    void drawItem(std::shared_ptr<Tile> t);
    FigureGraphicsItem* drawFigure(std::shared_ptr<Figure> figure);

    void drawPlaceHolderTile(std::shared_ptr<Tile> curTile);
    void updatePlaceHolderTile(QPoint newCoords);
    void removePlaceHolderTile();
    void hidePlaceHolderTile();

    void drawPossibleFigurePos(std::shared_ptr<Tile> tile);
    void removePossibleFigurePos(FigureGraphicsItem* ignore = nullptr);

    void drawFigure();
    void removeFigure(std::shared_ptr<Figure> figure);

    bool placeHolderExist() {return placeHolder_ != nullptr;}

    void rotateCW();
    void rotateCCW();

    void setGameView(GameView* view) {view_ = view;}

    bool placeFigure(FigureGraphicsItem* item);
    void highlightFigure(FigureGraphicsItem* item);

    void debug();
    void updateFigPTR(std::shared_ptr<Figure> figPTR);

private:
    GameView* view_;

    int mapWidth_;
    int mapHeight_;
    double mapScale_;

    std::vector<FigureGraphicsItem*> figureGraphicsItems_; // Figures on map
    std::vector<FigureGraphicsItem*> phFigures_; // Placeholder figures you can chose to put figure after tile

    MapItem* placeHolder_ = nullptr;
    FigureGraphicsItem* selectedFigure = nullptr;

    TileEventHandler& tilehndlr_ = TileEventHandler::getInstance();
    DataController& datactrl_ = DataController::getInstance();
};

#endif // GAMESCENE_H
