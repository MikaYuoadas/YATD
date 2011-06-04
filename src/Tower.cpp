#include "Tower.h"
#include "define.h"

Tower::Tower(QPointF buildPos, QString typeTower) :
    level(1), pos(buildPos), type(typeTower), parent(NULL)
{
    if (type == "water") {
        price = 4;
        firerate = 4.5;
        range = 2.5;
        target = CRAWL & FLY;
        color = Qt::cyan;
    } else if (type == "slingshot") {
        price = 6;
        firerate = 1.0;
        range = 3.5;
        target = FLY;
        color = Qt::yellow;
    } else if (type == "paintball") {
        price = 6;
        firerate = 2;
        range = 4.5;
        target = CRAWL & FLY;
        color = Qt::darkRed;
    } else if (type == "bowling") {
        price = 7.5;
        firerate = 0.5;
        range = 4;
        target = CRAWL;
        color = Qt::darkGray;
    }
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(fire()));
    timer->start(1000 / firerate);
    setPos(pos);
}

QRectF Tower::boundingRect() const
{
    return QRectF(-TOWER_SIZE / 2, -TOWER_SIZE / 2, TOWER_SIZE, TOWER_SIZE);
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget)
{
    painter->setBrush(color);
    painter->drawEllipse(QRect(-TOWER_SIZE / 2, - TOWER_SIZE / 2, TOWER_SIZE, TOWER_SIZE));
}

QString Tower::getType()
{
    return type;
}

double Tower::getRange()
{
    return range;
}

short int Tower::getLvl()
{
    return level;
}

float Tower::getPrice()
{
    return price;
}

double Tower::getFirerate()
{
    return firerate;
}

void Tower::fire()
{
    Bug * target = parent->getTarget(pos, range);
    Projectile * missile = NULL;
    emit projectile(missile);
}
