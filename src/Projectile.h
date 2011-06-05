#ifndef PROJECTILE
#define PROJECTILE

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>
#include <QString>

#include "Projectile.h"

class Projectile : public QGraphicsItem
{
    protected:
        void advance(int step);

    private:
        QPointF dest;
        double speed;
        double dmg;
        double maxrange;
        double travelled;

    public:
        Projectile(QPointF start, QPointF destination, double init_speed, double damage);
        QRectF boundingRect() const;
        void paint(QPainter *painter, QColor color);
};
#endif
