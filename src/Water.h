#ifndef WATER
#define WATER

#include "Projectile.h"

class Water : public Projectile
{
    public:
        Water(QPointF start, QPointF dest, short int lvl);
        void paint(QPainter *painter, const QStyleOptionQraphicsItem *option, QWidget *widget);
}
#endif
