#ifndef BUG
#define BUG

#include <QGraphicsItem>

#include "define.h"

class Bug : public QGraphicsItem
{
    protected:
        double size;
        void advance(int step);

    private:
        double hp;
        double resist;
        double angle;
        double speed;
        move moveType;

    public:
        Bug(double x, double y, double s, double health, double res, double start_angle, double init_speed, move type);
        QRectF boundingRect() const;
        bool hit(double dmg);
};
#endif
