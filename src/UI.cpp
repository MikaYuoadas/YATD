#include <QString>

#include "UI.h"
#include "define.h"

UI::UI(QWidget * parent) : QWidget(parent)
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
    //TODO : défaite si life <= 0
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
