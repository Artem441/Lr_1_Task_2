#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>

class Square;
class Circle;
class Figure;

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
    void setspinBoxValue(Figure* FigureAdress);
    int getspinBoxValue() const;
    void sethorizontalSliderValue(Figure* FigureAdress);
    int gethorizontalSliderValue() const;
    void setValueY(Figure* FigureAdress);
    int getValueY() const;
    void setValueX(Figure* FigureAdress);
    int getValueX() const;
    void updateS(double s);
    void updateP(double p);

    ~MainWindow();

signals:
    void on_pushButton_clicked();
private slots:
    void handleButtonClick();
    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_Y_valueChanged(int arg1);

    void on_spinBox_X_valueChanged(int arg1);

    void on_DeleteFigure_clicked();

    void on_AddCircle_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *MainScene;
    Square *square;
    Circle *circle;

    static MainWindow* mainWindow;
};
#endif // MAINWINDOW_H
