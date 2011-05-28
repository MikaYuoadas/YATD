#ifndef ANT
#define ANT

#include <QPainter>

#include "Bug.h"

class Ant : public Bug
{
    public:
        Ant(double x, double y, double s, double start_angle);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
