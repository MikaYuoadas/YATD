#ifndef PROJECTILE
#define PROJECTILE

#include <QGraphicsObject>
#include <QPainter>
#include <QPointF>
#include <QString>

#include "Bug.h"

class Bug;

class Projectile : public QGraphicsObject
{
    Q_OBJECT

    protected:
        void advance(int step);

    private:
        QPointF dest;
        Bug * target;
        double speed;
        double dmg;
        double maxrange;
        double travelled;

    public:
        Projectile(QPointF start, Bug * trgt, double init_speed, double damage);
        QRectF boundingRect() const;
        void paint(QPainter *painter, QColor color);

    signals:
        void explode(Projectile * missile);
};
#endif
