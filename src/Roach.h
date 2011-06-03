#ifndef ROACH
#define ROACH

#include <QPainter>

#include "Bug.h"

class Roach : public Bug
{
    private:
        QImage * image[3];

    public:
        Roach(double x, double y, double s, double start_angle);
        ~Roach();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
