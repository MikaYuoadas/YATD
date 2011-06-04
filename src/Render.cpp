#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QList>
#include <cmath>

#include "Render.h"
#include "define.h"
#include "Hatchery.h"

Render::Render() : QGraphicsScene(), start_angle(0), waveNumber(1), tower2build(QString("none"))
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
                        goalSquare = QPoint(j, i);
                        break;
                    case DIRT:
                        path = "../sprites/ground/dirt.png";
                        break;
                    default:
                        path = "../sprites/ground/grass.jpg";
                        break;
                }
                if (num > 10 && num < 32) {
                    path = "../sprites/ground/start.png";
                    start = new QPoint((j + 0.5) * SQUARE_SIZE, (i + 0.5) * SQUARE_SIZE);
                    switch (num - 16){
                        case NORTH:
                            start_angle = -90;
                            break;
                        case SOUTH:
                            start_angle = 90;
                            break;
                        case EAST:
                            start_angle = 0;
                            break;
                        case WEST:
                            start_angle = 180;
                            break;
                        case NE:
                            start_angle = -45;
                            break;
                        case SW:
                            start_angle = 135;
                            break;
                        case SE:
                            start_angle = 45;
                            break;
                        case NW:
                            start_angle = -135;
                            break;
                    }
                }
                tiles.insert(num, QPixmap(path));
            }
        }
    }
    file.close();

    wave = new QStringList();
    b1 = new Hatchery(start->x(), start->y(), start_angle);

    QObject::connect(&waveTimer, SIGNAL(timeout()), this, SLOT(nextBug()));
}

Render::~Render()
{
}

void Render::addBug(Bug * bug) {
    QGraphicsScene::addItem(bug);
    bug->parent = this;
}

void Render::drawBackground(QPainter *painter, const QRectF & rect)
{
    for(int i = round(rect.y() / SQUARE_SIZE); i < round((rect.y() + rect.height()) / SQUARE_SIZE); i++)
        for(int j = round(rect.y() / SQUARE_SIZE); j < round((rect.x() + rect.width()) / SQUARE_SIZE); j++) {
            painter->drawPixmap(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, tiles[map[i][j]]);
        }
}

void Render::nextWave()
{
    QFile file("../map/waves_1");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    if (!in.atEnd()) {
        QStringList line;
        for (int i = 0; i < waveNumber; i++)
            line = in.readLine().split(';', QString::SkipEmptyParts);
        if (line.size() >= 2) {
            emit newWaveName(line.at(0));
            line.removeFirst();
            waveTimer.start(line.at(0).split(':').at(3).toInt() * TIMER_INT);
            for (int i = 0; i < line.size(); i++)
                wave->append(line.at(i).split(':', QString::SkipEmptyParts));
        }
        waveNumber += 1;
    }
    file.close();
}

void Render::nextBug()
{
    if (wave->size() > 0) {
        Bug * bug = b1->spawnBug(wave->at(0), wave->at(1).toDouble());
        addBug(bug);
        QObject::connect(bug, SIGNAL(goalReached(Bug*)), this, SLOT(bugFinish(Bug*)));
        QObject::connect(bug, SIGNAL(dead(Bug*)), this, SLOT(bugKilled(Bug*)));
        int bugNumber = wave->at(2).toInt() - 1;
        if (bugNumber == 0) {
            waveTimer.stop();
            wave->removeFirst();
            wave->removeFirst();
            wave->removeFirst();
            wave->removeFirst();
            if (!wave->isEmpty())
                waveTimer.start(wave->at(3).toInt() * TIMER_INT);
            else
                waveTimer.stop();
        }
        else
            wave->replace(2, QString::number(bugNumber));
    } else
        waveTimer.stop();
}

QPoint Render::square(QGraphicsItem & item)
{
    int x = floor(item.x() / SQUARE_SIZE);
    int y = floor(item.y() / SQUARE_SIZE);
    return QPoint(x, y);
}

QPoint Render::goal()
{
    return goalSquare;
}

double Render::getAngle(QPoint & current)
{
    double angle = 0;
    switch (map[current.y()][current.x()]) {
        case NORTH:
            angle = -90;
            break;
        case SOUTH:
            angle = 90;
            break;
        case EAST:
            angle = 0;
            break;
        case WEST:
            angle = 180;
            break;
        case NE:
            angle = -45;
            break;
        case SW:
            angle = 135;
            break;
        case SE:
            angle = 45;
            break;
        case NW:
            angle = -135;
            break;
    }
    return angle;
}

void Render::bugFinish(Bug * bug)
{
    bug->disconnect();
    emit loseLife();
    removeItem(bug);
    bug->deleteLater();
}

void Render::bugKilled(Bug * bug)
{
    bug->disconnect();
    emit getCred();
    removeItem(bug);
    bug->deleteLater();
}

void Render::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (tower2build != "none") {
        QPointF rpos = mouseEvent->scenePos();
        QPoint pos((int) (rpos.x() / SQUARE_SIZE), (int) (rpos.y() / SQUARE_SIZE));
    }
}

void Render::towerBought(QString type)
{
    tower2build = type;
}
