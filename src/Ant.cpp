#include "Ant.h"
#include "define.h"

Ant::Ant(double x, double y, double s, double start_angle) :
    Bug(x, y, s, 5 * s * s, s * s, start_angle, 2 + s / 2, CRAWL, "ant")
{
    QImage tmp[3];
    tmp[0] = QImage("./sprites/insects/fourmi1.png", "png");
    tmp[1] = QImage("./sprites/insects/fourmi2.png", "png");
    tmp[2] = QImage("./sprites/insects/fourmi3.png", "png");
    int tsize = BASE_SIZE * size;
    image[0] = new QImage(tmp[0].scaled(tsize, tsize, Qt::KeepAspectRatio));
    image[1] = new QImage(tmp[1].scaled(tsize, tsize, Qt::KeepAspectRatio));
    image[2] = new QImage(tmp[2].scaled(tsize, tsize, Qt::KeepAspectRatio));
    timer = new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(5000);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slowDown()));
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
    double tsize = BASE_SIZE * size;
    painter->drawImage(QRectF(-tsize/2, -tsize/2, tsize, tsize), *pic);
}

void Ant::hit(double dmg)
{
    Bug::hit(dmg);
    if (!timer->isActive())
        speed *= 1.5;
    timer->start();
}

void Ant::slowDown()
{
    speed /= 1.5;
}
