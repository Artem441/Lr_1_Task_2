#ifndef FIGURE_H
#define FIGURE_H

#include <QQuickItem>
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

class Figure : public QGraphicsItem

{
public:
    Figure();
    QGraphicsScene *ptr;
    QGraphicsEllipseItem *point;
    virtual void draw(QPainter *painter);
    virtual void setFigureSize(int size); // general
    virtual void setFigureAngle(int angle); // general
    virtual void setY(int y); // general
    virtual void setX(int x); // general
    virtual int getFigureSize();  // general
    virtual int getFigureAngle(); // general
    virtual double getY(); // general
    virtual double getX(); // general
    virtual double getP();
    virtual double getS();
    virtual void setS(double s); // general
    virtual void setP(double p); // general
    virtual void getFigurePointer(); // general

    static Figure* FigureAdress;

    int X;
    int Y;
    int FigureSize;
    int FigureAngle;
    double S;
    double P;
    bool isSelected;



protected:
    Figure* figure;
    QRectF boundingRect() const override;
    QPen pen;
    MainWindow* mainWindow;
    QDoubleSpinBox *spinBoxS;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // 3 метода для левой кнопки
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    //virtual void mousePressEvent(QMouseEvent);
};

#endif // FIGURE_H

