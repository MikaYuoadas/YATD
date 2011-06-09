#include "Tower.h"
#include "Water.h"
#include "Stone.h"
#include "Paintball.h"
#include "Bowling.h"
#include "define.h"

Tower::Tower(QPointF buildPos, QString typeTower) :
    level(1), pos(buildPos), type(typeTower), parent(NULL)
{
    if (type == "water") {
        upg1 = 20;
        upg2 = 45;
        price = 4;
        firerate = 4.5;
        range = 2.5;
        targetType = CRAWL | FLY;
        color = Qt::cyan;
    } else if (type == "slingshot") {
        upg1 = 25;
        upg2 = 60;
        price = 6;
        firerate = 1.0;
        range = 3.5;
        targetType = FLY;
        color = Qt::yellow;
    } else if (type == "paintball") {
        upg1 = 25;
        upg2 = 60;
        price = 6;
        firerate = 2;
        range = 4.5;
        targetType = CRAWL | FLY;
        color = Qt::darkRed;
    } else if (type == "bowling") {
        upg1 = 40;
        upg2 = 80;
        price = 7.5;
        firerate = 0.5;
        range = 4;
        targetType = CRAWL;
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

float Tower::getUpgCost()
{
    if (level == 2)
        return upg2;
    else
        return upg1;
}

double Tower::getFirerate()
{
    return firerate;
}

void Tower::fire()
{
    Bug * target = parent->getTarget(pos, range, targetType);
    if (target != NULL) {
        Projectile * missile = NULL;
        if (type == "water") {
            missile = new Water(pos, target, level);
        } else if (type == "slingshot") {
            missile = new Stone(pos, target, level);
        } else if (type == "paintball") {
            missile = new Paintball(pos, target, level);
        } else if (type == "bowling") {
            missile = new Bowling(pos, target, level);
        }
        emit projectile(missile);
    }
}

void Tower::upgrade()
{
    level += 1;
    if (type == "water") {
        if (level == 2)
            price = 14;
        else
            price = 37;
        firerate = 4 - level / 2;
        range = 2 + level / 2;
    } else if (type == "slingshot") {
        if (level == 2)
            price = 19;
        else
            price = 49;
        range = 3 + level / 2;
    } else if (type == "paintball") {
        if (level == 2)
            price = 19;
        else
            price = 49;
        range = 4 + level / 2;
    } else if (type == "bowling") {
        if (level == 2)
            price = 28;
        else
            price = 68;
        range = 3 + level;
    }
    timer->start(1000 / firerate);
}

void Tower::pause()
{
    timer->stop();
}

void Tower::unpause()
{
    timer->start(1000 / firerate);
}
