#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QPoint>
#include <Game/tile.h>
#include <Graphics/gamescene.h>
#include <Controller/datacontroller.h>
#include <Controller/networkcontroller.h>
#include <Game/tileeventhandler.h>

class GameScene;

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(QWidget* parent = nullptr, GameScene* gamescene = nullptr);
    ~GameView();

    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void setNetCtrl(std::shared_ptr<NetWorkController> n) {netctrl_ = n;}

    void initializeMyTurn();
    void endTurnCleanup();

signals:
    void rotateTileView(int rotateN);


private:
    int beginDragX;
    int beginDragY;

    QPoint getWorldCoords(int mouseX, int mouseY);

    GameScene* scene_;

    DataController& datactrl_ = DataController::getInstance();
    TileEventHandler& tilehndlr_ = TileEventHandler::getInstance();
    std::shared_ptr<NetWorkController> netctrl_;

    bool mmbtn = false; // middlemousebutton

    bool tilePlaced = false;
    int rotateN = 0;

    QPoint curPHLoc_;  // Current PlaceHoldertile location
    std::shared_ptr<Tile> tmp_;
};

#endif // GAMEVIEW_H
