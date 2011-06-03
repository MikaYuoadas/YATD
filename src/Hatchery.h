#ifndef HATCHERY
#define HATCHERY

#include <QString>

#include "Bug.h"

class Bug;

class Hatchery
{
    private:
        double x;
        double y;
        double angle;

    public:
        Hatchery(double start_x, double start_y, double start_angle);
        Bug * spawnBug(QString race, double size);
};
#endif
