#ifndef CIRCLE_H
#define CIRCLE_H

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

class Circle : public Figure
{
public:
    Circle();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // 3 метода для левой кнопки
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // CIRCLE_H

