#include "gameview.h"


GameView::GameView(QWidget *parent, GameScene* gamescene) : QGraphicsView(parent), scene_(gamescene)
{
    setGeometry(10, 10, parent->width()-20, 550);
    setScene(dynamic_cast<QGraphicsScene*>(scene_));
    setInteractive(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setTransformationAnchor(QGraphicsView::NoAnchor);
    setFocus();
    setMouseTracking(false);

    // tb = new TileDatabase();

    /*  Draws grid
    for (int x = 0; x < 11; x++) {
        QGraphicsItem* item = scene_->addLine(x*50, 0, x*50, 500);
        item->setTransform(tm);
    }

    for (int y = 0; y < 11; y++) {
        QGraphicsItem* item = scene_->addLine(0, y*50, 500, y*50);
        item->setTransform(tm);
    } */
    // tmp_ = std::make_shared<Tile>(QPoint(0,0), tb->getTile(20), 0);
}

GameView::~GameView()
{

}

void GameView::mouseMoveEvent(QMouseEvent *event)
{
    if (mmbtn) {
        int dx = event->x() - beginDragX;
        int dy = event->y() - beginDragY;

        translate(dx / transform().m11(), dy / transform().m22());

        beginDragX = event->x();
        beginDragY = event->y();
        return;
    }

    if(!datactrl_.myTurn()) { return;}

    if (!tilePlaced) {  // Nothing happens if mousetracking is off
        QPoint c = getWorldCoords(event->x(), event->y());

        if (!scene_->placeHolderExist()) {
            tmp_ = std::make_shared<Tile>(c, datactrl_.getCurTile(), 0);
            for (int i = 0; i<rotateN; i++) {tmp_->rotateTile();}
            scene_->drawPlaceHolderTile(tmp_);
            return;
        }

        if (curPHLoc_ == c) {
            return;
        }

        scene_->updatePlaceHolderTile(c);
        curPHLoc_ = c;

    } else {
        scene_->highlightFigure(qgraphicsitem_cast<FigureGraphicsItem*>(itemAt(event->pos())));
    }
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton || event->button() == Qt::RightButton) {
        mmbtn = true;
        beginDragX = event->x();
        beginDragY = event->y();
        return;
    }

    if (event->button() == Qt::LeftButton && datactrl_.myTurn()) {
        if (!tilePlaced) {
            QPoint c = getWorldCoords(event->x(), event->y());
            tmp_->updateCoords(c);

            if(!tilehndlr_.tileFits(tmp_)) {return;}

            scene_->drawItem(tmp_);
            tilehndlr_.tilePlaced(tmp_);

            scene_->removePlaceHolderTile();
            if (datactrl_.getPlayerPTR()->getNFigures() > 0) {
                scene_->drawPossibleFigurePos(tmp_);
            }

            tilePlaced = true;
            netctrl_->tilePlaced(tmp_);
        } else {
            FigureGraphicsItem* curItem = qgraphicsitem_cast<FigureGraphicsItem*>(itemAt(event->pos()));
            if(scene_->placeFigure(curItem)) {
                netctrl_->figurePlaced(curItem->getFigureObj());
                setMouseTracking(false);
            }
        }
    }
}

void GameView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton || event->button() == Qt::RightButton) {
        mmbtn = false;
    }
}

void GameView::wheelEvent(QWheelEvent *event)
{
    QPointF before = mapToScene(event->x(), event->y());
    if(event->angleDelta().y() < 0) {
        scale(1.1, 1.1);
    } else {
        scale(0.9, 0.9);
    }
    QPointF after = mapToScene(event->x(), event->y());

    translate(after.x()-before.x(), after.y()-before.y());
}

void GameView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left: {
        scene_->rotateCW();
        rotateN ++;
        if (rotateN > 3) { rotateN = 0;}
        emit rotateTileView(rotateN);
        break;
    }

    case Qt::Key_Right: {
        scene_->rotateCCW();
        rotateN --;
        if (rotateN < 0) { rotateN = 3;}
        emit rotateTileView(rotateN);
        break;
    }

    case Qt::Key_Up: {
        QPointF before = mapToScene(0,0);
        scale(1.1, 1.1);
        QPointF after = mapToScene(0,0);
        translate(after.x()-before.x(), after.y()-before.y());
        break;
    }

    case Qt::Key_Down: {
        QPointF before = mapToScene(0,0);
        scale(0.9, 0.9);
        QPointF after = mapToScene(0,0);
        translate(after.x()-before.x(), after.y()-before.y());
        break;
    }

    case Qt::Key_A: {
        qDebug() << "Debugging!!!!";
        /*
        std::vector<std::pair<PlayerID, int>> sb;
        tilehndlr_.calculateFinalPoints(sb);

        for(auto point : sb) {
            qDebug() << datactrl_.getPlayerPTR(point.first)->getNick() << "gets" << point.second << "points.";
        }
        */
        tilehndlr_.debug();
    }

    default:
        return;
    }
}

void GameView::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    /*
    switch (event->key()) {
    default:
        return;
    }
    */
}

void GameView::initializeMyTurn()
{
    tilePlaced = false;
    setMouseTracking(true);
    setFocus();
    rotateN = 0;
}

void GameView::endTurnCleanup()
{
    scene_->removePossibleFigurePos();
    tmp_ = nullptr;
}

QPoint GameView::getWorldCoords(int mouseX, int mouseY)
{
    QPointF unscaled = mapToScene(mouseX, mouseY);

    if (unscaled.rx() < 0) {
        unscaled.rx() -= 50;
    }

    if (unscaled.ry() < 0) {
        unscaled.ry() -= 50;
    }

    return QPoint(unscaled.rx() / 50, unscaled.ry() / 50);
}

