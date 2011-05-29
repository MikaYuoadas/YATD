#ifndef BUG
#define BUG

#include <QGraphicsItem>
#include <QPainterPath>
#include <QPoint>

#include "define.h"
#include "Render.h"

class Render;

class Bug : public QGraphicsItem
{
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
        bool hit(double dmg);
};
#endif
