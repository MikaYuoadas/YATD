#ifndef WATER
#define WATER

#include "Projectile.h"

class Water : public Projectile
{
    public:
        Water(QPointF start, Bug * target, short int lvl);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
