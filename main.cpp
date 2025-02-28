#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MainWindow::setMainWindow(&w);
    return a.exec();
}
// сеттре и геттер от суда setter а из gettera(в потомках), а сеттер тут поставить

