#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "square.h"
#include "figure.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow *ptr;
    static void setMainWindow (MainWindow *ptr);
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
signals:
    void on_pushButton_clicked();
private slots:
    void handleButtonClick();
    //void DeleteButtonSignal();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *MainScene;
    Square *square;
};
#endif // MAINWINDOW_H
