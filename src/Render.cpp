#include <QGraphicsPixmapItem>
#include <QFile>
#include <QString>
#include <QTextStream>

#include "Render.h"
#include "define.h"

Render::Render() : QGraphicsScene()
{
    QFile file("../map/map_1");
    !file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    for (int i = 0; i < COLUMN && !in.atEnd(); i++) {
        QStringList line = in.readLine().split(" ");
        for (int j = 0; j < ROW && j < line.size(); j++) {
            int num = line.at(j).toInt();
            map[i][j] = num;
            if (!tiles.contains(num)) {
                QString path;
                switch (num){
                    case NORD:
                    case SUD:
                        path = "../sprites/ground/grass.jpg";
                        break;
                    case EAST:
                    case WEST:
                        path = "../sprites/ground/grass.jpg";
                        break;
                    case NE:
                    case SO:
                        path = "../sprites/ground/grass.jpg";
                        break;
                    case SE:
                    case NO:
                        path = "../sprites/ground/grass.jpg";
                        break;
                    case GOAL:
                        path = "../sprites/ground/grass.jpg";
                        break;
                    case DIRT:
                        path = "../sprites/ground/grass.jpg";
                        break;
                    default:
                        path = "../sprites/ground/grass.jpg";
                        break;
                }
                if (num > 10 && num < 32)
                    path = "../sprites/ground/grass.jpg";
                tiles.insert(num, QPixmap(path));
            }
        }
    }
    file.close();
}

Render::~Render()
{
}

void Render::drawBackground(QPainter *painter, const QRectF & rect)
{
    for(int i = 0; i < COLUMN; i++)
        for(int j = 0; j < ROW; j++) {
            painter->drawPixmap(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, tiles[map[i][j]]);
        }
}
