QT       += core gui quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# SOURCES
SOURCES += \
    circle.cpp \
    ellipse.cpp \
    figure.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    rhombus.cpp \
    square.cpp \
    triangle.cpp

# HEADERS
HEADERS += \
    circle.h \
    ellipse.h \
    figure.h \
    hexagon.h \
    mainwindow.h \
    rectangle.h \
    rhombus.h \
    square.h \
    triangle.h

# UI FORMS
FORMS += \
    mainwindow.ui

# Deployment rules
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
