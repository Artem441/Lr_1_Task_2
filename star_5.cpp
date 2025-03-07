#include "star_5.h"
#include "mainwindow.h"

Star_5::Star_5() {}

double Star_5::getP()
{
    return 5.806 * FigureSize;
}

double Star_5::getS()
{
    return 0.454 * FigureSize * FigureSize;
}

QRectF Star_5::boundingRect() const
{
    return QRectF(-FigureSize,-FigureSize,2 * FigureSize, 2 * FigureSize* 0.93);
}

void Star_5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //Square::SetSize();
    QPen pen(Qt::darkCyan, 1);
    painter->setPen(pen);
    painter -> setBrush(Qt::darkMagenta);
    QPointF points[10] = {
        QPointF(-FigureSize, -0.325*FigureSize),
        QPointF(-FigureSize * 0.225, -0.325*FigureSize),
        QPointF(0, -FigureSize),
        QPointF(FigureSize * 0.225, -0.325*FigureSize),
        QPointF(FigureSize, -0.325*FigureSize),
        QPointF(0.375*FigureSize, 0.125*FigureSize),
        QPointF(0.625*FigureSize, 0.85*FigureSize),
        QPointF(0, 0.4*FigureSize),
        QPointF(-0.625*FigureSize, 0.85*FigureSize),
        QPointF(-0.375*FigureSize, 0.125*FigureSize),
    };
    painter->drawPolygon(points, 10);
    if (isSelected == true) {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter -> setBrush(Qt::darkBlue);
        painter->drawPolygon(points,10);

    }
}

void Star_5::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setPos(mapToScene(event -> pos()));
    MainWindow* mainWindow = MainWindow::getMainWindow();
    mainWindow -> sethorizontalSliderValue(Figure::FigureAdress);
    mainWindow->setValueY(Figure::FigureAdress);
    mainWindow->setValueX(Figure::FigureAdress);
}

void Star_5::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void Star_5::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this -> setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
