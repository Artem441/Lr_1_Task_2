/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *AddStar_5;
    QPushButton *AddStar_6;
    QPushButton *AddHexagon;
    QPushButton *AddSquare;
    QPushButton *AddCircle;
    QPushButton *AddEllipse;
    QPushButton *AddRhombus;
    QPushButton *AddRectangle;
    QPushButton *AddTriangle;
    QPushButton *AddStar_8;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *DeleteFigure;
    QSpinBox *spinBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSpinBox *spinBox_Y;
    QSpinBox *spinBox_X;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_S;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_P;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1082, 771);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 90, 830, 620));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(890, 300, 158, 401));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        AddStar_5 = new QPushButton(groupBox);
        AddStar_5->setObjectName("AddStar_5");

        gridLayout->addWidget(AddStar_5, 7, 0, 1, 1);

        AddStar_6 = new QPushButton(groupBox);
        AddStar_6->setObjectName("AddStar_6");

        gridLayout->addWidget(AddStar_6, 8, 0, 1, 1);

        AddHexagon = new QPushButton(groupBox);
        AddHexagon->setObjectName("AddHexagon");

        gridLayout->addWidget(AddHexagon, 6, 0, 1, 1);

        AddSquare = new QPushButton(groupBox);
        AddSquare->setObjectName("AddSquare");

        gridLayout->addWidget(AddSquare, 0, 0, 1, 1);

        AddCircle = new QPushButton(groupBox);
        AddCircle->setObjectName("AddCircle");

        gridLayout->addWidget(AddCircle, 3, 0, 1, 1);

        AddEllipse = new QPushButton(groupBox);
        AddEllipse->setObjectName("AddEllipse");

        gridLayout->addWidget(AddEllipse, 2, 0, 1, 1);

        AddRhombus = new QPushButton(groupBox);
        AddRhombus->setObjectName("AddRhombus");

        gridLayout->addWidget(AddRhombus, 4, 0, 1, 1);

        AddRectangle = new QPushButton(groupBox);
        AddRectangle->setObjectName("AddRectangle");

        gridLayout->addWidget(AddRectangle, 1, 0, 1, 1);

        AddTriangle = new QPushButton(groupBox);
        AddTriangle->setObjectName("AddTriangle");

        gridLayout->addWidget(AddTriangle, 5, 0, 1, 1);

        AddStar_8 = new QPushButton(groupBox);
        AddStar_8->setObjectName("AddStar_8");

        gridLayout->addWidget(AddStar_8, 9, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 0, 231, 71));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        DeleteFigure = new QPushButton(groupBox_2);
        DeleteFigure->setObjectName("DeleteFigure");

        gridLayout_2->addWidget(DeleteFigure, 0, 1, 1, 1);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(940, 30, 71, 41));
        spinBox->setMaximum(250);
        spinBox->setSingleStep(2);
        spinBox->setValue(60);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(920, 0, 101, 31));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(270, 40, 591, 25));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(480, 0, 151, 31));
        spinBox_Y = new QSpinBox(centralwidget);
        spinBox_Y->setObjectName("spinBox_Y");
        spinBox_Y->setGeometry(QRect(940, 140, 71, 41));
        spinBox_Y->setMaximum(584);
        spinBox_X = new QSpinBox(centralwidget);
        spinBox_X->setObjectName("spinBox_X");
        spinBox_X->setGeometry(QRect(940, 90, 71, 41));
        spinBox_X->setMinimum(-135);
        spinBox_X->setMaximum(635);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(910, 90, 31, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(910, 140, 41, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(900, 200, 71, 41));
        doubleSpinBox_S = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_S->setObjectName("doubleSpinBox_S");
        doubleSpinBox_S->setGeometry(QRect(980, 200, 71, 41));
        doubleSpinBox_S->setMaximum(62500.000000000000000);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(900, 250, 71, 41));
        doubleSpinBox_P = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_P->setObjectName("doubleSpinBox_P");
        doubleSpinBox_P->setGeometry(QRect(980, 250, 71, 41));
        doubleSpinBox_P->setMaximum(1000.000000000000000);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1082, 36));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\263\321\203\321\200\321\213", nullptr));
        AddStar_5->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(5)", nullptr));
        AddStar_6->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(6)", nullptr));
        AddHexagon->setText(QCoreApplication::translate("MainWindow", "\320\250\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        AddSquare->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        AddCircle->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        AddEllipse->setText(QCoreApplication::translate("MainWindow", "\320\236\320\262\320\260\320\273", nullptr));
        AddRhombus->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        AddRectangle->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        AddTriangle->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        AddStar_8->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(8)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        DeleteFigure->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X  :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Y  :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214   :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\274\320\265\321\202\321\200 :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
