#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QList>
#include <cmath>

#include "Render.h"
#include "define.h"
#include "Hatchery.h"

Render::Render() : QGraphicsScene(), start_angle(0), waveNumber(1), tower2build(QString("none")), bugs(QList<Bug *>())
{
    QFile file("./map/map_1");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    for (int i = 0; i < ROW && !in.atEnd(); i++) {
        QStringList line = in.readLine().split(" ", QString::SkipEmptyParts);
        for (int j = 0; j < COLUMN && j < line.size(); j++) {
            int num = line.at(j).toInt();
            map[i][j] = num;
            towers[i][j] = NULL;
            if (!tiles.contains(num)) {
                QString path;
                switch (num){
                    case NORTH:
                    case SOUTH:
                        path = "./sprites/ground/trail_NS.jpg";
                        break;
                    case EAST:
                    case WEST:
                        path = "./sprites/ground/trail_EW.jpg";
                        break;
                    case NE:
                    case SW:
                        path = "./sprites/ground/trail_NE-SW.jpg";
                        break;
                    case SE:
                    case NW:
                        path = "./sprites/ground/trail_NW-SE.jpg";
                        break;
                    case GOAL:
                        path = "./sprites/ground/goal.png";
                        goalSquare = QPoint(j, i);
                        break;
                    case DIRT:
                        path = "./sprites/ground/dirt.png";
                        break;
                    default:
                        path = "./sprites/ground/grass.jpg";
                        break;
                }
                if (num > 10 && num < 32) {
                    path = "./sprites/ground/start.png";
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
    bugs.append(bug);
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
    QFile file("./map/waves_1");
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
    bugs.removeAll(bug);
    bug->disconnect();
    emit loseLife();
    removeItem(bug);
    bug->deleteLater();
}

void Render::bugKilled(Bug * bug)
{
    bugs.removeAll(bug);
    bug->disconnect();
    emit getCred();
    removeItem(bug);
    bug->deleteLater();
}

void Render::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QPointF rpos = mouseEvent->scenePos();
    int x = (int) (rpos.x() / SQUARE_SIZE);
    int y = (int) (rpos.y() / SQUARE_SIZE);
    QPoint pos(x, y);
    rpos.rx() = (x + 0.5) * SQUARE_SIZE;
    rpos.ry() = (y + 0.5) * SQUARE_SIZE;
    if (tower2build != "none" && map[pos.y()][pos.x()] == FREE && towers[pos.y()][pos.x()] == NULL) {
        Tower * tower = new Tower(rpos, tower2build);
        towers[pos.y()][pos.x()] = tower;
        tower->parent = this;
        addItem(tower);
        QObject::connect(tower, SIGNAL(projectile(Projectile *)), this, SLOT(addProjectile(Projectile *)));
        tower2build = "none";
    } else if (towers[pos.y()][pos.x()] != NULL) {
        Tower * tower = towers[pos.y()][pos.x()];
        emit selectTower(tower);
    }
}

void Render::towerBought(QString type)
{
    tower2build = type;
}

void Render::addProjectile(Projectile * missile)
{
    QObject::connect(missile, SIGNAL(explode(Projectile *)), this, SLOT(explodingProjectile(Projectile *)));
    addItem(missile);
}

Bug * Render::getTarget(QPointF pos, double range, short int targetType)
{
    Bug * bug = NULL;
    for (int i = 0; i < bugs.size(); i++) {
        double x = bugs.at(i)->x();
        double y = bugs.at(i)->y();
        short int move = bugs.at(i)->getMoveType();
        if (sqrt(pow(x - pos.x(), 2) + pow(y - pos.y(), 2)) <= range * SQUARE_SIZE and move & targetType) {
            bug = bugs.at(i);
            break;
        }
    }
    return bug;
}

void Render::destroyTower(Tower * tower)
{
    tower->disconnect();
    removeItem(tower);
    tower->deleteLater();
}

void Render::explodingProjectile(Projectile * missile)
{
    missile->disconnect();
    removeItem(missile);
    missile->deleteLater();
}
