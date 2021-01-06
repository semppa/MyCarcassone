#ifndef MAPITEM_H
#define MAPITEM_H

#include <QGraphicsItem>
#include "Game/tile.h"
#include "Graphics/gameview.h"
#include <QPainter>

#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <QDebug>

class GameView;

class MapItem : public QGraphicsItem
{
public:
    enum {TileItem = UserType + 1};

    MapItem(std::shared_ptr<Tile> gameobj = nullptr, int scale = 50);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void rotate();

    int type() const override { return TileItem; }

private:
    QPainter* painter;
    std::shared_ptr<Tile> gameObj_;
    int scale_;
};

#endif // MAPITEM_H
