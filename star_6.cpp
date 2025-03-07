#include "star_6.h"
#include "mainwindow.h"

Star_6::Star_6() {}

double Star_6::getP()
{
    return 3.5 * FigureSize;
}

double Star_6::getS()
{
    return 0.65*FigureSize*FigureSize;
}

QRectF Star_6::boundingRect() const
{
    return QRectF(-FigureSize/2,-FigureSize/2,FigureSize,FigureSize);
}

void Star_6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen(Qt::darkCyan, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    QPointF points[12] = {
        QPointF(-FigureSize/5,0),
        QPointF(-FigureSize /2, -0.25*FigureSize),
        QPointF(-FigureSize/10, -0.15*FigureSize),
        QPointF(0, -0.5*FigureSize),
        QPointF(0.1*FigureSize, -0.15*FigureSize),
        QPointF(0.5*FigureSize, -0.25*FigureSize),
        QPointF(0.2*FigureSize, 0),
        QPointF(0.5*FigureSize, 0.25*FigureSize),
        QPointF(0.1*FigureSize, 0.15*FigureSize),
        QPointF(0, 0.5*FigureSize),
        QPointF(-FigureSize/10, 0.15*FigureSize),
        QPointF(-FigureSize /2, 0.25*FigureSize),
    };
    painter->drawPolygon(points, 12);
    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::darkBlue);
        painter->drawPolygon(points,12);
        //painter->setBrush(Qt::NoBrush);
        //painter->drawPolygon(boundingRect());
    }
}

void Star_6::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(Figure::FigureAdress);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Star_6::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void Star_6::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
