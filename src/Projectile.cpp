#include <cmath>

#include "Projectile.h"
#include "define.h"

Projectile::Projectile(QPointF start, QPointF destination, double init_speed, double damage) :
    dest(destination), speed(init_speed), dmg(damage), travelled(0)
{
    maxrange = sqrt(pow(2, dest.x() - start.x()) + pow(2, dest.y() - start.y()));
    setPos(start);
}

void Projectile::advance(int step)
{
    if (!step)
        return;
    double hyp = sqrt(pow(2, dest.x() - pos().x()) + pow(2, dest.y() - pos().y()));
    double rspeed = speed * BASE_SPEED;
    moveBy((dest.x() - pos().x()) / hyp * rspeed, (dest.y() - pos().y()) / hyp * rspeed);
    travelled += rspeed;
    // if travelled > maxrange explode
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
