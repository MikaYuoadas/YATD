#ifndef TOWER
#define TOWER

#include <QGraphicsObject>
#include <QPainter>
#include <QPointF>
#include <QTimer>
#include <QString>

#include "Projectile.h"
#include "Render.h"

class Render;

class Tower : public QGraphicsObject
{
    Q_OBJECT

    private:
        short int level;
        QColor color;
        short int target;
        double range;
        double firerate;
        QTimer * timer;
        QPointF pos;
        QString type;

    public:
        Render * parent;
        Tower(QPointF buildPos, QString typeTower);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public slots:
        void fire();

    signals:
        void projectile(Projectile * missile);
};
#endif
