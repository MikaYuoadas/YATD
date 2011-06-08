#ifndef Ui
#define Ui

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QString>

#include "Tower.h"

class UI : public QWidget
{
    Q_OBJECT

    private:
        QGroupBox * tower;
        QGroupBox * stats;
        QPushButton * sell;
        QPushButton * upg;
        QPushButton * water;
        QPushButton * sling;
        QPushButton * bowling;
        QPushButton * paintball;
        QLabel * name;
        QLabel * lvl;
        QLabel * range;
        QLabel * firerate;
        QLabel * t_name;
        QLabel * t_lvl;
        QLabel * t_range;
        QLabel * t_firerate;
        QLabel * wave;
        QLabel * cred_txt;
        QLabel * life_txt;
        QLCDNumber * cred;
        QLCDNumber * life;
        Tower * selected;

    public:
        QPushButton *start;
        UI(QWidget * parent);

    public slots:
        void setWaveName(QString name);
        void addCred();
        void loseLife();
        void startWave();
        void buyWaterTower();
        void buySlingshotTower();
        void buyPaintballTower();
        void buyBowlingTower();
        void selectTower(Tower * tower);
        void sellSelectedTower();

    signals:
        void buyTower(QString type);
        void nextWave();
        void towerSold(Tower * tower);
        void defeat();
};
#endif
