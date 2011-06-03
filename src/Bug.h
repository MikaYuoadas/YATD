#ifndef BUG
#define BUG

#include <QGraphicsObject>
#include <QPainterPath>
#include <QPoint>

#include "define.h"
#include "Render.h"

class Render;

class Bug : public QGraphicsObject
{
    Q_OBJECT

    protected:
        double size;
        int frame;
        void advance(int step);

    private:
        double hp;
        double resist;
        double angle;
        double speed;
        move moveType;
        QPoint lastSquare;

    public:
        Render * parent;
        Bug(double x, double y, double s, double health, double res, double start_angle, double init_speed, move type);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void hit(double dmg);

    signals:
        void dead(Bug * bug);
        void goalReached(Bug * bug);
};
#endif
