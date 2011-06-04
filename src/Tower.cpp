#include "Tower.h"
#include "define.h"

Tower::Tower(QColor col) :
    color(col)
{
}

QRectF Tower::boundingRect() const
{
    return QRectF(-TOWER_SIZE / 2, -TOWER_SIZE / 2, TOWER_SIZE, TOWER_SIZE);
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget)
{
    painter->setBrush(color);
    painter->drawEllipse(QRect(-TOWER_SIZE / 2, - TOWER_SIZE / 2, TOWER_SIZE, TOWER_SIZE));
}
