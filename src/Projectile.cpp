#include "Projectile.h"
#include "define.h"

Projectile::Projectile(QPointF start, QPointF dest, double init_speed) :
    destination(dest), speed(init_speed)
{
    setPos(start);
}

QRectF Projectile::boundingRect() const
{
    return QRectF(-PROJECTILE_SIZE / 2, -PROJECTILE_SIZE / 2, PROJECTILE_SIZE, PROJECTILE_SIZE);
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRect(-PROJECTILE_SIZE / 2, - PROJECTILE_SIZE / 2, PROJECTILE_SIZE, PROJECTILE_SIZE));
}
