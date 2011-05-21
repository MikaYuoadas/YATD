#ifndef Tower
#define Tower
#include <QWidget>
#include "Missile.h"

class Tower : QWidget
{
    private:
        float range;
        float rate;
        float dmg;
        int price[3];
        int target;
        Missile * missile;
    public:
        Tower(QWidget * parent);
}
#endif
