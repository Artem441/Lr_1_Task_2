#include "square.h"
#include "mainwindow.h"

Square::Square() {}

Square* Square::SquareAdress = nullptr;
QGraphicsEllipseItem *point = nullptr;
//QGraphicsScene* ptr = MainWindow::ScenePtr();



void Square::GetSquarePointer()
{
    Square::SquareAdress = this;
    Square::isSelected = true;
    update();
}

void Square::SetSize()
{
    RectSize = 60;
}



QRectF Square::boundingRect() const
{
    return QRectF(-(RectSize/2),-(RectSize/2),RectSize,RectSize);
}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //Square::SetSize();
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
    //Q_UNUSED(event);
    //initialPos = scenePos();
    if (event -> button() == Qt::LeftButton) {
        this -> setCursor(QCursor(Qt::ClosedHandCursor));
        if (Square::SquareAdress != nullptr) { // для обнуления при выделении другой фигуры просто проверять статические указатели на все другие объекты
            Square::SquareAdress -> isSelected = false;
            Square::SquareAdress->update();
        }
        this -> GetSquarePointer();
    }
    if (event -> button() == Qt::RightButton) {
        if (point == nullptr) {
            QPointF center = boundingRect().center();
            point = new QGraphicsEllipseItem(
                center.x() - 2.5,
                center.y() - 2.5,
                5,5,
                this
            );
            point -> setBrush(Qt::black);
        }
        else
        {
            QGraphicsScene* ScenePtr = MainWindow::ScenePtr();
            if (ScenePtr)
            {
                ScenePtr->removeItem(point);
                point = nullptr;
                qDebug() << "efsfgsgweg";
                Square::SquareAdress -> update();
            }
        }

    }
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

//переопределить методы мыши так чтобы при нажатии фиксировалась начальное положение и потом при растягивании изменялось




