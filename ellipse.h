#ifndef ELLIPSE_H
#define ELLIPSE_H

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

class Ellipse : public Figure
{
public:
    Ellipse();
    double getP() override;
    double getS() override;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // 3 метода для левой кнопки
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // ELLIPSE_H
