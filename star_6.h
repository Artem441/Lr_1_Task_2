#ifndef STAR_6_H
#define STAR_6_H

#include "figure.h"

class MainWindow;

class Star_6 : public Figure
{
public:
    Star_6();
    double getP() override;
    double getS() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // STAR_6_H
