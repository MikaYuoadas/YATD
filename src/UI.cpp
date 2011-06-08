#include <QString>

#include "UI.h"
#include "define.h"

UI::UI(QWidget * parent) : QWidget(parent), selected(NULL)
{
    tower = new QGroupBox("Créer une défense", this);
    tower->setGeometry(0, 120, UI_WIDTH, 180);
    stats = new QGroupBox("Stats", this);
    stats->setGeometry(0, 310, UI_WIDTH, 180);

    start = new QPushButton("Lancer la vague suivante", this);
    start->setGeometry(10, 30, 180, 25);
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(startWave()));
    upg = new QPushButton("Améliorer", stats);
    upg->setGeometry(20, 150, 75, 20);
    sell = new QPushButton("Vendre", stats);
    sell->setGeometry(105, 150, 75, 20);
    QObject::connect(sell, SIGNAL(clicked()), this, SLOT(sellSelectedTower()));

    // Tower shop
    water = new QPushButton("Eau", tower);
    water->setGeometry(10, 25, (UI_WIDTH - 30)/2, 65);
    QObject::connect(water, SIGNAL(clicked()), this, SLOT(buyWaterTower()));
    sling = new QPushButton("Pierres", tower);
    sling->setGeometry((UI_WIDTH - 30)/2 + 20, 25, (UI_WIDTH - 30)/2, 65);
    QObject::connect(sling, SIGNAL(clicked()), this, SLOT(buySlingshotTower()));
    bowling = new QPushButton("Pétanque", tower);
    bowling->setGeometry(10, 100, (UI_WIDTH - 30)/2, 65);
    QObject::connect(bowling, SIGNAL(clicked()), this, SLOT(buyBowlingTower()));
    paintball = new QPushButton("Paintball", tower);
    paintball->setGeometry((UI_WIDTH - 30)/2 + 20, 100, (UI_WIDTH - 30)/2, 65);
    QObject::connect(paintball, SIGNAL(clicked()), this, SLOT(buyPaintballTower()));

    //Tower Stat
    name = new QLabel("type de la tour : ", stats);
    name->setGeometry(5, 15, 100, 20);
    lvl = new QLabel("niveau : ", stats);
    lvl->setGeometry(5, 40, 100, 20);
    range = new QLabel("portée : ", stats);
    range->setGeometry(5, 65, 100, 20);
    firerate = new QLabel("cadence de tir : ", stats);
    firerate->setGeometry(5, 90, 100, 20);

    t_name = new QLabel("test", stats);
    t_name->setGeometry(130, 15, 100, 20);
    t_lvl = new QLabel("test", stats);
    t_lvl->setGeometry(130, 40, 100, 20);
    t_range = new QLabel("test", stats);
    t_range->setGeometry(130, 65, 100, 20);
    t_firerate = new QLabel("test", stats);
    t_firerate->setGeometry(130, 90, 100, 20);

    // Game Stats display
    wave = new QLabel("Wave text here", this);
    wave->setGeometry(0, 5, UI_WIDTH, 20);
    cred_txt = new QLabel("Crédits :", this);
    cred_txt->move(0, 65);
    life_txt = new QLabel("Vies :", this);
    life_txt->move(0, 95);

    cred = new QLCDNumber(this);
    cred->setSegmentStyle(QLCDNumber::Flat);
    cred->move(135, 65);
    cred->display(START_CRED);
    life = new QLCDNumber(this);
    life->setSegmentStyle(QLCDNumber::Flat);
    life->move(135, 95);
    life->display(START_LIFE);
}

void UI::startWave()
{
    emit nextWave();
}

void UI::setWaveName(QString name)
{
    wave->setText(name);
}

void UI::addCred()
{
    cred->display(cred->intValue() + 1);
}

void UI::loseLife()
{
    life->display(life->intValue() - 1);
    if (life->intValue() <= 0)
        emit defeat();
}

void UI::buyWaterTower()
{
    if (cred->intValue() >= WATER_PRICE) {
        cred->display(cred->intValue() - WATER_PRICE);
        emit buyTower(QString("water"));
    }
}

void UI::buySlingshotTower()
{
    if (cred->intValue() >= SLINGSHOT_PRICE) {
        cred->display(cred->intValue() - SLINGSHOT_PRICE);
        emit buyTower(QString("slingshot"));
    }
}

void UI::buyPaintballTower()
{
    if (cred->intValue() >= PAINTBALL_PRICE) {
        cred->display(cred->intValue() - PAINTBALL_PRICE);
        emit buyTower(QString("paintball"));
    }
}

void UI::buyBowlingTower()
{
    if (cred->intValue() >= BOWLING_PRICE) {
        cred->display(cred->intValue() - BOWLING_PRICE);
        emit buyTower(QString("bowling"));
    }
}

void UI::selectTower(Tower * tower)
{
    selected = tower;
    t_name->setText(tower->getType());
    t_lvl->setText(QString().setNum(tower->getLvl()));
    t_range->setText(QString().setNum(tower->getRange()));
    t_firerate->setText(QString().setNum(tower->getFirerate()));
}

void UI::sellSelectedTower()
{
    cred->display(cred->intValue() + (int) selected->getPrice());
    emit towerSold(selected);
    t_name->setText("");
    t_lvl->setText("");
    t_range->setText("");
    t_firerate->setText("");
}
