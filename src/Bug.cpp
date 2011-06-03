#include <cmath>

#include "Bug.h"
#include "define.h"

Bug::Bug(double x, double y, double s, double health, double res, double start_angle, double init_speed, move type) :
    size(s), frame(0), hp(health), resist(res), angle(start_angle), speed(init_speed), moveType(type),
    lastSquare(QPoint(floor(x / SQUARE_SIZE), floor(y /SQUARE_SIZE)))
{
    setRotation(start_angle);
    setPos(x, y);
}

QRectF Bug::boundingRect() const
{
    double tsize = (BASE_SIZE * size) + 2;
    return QRectF( -tsize/2, -tsize/2, tsize, tsize);
}

void Bug::advance(int step)
{
    if (!step)
        return;
    frame += 1;
    moveBy(cos(angle * PI / 180) * speed * BASE_SPEED, sin(angle * PI / 180) * speed * BASE_SPEED);
    QPoint currentSquare = parent->square(*this);
    if (currentSquare != lastSquare) {
        lastSquare = currentSquare;
        angle = parent->getAngle(currentSquare);
        setRotation(angle);
    }
    if (currentSquare == parent->goal())
    {
        emit goalReached(this);
    }
}

QPainterPath Bug::shape() const
{
    QPainterPath path;
    double tsize = (BASE_SIZE * size) - 10;
    path.addEllipse(-tsize/2, -tsize/2, tsize, tsize);
    return path;
}

void Bug::hit(double dmg)
{
    hp -= dmg - resist;
    if (hp <= 0)
        emit dead(this);
}
