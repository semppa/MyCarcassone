#include "mapitem.h"

MapItem::MapItem(std::shared_ptr<Tile> gameobj, int scale) :
     gameObj_(gameobj), scale_(scale)
{
    painter = new QPainter();
    QStyleOptionGraphicsItem* tmp = new QStyleOptionGraphicsItem();
    QWidget* an = new QWidget();

    paint(painter, tmp, an);
    update();
}

QRectF MapItem::boundingRect() const
{
    return QRectF(QPointF(0, 0), QPointF(scale_, scale_));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    QString filename = gameObj_->getSprite();
    int rotation = gameObj_->getRotationNum();

    QPixmap tmp(filename);
    // QPixmap scaled = tmp.scaled(scale_, scale_);

    QMatrix rm;
    rm.rotate(rotation * 90);
    tmp = tmp.transformed(rm);

    painter->drawPixmap(0, 0, scale_, scale_, tmp);
}

void MapItem::rotate()
{
    gameObj_->rotateTile();
    update();
}
