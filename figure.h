#ifndef FIGURE_H
#define FIGURE_H

#include <QQuickItem>
#include <QStyle>
#include "QPainter"
#include "QGraphicsItem"

class Figure : public QGraphicsItem

{
public:
    Figure();
    void draw(QPainter *painter);
    void getPointer();
};

#endif // FIGURE_H
//сощдать указатель типа main vindow
