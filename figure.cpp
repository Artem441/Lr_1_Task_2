#include "figure.h"

Figure::Figure() {}

Figure* Figure::FigureAdress = nullptr;

void Figure::draw(QPainter *painter)
{
    Q_UNUSED(painter);
}

int Figure::getFigureSize()
{
    return FigureSize;
}

void Figure::setFigureSize(int size)
{
    FigureSize = size;
    update();
}

void Figure::setFigureAngle(int angle)
{
    FigureAngle = angle;
    update();
}

void Figure::setY(int y)
{
    setPos(Figure::FigureAdress->x(), y);
    update();
}

void Figure::setX(int x)
{
    setPos(x ,Figure::FigureAdress->y());
    update();
}

int Figure::getFigureAngle()
{
    return FigureAngle;
}

double Figure::getY()
{
    return Figure::FigureAdress-> y();
}

double Figure::getX()
{
    return Figure::FigureAdress-> x();
}

double Figure::getP()
{
    return 0;
}

double Figure::getS()
{
    return 0;
}

void Figure::setS(double s)
{
    Figure::FigureAdress->S = s;
    Figure::FigureAdress->update();
}

void Figure::setP(double p)
{
    Figure::FigureAdress->P = p;
    Figure::FigureAdress->update();
}

void Figure::getFigurePointer() // полиморфизм
{
    Figure::FigureAdress = this;
    Figure::isSelected = true;
    update();
}

QRectF Figure::boundingRect() const
{
    return QRectF(0,0,1,1);
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}



