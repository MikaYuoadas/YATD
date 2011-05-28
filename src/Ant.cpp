#include "Ant.h"
#include "define.h"

Ant::Ant(double x, double y, double s, double start_angle) :
    Bug(x, y, s, start_angle, 2 + s / 2, CRAWL)
{
}

void Ant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double tsize = (BASE_SIZE * size)/2;
    painter->drawImage(QRectF(-tsize, -tsize, tsize, tsize), QImage("../sprites/insects/fourmi1.png", "png"));
}
