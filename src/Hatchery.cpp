#include "Hatchery.h"
#include "Ant.h"
#include "Wasp.h"
#include "Roach.h"
#include "Mosquito.h"

Hatchery::Hatchery(double start_x, double start_y, double start_angle) : x(start_x), y(start_y), angle(start_angle)
{
}

Bug * Hatchery::spawnBug(QString race, double size)
{
    Bug * bug = NULL;
    if (race == "fourmi")
        bug = new Ant(x, y, size, angle);
    else if (race == "guepe")
        bug = new Wasp(x, y, size, angle);
    else if (race == "cafard")
        bug = new Roach(x, y, size, angle);
    else if (race == "moustique")
        bug = new Mosquito(x, y, size, angle);
    return bug;
}
