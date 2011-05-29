#ifndef RENDER
#define RENDER

#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QHash>
#include <QTimer>
#include <QPoint>

#include "define.h"

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

    public:
        Render();
        ~Render();
        void drawBackground(QPainter *painter, const QRectF & rect);

    public slots:
        void nextWave();
        void nextBug();

    signals:
        void newWaveName(QString name);
};
#endif
