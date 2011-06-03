#ifndef MOSQUITO
#define MOSQUITO

#include <QPainter>

#include "Bug.h"

class Mosquito : public Bug
{
    private:
        QImage * image[2];

    public:
        Mosquito(double x, double y, double s, double start_angle);
        ~Mosquito();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
