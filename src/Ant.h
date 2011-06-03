#ifndef ANT
#define ANT

#include <QPainter>
#include <QTimer>
#include <QObject>

#include "Bug.h"

class Ant : public Bug
{
    Q_OBJECT

    private:
        QImage * image[3];
        QTimer * timer;

    public:
        Ant(double x, double y, double s, double start_angle);
        ~Ant();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void hit(double dmg);

    private slots:
        void slowDown();
};
#endif
