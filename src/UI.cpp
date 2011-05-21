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
    upg = new QPushButton("Améliorer", stats);
    upg->setGeometry(20, 150, 75, 20);
    sell = new QPushButton("Vendre", stats);
    sell->setGeometry(105, 150, 75, 20);

    wave = new QLabel("Wave text here", this);
    wave->move(0, 5);
    cred_txt = new QLabel("Crédits :", this);
    cred_txt->move(0, 65);
    life_txt = new QLabel("Vies :", this);
    life_txt->move(0, 95);

    cred = new QLCDNumber(this);
    cred->setSegmentStyle(QLCDNumber::Flat);
    cred->move(135, 65);
    life = new QLCDNumber(this);
    life->setSegmentStyle(QLCDNumber::Flat);
    life->move(135, 95);
}
