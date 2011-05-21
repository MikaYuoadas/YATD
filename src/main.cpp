#include <QMainWindow>
#include <QApplication>
#include <QTextCodec>
#include "define.h"
#include "Render.h"
#include "UI.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication app(argc, argv);

    QMainWindow window;
    window.setFixedSize(WIDTH + 20 + UI_WIDTH, HEIGHT);

    Render render(&window);
    render.setGeometry(0, 0, WIDTH, HEIGHT);
    UI ui(&window);
    ui.setGeometry(WIDTH + 10, 0, UI_WIDTH, HEIGHT);

    window.show();
    return app.exec();
}
