#include <cmath>

#include "Water.h"

Water::Water(QPointF start, QPointF dest, short int level) :
    Projectile(start, dest, WATER_SPEED, 5 * pow(1.5, level))
{
}

void Water::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    paint(painter, Qt::blue);
}
