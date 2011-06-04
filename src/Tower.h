#ifndef TOWER
#define TOWER

#include <QGraphicsItem>
#include <QPainter>

class Tower : public QGraphicsItem
{
    private:
        int level;
        QColor color;

    public:
        Tower(QColor col);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
