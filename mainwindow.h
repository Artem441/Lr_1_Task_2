#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>

class Square;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static QGraphicsScene* ptr;
    static QGraphicsScene* ScenePtr();
    static void setMainWindow (MainWindow *ptr);
    static MainWindow* getMainWindow();
    MainWindow(QWidget *parent = nullptr);
    void setspinBoxValue(Square* SquareAdress);
    int getspinBoxValue() const;

    ~MainWindow();

signals:
    void on_pushButton_clicked();
private slots:
    void handleButtonClick();
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *MainScene;
    Square *square;
    static MainWindow* mainWindow;
};
#endif // MAINWINDOW_H
