#include <QApplication>
#include <QGraphicsView>
#include <QMainWindow>
#include <QObject>
#include <QPainter>
#include <QTextCodec>
#include <QTimer>
#include <QString>

#include "define.h"
#include "Render.h"
#include "UI.h"

#include "Ant.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication app(argc, argv);

    QMainWindow window;
    window.setFixedSize(WIDTH + 24 + UI_WIDTH, HEIGHT + 4);

    UI ui(&window);
    ui.setGeometry(WIDTH + 10, 0, UI_WIDTH, HEIGHT);

    Render render;
    render.setSceneRect(0, 0, WIDTH, HEIGHT);
    render.setItemIndexMethod(QGraphicsScene::NoIndex);

    QGraphicsView view(&render, &window);
    view.setGeometry(0, 0, WIDTH + 4, HEIGHT + 4);

    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::NoDrag);

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &render, SLOT(advance()));
    timer.start(TIMER_INT);

    QObject::connect(ui.start, SIGNAL(clicked()), &render, SLOT(nextWave()));
    QObject::connect(&render, SIGNAL(newWaveName(QString)), &ui, SLOT(setWaveName(QString)));

    window.show();
    return app.exec();
}
