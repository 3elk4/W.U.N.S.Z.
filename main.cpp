#include "mainwindow.h"
#include <QApplication>
#include <QPainter>

int main(int argc, char *argv[])
{
    qsrand(time(NULL));
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    return a.exec();
}
