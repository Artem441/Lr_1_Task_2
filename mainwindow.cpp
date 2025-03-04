#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"
#include "circle.h"


MainWindow* MainWindow::mainWindow = nullptr;

QGraphicsScene* MainWindow::ScenePtr()
{
    return ptr;
}

void MainWindow::setMainWindow(MainWindow *ptr)
{
    mainWindow = ptr;
}

MainWindow *MainWindow::getMainWindow()
{
    return mainWindow;
}
QGraphicsScene* MainWindow::ptr = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> resize(1065,865);
    this -> setFixedSize(1065,865);
    MainScene = new QGraphicsScene;
    ptr = MainScene;
    MainScene -> setSceneRect(0,0,500,610);
    ui->graphicsView->setScene(MainScene);
    connect(ui->AddSquare, &QPushButton::clicked, this, &MainWindow::handleButtonClick); // создание квадрата через конопку
    ui -> horizontalSlider -> setRange(0,360);
    ui->doubleSpinBox_S->setReadOnly(true);
    ui->doubleSpinBox_P->setReadOnly(true);

}

int MainWindow::getspinBoxValue() const
{
    if (Figure::FigureAdress && (ui->spinBox)) {
        return ui -> spinBox -> value();
    }
    return -1;
}

void MainWindow::sethorizontalSliderValue(Figure* FigureAdress)
{
    if ((ui->spinBox)&&(FigureAdress)) {
        ui->horizontalSlider->setValue(FigureAdress -> getFigureAngle());
    }
}


int MainWindow::gethorizontalSliderValue() const
{
    if (Figure::FigureAdress && (ui->horizontalSlider)) {
        return ui -> horizontalSlider -> value();
    }
    return -1;
}

void MainWindow::setValueY(Figure* FigureAdress)
{
    if ((FigureAdress) && (ui->spinBox_Y)) {
        ui->spinBox_Y->setValue(FigureAdress -> getY());
        FigureAdress->setY(FigureAdress->getY());
    }
}

int MainWindow::getValueY() const
{
    if ((Figure::FigureAdress) && (ui->spinBox_Y)) {
        return ui->spinBox_Y->value();
    }
    return -1;
}

void MainWindow::setValueX(Figure* FigureAdress)
{
    if ((FigureAdress) && (ui->spinBox_X)) {
        ui->spinBox_X->setValue(FigureAdress -> getX());
        FigureAdress->setX(FigureAdress->getX());
    }
}

int MainWindow::getValueX() const
{
    if ((Figure::FigureAdress) && (ui->spinBox_X)) {
        return ui->spinBox_X->value();
    }
    return -1;
}

void MainWindow::updateS(double s)
{
    ui->doubleSpinBox_S->setValue(s);
    ui->doubleSpinBox_S->update();
}

void MainWindow::updateP(double p)
{
    ui->doubleSpinBox_P->setValue(p);
    ui->doubleSpinBox_P->update();
}


void MainWindow::setspinBoxValue(Figure* FigureAdress)
{
    if ((ui -> spinBox) && FigureAdress){
        ui -> spinBox -> setValue(FigureAdress -> getFigureSize());
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonClick()
{
    square = new Square;
    square -> setFigureSize(60);
    MainScene -> addItem(square);
    square -> setPos(200,150);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if (Figure::FigureAdress != nullptr) {
        Figure::FigureAdress -> setFigureSize(arg1);
        ui -> doubleSpinBox_S -> setValue(Figure::FigureAdress->getS());
        ui->doubleSpinBox_S->update();
        ui -> doubleSpinBox_P -> setValue(Figure::FigureAdress->getP());
        ui->doubleSpinBox_P->update();
        Figure::FigureAdress->update();
        MainScene -> invalidate(); // чтобы не было оставшегося жмыха
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (Figure::FigureAdress != nullptr) {
        Figure::FigureAdress -> setRotation(value);
        Figure::FigureAdress -> setFigureAngle(value);
        Figure::FigureAdress->update();
    }
}


void MainWindow::on_spinBox_Y_valueChanged(int arg1)
{
    if (Figure::FigureAdress != nullptr) {
        Figure::FigureAdress->setY(arg1);
        Figure::FigureAdress->update();
    }
}


void MainWindow::on_spinBox_X_valueChanged(int arg1)
{
    if (Figure::FigureAdress != nullptr) {
        Figure::FigureAdress->setX(arg1);
        Figure::FigureAdress->update();
    }
}


void MainWindow::on_DeleteFigure_clicked()
{
    if (Figure::FigureAdress != nullptr) {
        MainScene -> removeItem(Figure::FigureAdress);
        Figure::FigureAdress = nullptr;
    }
}

void MainWindow::on_AddCircle_clicked()
{
    circle = new Circle;
    circle -> setFigureSize(70);
    MainScene -> addItem(circle);
    circle -> setPos(250,150);
}


