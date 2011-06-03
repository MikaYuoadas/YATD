#ifndef RENDER
#define RENDER

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QHash>
#include <QTimer>
#include <QPoint>

#include "define.h"
#include "Bug.h"

class Bug;

class Render : public QGraphicsScene
{
    Q_OBJECT

    private:
        QTimer waveTimer;
        QPoint * start;
        double start_angle;
        int bugNumber;
        int bugSize;
        int map[ROW][COLUMN];
        QPoint goalSquare;
        QHash<int, QPixmap> tiles;
        void addBug(Bug * bug);

    public:
        Render();
        ~Render();
        void drawBackground(QPainter *painter, const QRectF & rect);
        QPoint square(QGraphicsItem & item);
        QPoint goal();
        double getAngle(QPoint & current);

    public slots:
        void nextWave();
        void nextBug();
        void bugFinish(Bug * bug);
        void bugKilled(Bug * bug);

    signals:
        void newWaveName(QString name);
        void loseLife();
        void getCred();
};
#endif
