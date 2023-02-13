#ifndef SHAPE_H
#define SHAPE_H

#include <QtGui>
#include <QtCore>

enum Places {
    upperLeft,
    upper,
    upperRight,
    downLeft,
    down,
    downRight
};

class Shape
{
public:
    Shape(qreal x, qreal y, qreal width, qreal height);

    QPainterPath outline;
    qreal rotationAngle = 0;

    void setStart(qreal startOffset);

    void addLine(Places place, qreal endOffset=0);

    void addOuterRound(qreal radius, Places place);
    void addInnerRound(qreal radius, Places place);
    void addRoundPit(qreal radius, Places place);
    void addStair(qreal a, Places place);
    void addSlope(qreal a, Places place);
    void addPit(qreal a, Places place);

    void setPosition(qreal x, qreal y);
    void restorePosition();

    qreal getX();
    qreal getY();

    qreal getHeight();
    qreal getWidth();

    qreal getPerimeter();
    qreal getArea();

private:
    qreal x;
    qreal y;

    qreal width;
    qreal height;

    qreal previousX;
    qreal previousY;

    qreal area;
    qreal perimeter;
};

#endif // SHAPE_H
