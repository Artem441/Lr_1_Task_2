#include "ellipse.h"
#include "mainwindow.h"
#include <cmath>

Ellipse::Ellipse() {}

double Ellipse::getP()
{
    return (4.0 / ((FigureSize/2.0) + (FigureSize/4.0))) * (((FigureSize/2.0) * (FigureSize/4.0) * 3.14)  + (FigureSize/2.0 - FigureSize/4.0));
}

double Ellipse::getS()
{
    return (3.14*FigureSize/2*FigureSize/4);
}

QRectF Ellipse::boundingRect() const
{
    return QRectF(-(FigureSize/2),(-FigureSize/4),FigureSize,FigureSize/2);
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen(Qt::darkBlue, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    painter -> drawEllipse(-(FigureSize/2),(-FigureSize/4),FigureSize,FigureSize/2);
    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::darkBlue);
        painter -> drawEllipse(-(FigureSize/2),(-FigureSize/4),FigureSize,FigureSize/2);
    }
}

void Ellipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(figure);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Ellipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    MainWindow* mainWindow = MainWindow::getMainWindow();
    if (event -> button() == Qt::LeftButton) {
        this -> setCursor(QCursor(Qt::ClosedHandCursor));
        if (Figure::FigureAdress != nullptr) {
            Figure::FigureAdress -> isSelected = false;
            Figure::FigureAdress->update();
        }
        this -> Figure::getFigurePointer();
        figure = Figure::FigureAdress;
        mainWindow -> setspinBoxValue(figure);
        mainWindow -> sethorizontalSliderValue(figure);
        mainWindow -> setValueY(figure);
        mainWindow -> setValueX(figure);
        mainWindow->updateS(getS());
        mainWindow->updateP(getP());



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
                Figure::FigureAdress -> update();
            }
        }

    }
}

void Ellipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
