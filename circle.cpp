#include "circle.h"
#include "mainwindow.h"

Circle::Circle() {}

//QGraphicsEllipseItem *point = nullptr;

QRectF Circle::boundingRect() const
{
    return QRectF(-(FigureSize/2),(-FigureSize/2),FigureSize,FigureSize);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen(Qt::darkBlue, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    painter -> drawEllipse(-(FigureSize/2),(-FigureSize/2),FigureSize,FigureSize);
    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(-(FigureSize/2),(-FigureSize/2),FigureSize,FigureSize);
    }

}

void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(figure);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Q_UNUSED(event);
    //initialPos = scenePos();
    MainWindow* mainWindow = MainWindow::getMainWindow();
    if (event -> button() == Qt::LeftButton) {
        this -> setCursor(QCursor(Qt::ClosedHandCursor));
        if (Figure::FigureAdress != nullptr) { // для обнуления при выделении другой фигуры просто проверять статические указатели на все другие объекты
            Figure::FigureAdress -> isSelected = false;
            Figure::FigureAdress->update();
        }
        this -> Figure::getFigurePointer();
        figure = Figure::FigureAdress;
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


void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
