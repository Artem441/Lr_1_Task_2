#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class MainWindow;

class Triangle : public Figure
{
public:
    Triangle();
    double getP() override;
    double getS() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // TRIANGLE_H
