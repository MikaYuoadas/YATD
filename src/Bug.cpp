#include <cmath>

#include "Bug.h"
#include "define.h"

Bug::Bug(double x, double y, double s, double start_angle, double init_speed, move type) :
    size(s), angle(start_angle), speed(init_speed), moveType(type)
{
    setRotation(start_angle);
    setPos(x, y);
}

QRectF Bug::boundingRect() const
{
    double tsize = (BASE_SIZE * size)/2;
    return QRectF(-tsize - 1, -tsize -1, tsize + 1, tsize + 1);
}

void Bug::advance(int step)
{
    if (!step)
        return;
    moveBy(cos(angle) * speed * BASE_SPEED, sin(angle) * speed * BASE_SPEED);
}
