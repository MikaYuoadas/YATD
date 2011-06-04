#ifndef PROJECTILE
#define PROJECTILE

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>
#include <QString>

#include "Projectile.h"

class Projectile : public QGraphicsItem
{
    private:
        QPointF destination;
        double speed;

    public:
        Projectile(QPointF start, QPointF dest, double init_speed);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
