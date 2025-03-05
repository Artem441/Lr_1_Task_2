
#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class MainWindow;

class Rhombus : public Figure
{
public:
    Rhombus();
    double getP() override;
    double getS() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // RHOMBUS_H
