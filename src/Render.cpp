#include <QPixmap>
#include "Render.h"

Render::Render(QWidget * parent) : QWidget(parent)
{
    for(int i = 0; i < COLUMN; i++)
        for(int j = 0; j < ROW; j++) {
            tiles[i][j] = new QLabel(this);
            tiles[i][j]->setPixmap(QPixmap("../sprites/ground/grass.jpg"));
            tiles[i][j]->move(i * SQUARE_SIZE, j * SQUARE_SIZE);
        }
}
