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

}

int MainWindow::getspinBoxValue() const
{
    if (Square::SquareAdress && (ui->spinBox)) {
        return ui -> spinBox -> value();
    }
    return -1;
}

void MainWindow::setspinBoxValue(Square* SquareAdress)
{
    if ((ui -> spinBox) && SquareAdress){
        ui -> spinBox -> setValue(Square::SquareAdress -> getSqareSize());
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
        Square::SquareAdress->update();
    }
}
// сообщение в завтра разобраться с указателем на главное окно и сетереами гетерами для квадрата и спин бокса :)
