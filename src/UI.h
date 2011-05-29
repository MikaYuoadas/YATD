#ifndef Ui
#define Ui

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QString>

class UI : public QWidget
{
    Q_OBJECT

    private:
        QGroupBox *tower;
        QGroupBox *stats;
        QPushButton *sell;
        QPushButton *upg;
        QLabel * wave;
        QLabel * cred_txt;
        QLabel * life_txt;
        QLCDNumber * cred;
        QLCDNumber * life;

    public:
        QPushButton *start;
        UI(QWidget * parent);

    public slots:
        void setWaveName(QString name);
        void addCred();
        void loseLife();
};
#endif
