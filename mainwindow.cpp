#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"


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
    connect(ui->AddFigure, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    ui -> horizontalSlider -> setRange(0,360);
    ui->doubleSpinBox_S->setReadOnly(true);
    ui->doubleSpinBox_P->setReadOnly(true);

}

int MainWindow::getspinBoxValue() const
{
    if (Square::SquareAdress && (ui->spinBox)) {
        return ui -> spinBox -> value();
    }
    return -1;
}

void MainWindow::sethorizontalSliderValue(Square *SquareAdress)
{
    if ((ui->spinBox)&&(SquareAdress)) {
        ui->horizontalSlider->setValue(SquareAdress -> getSquareAngle());
    }
}

int MainWindow::gethorizontalSliderValue() const
{
    if (Square::SquareAdress && (ui->horizontalSlider)) {
        return ui -> horizontalSlider -> value();
    }
    return -1;
}

void MainWindow::setValueY(Square *SquareAdress)
{
    if ((SquareAdress) && (ui->spinBox_Y)) {
        ui->spinBox_Y->setValue(SquareAdress -> getY());
        SquareAdress->setY(SquareAdress->getY());
    }
}

int MainWindow::getValueY() const
{
    if ((Square::SquareAdress) && (ui->spinBox_Y)) {
        return ui->spinBox_Y->value();
    }
    return -1;
}

void MainWindow::setValueX(Square *SquareAdress)
{
    if ((SquareAdress) && (ui->spinBox_X)) {
        ui->spinBox_X->setValue(SquareAdress -> getX());
        SquareAdress->setX(SquareAdress->getX());
    }
}

int MainWindow::getValueX() const
{
    if ((Square::SquareAdress) && (ui->spinBox_X)) {
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


void MainWindow::setspinBoxValue(Square* SquareAdress)
{
    if ((ui -> spinBox) && SquareAdress){
        ui -> spinBox -> setValue(SquareAdress -> getSqareSize());
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonClick()
{
    square = new Square;
    square -> setSquareSize(60);
    MainScene -> addItem(square);
    square -> setPos(200,150);
}





void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if (Square::SquareAdress != nullptr) {
        Square::SquareAdress -> setSquareSize(arg1);
        ui -> doubleSpinBox_S -> setValue(Square::SquareAdress->getS());
        ui->doubleSpinBox_S->update();
        ui -> doubleSpinBox_P -> setValue(Square::SquareAdress->getP());
        ui->doubleSpinBox_P->update();
        Square::SquareAdress->update();
    }
}
// сообщение в завтра разобраться с указателем на главное окно и сетереами гетерами для квадрата и спин бокса :)

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (Square::SquareAdress != nullptr) {
        Square::SquareAdress -> setRotation(value);
        Square::SquareAdress -> setSquareAngle(value);
        Square::SquareAdress->update();
    }
}


void MainWindow::on_spinBox_Y_valueChanged(int arg1)
{
    if (Square::SquareAdress != nullptr) {
        Square::SquareAdress->setY(arg1);
        Square::SquareAdress->update();
    }
}


void MainWindow::on_spinBox_X_valueChanged(int arg1)
{
    if (Square::SquareAdress != nullptr) {
        Square::SquareAdress->setX(arg1);
        Square::SquareAdress->update();
    }
}

