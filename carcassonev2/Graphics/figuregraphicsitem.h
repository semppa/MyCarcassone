#ifndef FIGUREGRAPHICSITEM_H
#define FIGUREGRAPHICSITEM_H

#include <QGraphicsItem>
#include "Game/tile.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class GameView;

class FigureGraphicsItem : public QGraphicsItem
{
public:
    enum {FigureItem = UserType + 2};

    FigureGraphicsItem(std::shared_ptr<Figure> figobj, int scale = 50);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    std::shared_ptr<Figure> getFigureObj() {return figobj_;}
    void updateFigPTR(std::shared_ptr<Figure> newFigPTR) {figobj_ = newFigPTR;}

    int type() const override { return FigureItem; }

private:
    std::shared_ptr<Figure> figobj_;
    int scale_;
};

#endif // FIGUREGRAPHICSITEM_H
