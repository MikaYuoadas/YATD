#include <cmath>

#include "Projectile.h"
#include "define.h"

Projectile::Projectile(QPointF start, Bug * trgt, double init_speed, double damage) :
    dest(trgt->pos()), target(trgt), speed(init_speed), dmg(damage), travelled(0), parent(NULL)
{
    maxrange = sqrt(pow(dest.x() - start.x(), 2) + pow(dest.y() - start.y(), 2));
    setPos(start);
}

void Projectile::advance(int step)
{
    if (!step)
        return;
    double hyp = sqrt(pow(dest.x() - pos().x(), 2) + pow(dest.y() - pos().y(), 2));
    double rspeed = speed * BASE_SPEED;
    moveBy((dest.x() - pos().x()) / hyp * rspeed, (dest.y() - pos().y()) / hyp * rspeed);
    travelled += rspeed;
    if (travelled > maxrange) {
        setPos(dest);
        if (parent->isnotDead(target))
            target->hit(dmg);
        emit explode(this);
    }
}

QRectF Projectile::boundingRect() const
{
    return QRectF(-PROJECTILE_SIZE / 2, -PROJECTILE_SIZE / 2, PROJECTILE_SIZE, PROJECTILE_SIZE);
}

void Projectile::paint(QPainter *painter, QColor color)
{
    painter->setBrush(color);
    painter->drawEllipse(QRect(-PROJECTILE_SIZE / 2, - PROJECTILE_SIZE / 2, PROJECTILE_SIZE, PROJECTILE_SIZE));
}
