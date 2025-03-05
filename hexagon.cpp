#include "hexagon.h"
#include "mainwindow.h"
#include <cmath>

Hexagon::Hexagon() {}

double Hexagon::getP()
{
    return 6*FigureSize;
}

double Hexagon::getS()
{
    return pow(FigureSize,2) * sqrt(3) / 2.0 * 3.0;
}

QRectF Hexagon::boundingRect() const
{
    return QRectF(-(FigureSize/2),-(FigureSize/4),FigureSize,FigureSize/2);
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //Square::SetSize();
    QPen pen(Qt::darkCyan, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    QPointF points[6] = {
        QPointF(-FigureSize/2, 0),
        QPointF(-FigureSize/4, -FigureSize/4),
        QPointF(FigureSize/4, -FigureSize/4),
        QPointF(FigureSize/2, 0),
        QPointF(FigureSize/4, FigureSize/4),
        QPointF(-FigureSize/4, FigureSize/4),
    };
    painter->drawPolygon(points, 6);

    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::darkBlue);
        painter->drawPolygon(points,6);
    }
}

void Hexagon::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(Figure::FigureAdress);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    MainWindow* mainWindow = MainWindow::getMainWindow();
    if (event -> button() == Qt::LeftButton) {
        this -> setCursor(QCursor(Qt::ClosedHandCursor));
        if (Figure::FigureAdress != nullptr) { // для обнуления при выделении другой фигуры просто проверять статические указатели на все другие объекты
            Figure::FigureAdress -> isSelected = false;
            Figure::FigureAdress->update();
        }
        this->getFigurePointer();
        figure = Figure::FigureAdress; // нужен объект нельзя через ссылку вызывать
        mainWindow -> setspinBoxValue(figure); // обновляю значение спин бокса для нового тела
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

void Hexagon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
