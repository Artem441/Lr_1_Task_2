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

class Square : public Figure
{
public:
    Square();
    static Square* SquareAdress;
    //void onSquareSelected(Square* selectedSquare);
    void GetSquarePointer(); // функция взятия адресса квадрата
    //void highlight(bool enable);
    //void deselect();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QPen pen;
private:
//QPointF initialPos;
    //double RectSize;
    bool isSelected = false;

public slots:

};

#endif // SQUARE_H
