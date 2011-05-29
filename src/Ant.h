#ifndef ANT
#define ANT

#include <QPainter>

#include "Bug.h"

class Ant : public Bug
{
    private:
        QImage * image[3];
    public:
        Ant(double x, double y, double s, double start_angle);
        ~Ant();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
