#ifndef WASP
#define WASP

#include <QPainter>

#include "Bug.h"

class Wasp : public Bug
{
    private:
        QImage * image[2];

    public:
        Wasp(double x, double y, double s, double start_angle);
        ~Wasp();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
