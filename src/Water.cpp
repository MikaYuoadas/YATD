#include <cmath>

#include "Water.h"
#include "define.h"

Water::Water(QPointF start, Bug * target, short int level) :
    Projectile(start, target, WATER_SPEED, 5 * pow(1.5, level))
{
}

void Water::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Projectile::paint(painter, Qt::blue);
}
