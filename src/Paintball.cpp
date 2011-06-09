#include <cmath>

#include "Paintball.h"
#include "define.h"

Paintball::Paintball(QPointF start, Bug * target, short int level) :
    Projectile(start, target, PAINTBALL_SPEED, 4 * pow(level, 1.5))
{
}

void Paintball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Projectile::paint(painter, Qt::red);
}
