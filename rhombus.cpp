#include "rhombus.h"
#include "mainwindow.h"

Rhombus::Rhombus() {}

//QGraphicsEllipseItem *point = nullptr;

double Rhombus::getP()
{
    return 4*FigureSize;
}

double Rhombus::getS()
{
    return FigureSize*FigureSize/2.0;
}

QRectF Rhombus::boundingRect() const
{
    return QRectF(-FigureSize / 2, -FigureSize / 4, FigureSize, FigureSize / 2);
}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //Square::SetSize();
    QPen pen(Qt::darkCyan, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    QPointF points[4] = {
        QPointF(FigureSize/2.0, 0.0),
        QPointF(0.0, FigureSize/4.0),
        QPointF(-FigureSize/2.0, 0.0),
        QPointF(0.0, -FigureSize/4.0)
    };
    painter->drawPolygon(points, 4);


    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::darkBlue);
        painter->drawPolygon(points,4);
    }
}

void Rhombus::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(Figure::FigureAdress);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Rhombus::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void Rhombus::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

