#include "Roach.h"
#include "define.h"

Roach::Roach(double x, double y, double s, double start_angle) :
    Bug(x, y, s, 10/*10 * s * s*/, 5 * s * s, start_angle, 2, CRAWL, "roach")
{
    QImage tmp[3];
    tmp[0] = QImage("./sprites/insects/cafard1.png");
    tmp[1] = QImage("./sprites/insects/cafard2.png");
    tmp[2] = QImage("./sprites/insects/cafard3.png");
    int tsize = BASE_SIZE * size;
    image[0] = new QImage(tmp[0].scaled(tsize, tsize, Qt::KeepAspectRatio));
    image[1] = new QImage(tmp[1].scaled(tsize, tsize, Qt::KeepAspectRatio));
    image[2] = new QImage(tmp[2].scaled(tsize, tsize, Qt::KeepAspectRatio));
}

Roach::~Roach()
{
    delete image[0];
    delete image[1];
    delete image[2];
}

void Roach::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    double tsize = BASE_SIZE * size;
    painter->drawImage(QRectF(-tsize/2, -tsize/2, tsize, tsize), *pic);
}
