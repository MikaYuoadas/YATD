#include <cmath>

#include "Bowling.h"
#include "define.h"

Bowling::Bowling(QPointF start, Bug * target, short int level) :
    Projectile(start, target, BOWLING_SPEED, 15 * pow(level, 1.5))
{
}

void Bowling::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Projectile::paint(painter, Qt::black);
}
