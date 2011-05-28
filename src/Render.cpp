#include <QGraphicsPixmapItem>
#include <QFile>
#include <QString>
#include <QTextStream>

#include "Render.h"
#include "define.h"
#include "Ant.h"

Render::Render() : QGraphicsScene()
{
    QFile file("../map/map_1");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    for (int i = 0; i < ROW && !in.atEnd(); i++) {
        QStringList line = in.readLine().split(" ", QString::SkipEmptyParts);
        for (int j = 0; j < COLUMN && j < line.size(); j++) {
            int num = line.at(j).toInt();
            map[i][j] = num;
            if (!tiles.contains(num)) {
                QString path;
                switch (num){
                    case NORTH:
                    case SOUTH:
                        path = "../sprites/ground/trail_NS.jpg";
                        break;
                    case EAST:
                    case WEST:
                        path = "../sprites/ground/trail_EW.jpg";
                        break;
                    case NE:
                    case SW:
                        path = "../sprites/ground/trail_NE-SW.jpg";
                        break;
                    case SE:
                    case NW:
                        path = "../sprites/ground/trail_NW-SE.jpg";
                        break;
                    case GOAL:
                        path = "../sprites/ground/goal.png";
                        break;
                    case DIRT:
                        path = "../sprites/ground/dirt.png";
                        break;
                    default:
                        path = "../sprites/ground/grass.jpg";
                        break;
                }
                if (num > 10 && num < 32)
                    path = "../sprites/ground/start.png";
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
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COLUMN; j++) {
            painter->drawPixmap(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, tiles[map[i][j]]);
        }
}

void Render::nextWave()
{
    Ant * ant = new Ant(0, 100, 3, 0);
    addItem(ant);
    QFile file("../map/waves_1");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    if (!in.atEnd()) {
        QStringList line = in.readLine().split(";", QString::SkipEmptyParts);
        if (line.size() >= 2) {
            emit newWaveName(line.at(0));
            QStringList params = line.at(1).split(":", QString::SkipEmptyParts);
        }
    }
    file.close();
}
