#include "Wasp.h"
#include "define.h"

Wasp::Wasp(double x, double y, double s, double start_angle) :
    Bug(x, y, s, 7 * s * s, 4 * s * s, start_angle, 3, FLY)
{
    QImage tmp[2];
    tmp[0] = QImage("../sprites/insects/guepe1.png");
    tmp[1] = QImage("../sprites/insects/guepe2.png");
    int tsize = BASE_SIZE * size;
    image[0] = new QImage(tmp[0].scaled(tsize, tsize, Qt::KeepAspectRatio));
    image[1] = new QImage(tmp[1].scaled(tsize, tsize, Qt::KeepAspectRatio));
}

Wasp::~Wasp()
{
    delete image[0];
    delete image[1];
}

void Wasp::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage * pic;
    if (frame > 20) {
        pic = image[0];
        frame = 0;
    } else if (frame > 10)
        pic = image[1];
    else
        pic = image[0];
    double tsize = BASE_SIZE * size;
    painter->drawImage(QRectF(-tsize/2, -tsize/2, tsize, tsize), *pic);
    painter->drawEllipse(QRectF(-tsize/2 + 5, -tsize/2 + 5, tsize - 10, tsize - 10));
}
