#ifndef STAR_8_H
#define STAR_8_H

#include "figure.h"

class MainWindow;

class Star_8 : public Figure
{
public:
    Star_8();
    double getP() override;
    double getS() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // STAR_8_H
