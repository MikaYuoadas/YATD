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
        QHash<int, QPixmap> tiles;
        void addBug(Bug * bug);

    public:
        Render();
        ~Render();
        void drawBackground(QPainter *painter, const QRectF & rect);
        QPoint square(QGraphicsItem & item);
        double getAngle(QPoint & current);

    public slots:
        void nextWave();
        void nextBug();

    signals:
        void newWaveName(QString name);
};
#endif
