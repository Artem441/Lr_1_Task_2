#include "mainwindow.h"
#include "ui_mainwindow.h"


QGraphicsScene* MainWindow::ScenePtr()
{
    return ptr;
}
QGraphicsScene* MainWindow::ptr = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> resize(1020,830);
    this -> setFixedSize(1020,830);
    MainScene = new QGraphicsScene;
    ptr = MainScene;
    MainScene -> setSceneRect(0,0,500,610);
    ui->graphicsView->setScene(MainScene);
    connect(ui->AddFigure, &QPushButton::clicked, this, &MainWindow::handleButtonClick);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonClick()
{
    square = new Square;
    square -> SetSize();
    MainScene -> addItem(square);
    square -> setPos(200,150);
}

