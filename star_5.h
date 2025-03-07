#ifndef STAR_5_H
#define STAR_5_H

#include "figure.h"

class MAinWindow;

class Star_5 : public Figure
{
public:
    Star_5();
    double getP() override;
    double getS() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // STAR_5_H
