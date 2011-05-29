#include "Ant.h"
#include "define.h"

Ant::Ant(double x, double y, double s, double start_angle) :
    Bug(x, y, s, 5 * s * s, s * s, start_angle, 2 + s / 2, CRAWL)
{
    image[0] = new QImage("../sprites/insects/fourmi1.png", "png");
    image[1] = new QImage("../sprites/insects/fourmi2.png", "png");
    image[2] = new QImage("../sprites/insects/fourmi3.png", "png");
}

Ant::~Ant()
{
    delete image[0];
    delete image[1];
    delete image[2];
}

void Ant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage * pic;
    if (frame > 40) {
        pic = image[0];
        frame = 0;
    } else if (frame > 30)
        pic = image[1];
    else if (frame > 20)
        pic = image[2];
    else if (frame > 10)
        pic = image[1];
    else
        pic = image[0];
    double tsize = (BASE_SIZE * size);
    painter->drawImage(QRectF(-tsize/2, -tsize/2, tsize, tsize), *pic);
    painter->drawEllipse(QRectF(-tsize/2 + 5, -tsize/2 + 5, tsize - 10, tsize - 10));
}
