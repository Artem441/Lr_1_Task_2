#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"



#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEllipseItem>

class Square : public Figure
{
public:
    Square();
    QGraphicsScene *ptr;
    static Square* SquareAdress;
    QGraphicsEllipseItem *point;
    void GetSquarePointer(); // функция взятия адресса квадрата
    void SetSize();


protected:
    QRectF boundingRect() const override;
    double RectSize; // размер квадрата
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // 3 метода для левой кнопки
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QMouseEvent);
    QPen pen;
private:
    bool isSelected = false; // обработка

public slots:

};

#endif // SQUARE_H
