#ifndef RENDER
#define RENDER
#include <QWidget>
#include <QLabel>
#include "define.h"

class Render : public QWidget
{
    private:
        QLabel * tiles[COLUMN][ROW];
    public:
        Render(QWidget * parent = 0);
};
#endif
