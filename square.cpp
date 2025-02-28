#include "square.h"

Square::Square() {}

void Square::GetSquarePointer()
{
    Square *SquareAdress = this;
    isSelected = true;
    update();
    qDebug() << SquareAdress;
}



QRectF Square::boundingRect() const
{
    return QRectF(-25,-25,50,50);
}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (isSelected == false) {
        QPen pen(Qt::darkCyan, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::blue);
        painter->drawRect(boundingRect());
    }
    else {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter -> setBrush(Qt::blue);
        painter->drawRect(boundingRect());
    }

}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    //initialPos = scenePos();
    this -> setCursor(QCursor(Qt::ClosedHandCursor));
    this -> GetSquarePointer();



}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

//переопределить методы мыши так чтобы при нажатии фиксировалась начальное положение и потом при растягивании изменялось




