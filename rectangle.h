#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"


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

class Rectangle : public Figure
{
public:
    Rectangle();

    double getP() override;
    double getS() override;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // 3 метода для левой кнопки
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // RECTANGLE_H
