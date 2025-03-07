#include "star_8.h"
#include "mainwindow.h"

Star_8::Star_8() {}

double Star_8::getP()
{

}

double Star_8::getS()
{

}

QRectF Star_8::boundingRect() const
{
    return QRectF(-FigureSize/2,-FigureSize/2,FigureSize,FigureSize);
}

void Star_8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen(Qt::darkCyan, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    QPointF points[16] = {
        QPointF(-0.5*FigureSize, 0),
        QPointF(-0.3*FigureSize, -0.125*FigureSize),
        QPointF(-0.35*FigureSize, -0.35*FigureSize),
        QPointF(-0.125*FigureSize, -0.3*FigureSize),
        QPointF(0, -0.5*FigureSize),
        QPointF(0.125*FigureSize, -0.3*FigureSize),
        QPointF(0.35*FigureSize, -0.35*FigureSize),
        QPointF(0.3*FigureSize, -0.125*FigureSize),
        QPointF(0.5*FigureSize, 0),
        QPointF(0.3*FigureSize, 0.125*FigureSize),
        QPointF(0.35*FigureSize, 0.35*FigureSize),
        QPointF(0.125*FigureSize, 0.3*FigureSize),
        QPointF(0, 0.5*FigureSize),
        QPointF(-0.125*FigureSize, 0.3*FigureSize),
        QPointF(-0.35*FigureSize, 0.35*FigureSize),
        QPointF(-0.3*FigureSize, 0.125*FigureSize),
    };
    painter->drawPolygon(points, 16);
    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::darkBlue);
        painter->drawPolygon(points,16);
        //painter->setBrush(Qt::NoBrush);
        //painter->drawPolygon(boundingRect());
    }
}

void Star_8::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(Figure::FigureAdress);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Star_8::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void Star_8::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
