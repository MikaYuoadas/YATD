#ifndef RENDER
#define RENDER

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QHash>
#include <QTimer>
#include <QPoint>
#include <QStringList>

#include "define.h"
#include "Hatchery.h"
#include "Tower.h"

class Bug;
class Hatchery;
class Tower;
class Projectile;

class Render : public QGraphicsScene
{
    Q_OBJECT

    private:
        QTimer waveTimer;
        QPoint * start;
        double start_angle;
        int waveNumber;
        QStringList * wave;
        int map[ROW][COLUMN];
        Tower * towers[ROW][COLUMN];
        QPoint goalSquare;
        QHash<int, QPixmap> tiles;
        void addBug(Bug * bug);
        Hatchery * b1;
        QString tower2build;
        QList<Bug *> bugs;

    public:
        Render();
        ~Render();
        void drawBackground(QPainter *painter, const QRectF & rect);
        QPoint square(QGraphicsItem & item);
        QPoint goal();
        double getAngle(QPoint & current);
        void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        Bug * getTarget(QPointF pos, double range);

    public slots:
        void nextWave();
        void nextBug();
        void towerBought(QString type);
        void bugFinish(Bug * bug);
        void bugKilled(Bug * bug);
        void addProjectile(Projectile * missile);
        void destroyTower(Tower * tower);
        void explodingProjectile(Projectile * missile);

    signals:
        void newWaveName(QString name);
        void loseLife();
        void getCred();
        void selectTower(Tower * tower);
};
#endif
