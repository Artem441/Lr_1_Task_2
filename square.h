#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"
//#include "mainwindow.h"

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QDoubleSpinBox>

class MainWindow;

class Square : public Figure
{
public:
    Square();
    QGraphicsScene *ptr;
    static Square* SquareAdress;
    QGraphicsEllipseItem *point;
    void GetSquarePointer(); // функция взятия адресса квадрата
    void setSquareSize(int size);
    void setSquareAngle(int angle);
    void setY(int y);
    void setX(int x);
    int getSqareSize();
    int getSquareAngle();
    int getY();
    int getX();
    double getP();
    double getS();
    void setS(double s);
    void setP(double p);

    void setMainWindow(MainWindow* mainWindow);



protected:
    QRectF boundingRect() const override;
    int X;
    int Y;
    int RectSize; // размер квадрата
    int RectAngle; // угол поворота
    double S;
    double P;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // 3 метода для левой кнопки
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QMouseEvent);
    QPen pen;
private:
    bool isSelected = false; // обработка
    MainWindow* mainWindow;
    Square* square;
    QDoubleSpinBox *spinBoxS;



public slots:

};

#endif // SQUARE_H
