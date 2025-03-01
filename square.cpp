#include "square.h"
#include "mainwindow.h"

Square::Square() {}

Square* Square::SquareAdress = nullptr;

void Square::GetSquarePointer()
{
    Square::SquareAdress = this;
    Square::isSelected = true;
    update();
}



QRectF Square::boundingRect() const
{
    return QRectF(-25,-25,50,50);
}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(Qt::darkCyan, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::blue);
    painter->drawRect(boundingRect());

    if (isSelected == true) {
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
    if (Square::SquareAdress != nullptr) {
        Square::SquareAdress -> isSelected = false;
        Square::SquareAdress->update();
    }
    this -> GetSquarePointer();
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

//переопределить методы мыши так чтобы при нажатии фиксировалась начальное положение и потом при растягивании изменялось




