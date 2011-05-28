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
    private:
        int map[COLUMN][ROW];
        QHash<int, QPixmap> tiles;

    public:
        Render();
        ~Render();
        void drawBackground(QPainter *painter, const QRectF & rect);
};
#endif
