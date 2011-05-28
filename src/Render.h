#ifndef RENDER
#define RENDER

#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QHash>

#include "define.h"

class Render : public QGraphicsScene
{
    Q_OBJECT

    private:
        int map[ROW][COLUMN];
        QHash<int, QPixmap> tiles;

    public:
        Render();
        ~Render();
        void drawBackground(QPainter *painter, const QRectF & rect);

    public slots:
        void nextWave();

    signals:
        void newWaveName(QString name);
};
#endif
