#include "figuregraphicsitem.h"

FigureGraphicsItem::FigureGraphicsItem(std::shared_ptr<Figure> figobj, int scale) :
    figobj_(figobj), scale_(scale)
{
    QPainter* painter = new QPainter();
    QStyleOptionGraphicsItem* tmp = new QStyleOptionGraphicsItem();
    QWidget* an = new QWidget();

    paint(painter, tmp, an);
    update();
}

QRectF FigureGraphicsItem::boundingRect() const
{
    return QRectF(QPointF(0, 0), QPointF(scale_, scale_));
}

void FigureGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    QString filename = figobj_->getSprite();

    QPixmap tmp(filename);
    // QPixmap scaled = tmp.scaled(scale_, scale_);  DONT DO THIS, THIS PIXELATES THE FIGURE. LET VIEW DO THE SCALING

    painter->drawPixmap(0, 0, scale_, scale_, tmp);  // Here its ensured that figure is correct length
}
