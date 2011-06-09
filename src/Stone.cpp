#include <cmath>

#include "Stone.h"
#include "define.h"

Stone::Stone(QPointF start, Bug * target, short int level) :
    Projectile(start, target, STONE_SPEED, 10 * pow(level, 1.5))
{
}

void Stone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Projectile::paint(painter, Qt::grey);
}
