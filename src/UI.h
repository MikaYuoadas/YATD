#ifndef Ui
#define Ui
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>

class UI : public QWidget
{
    private:
        QGroupBox *tower;
        QGroupBox *stats;
        QPushButton *start;
        QPushButton *sell;
        QPushButton *upg;
        QLabel * wave;
        QLabel * cred_txt;
        QLabel * life_txt;
        QLCDNumber * cred;
        QLCDNumber * life;
    public:
        UI(QWidget * parent);
};
#endif
