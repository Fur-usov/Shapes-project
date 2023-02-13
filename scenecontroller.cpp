#include "scenecontroller.h"

SceneController::SceneController()
{

}

void SceneController::createFirstShape(qreal x, qreal y, ShapesTypes shapeType)
{

    Shape shape = Shape(x, y, width, height);

    switch (shapeType) {
    case ShapesTypes::first:
        shape.setStart(verticesExcavations);

        shape.addRoundPit(pitRadius, Places::upper);
        shape.addStair(verticesExcavations, Places::upperRight);
        shape.addStair(verticesExcavations, Places::downRight);
        shape.addLine(Places::downRight);
        shape.addOuterRound(verticesRadius, Places::downLeft);
        shape.addStair(verticesExcavations, Places::upperLeft);
        break;
    case ShapesTypes::second:
        shape.setStart(verticesRadius);

        shape.addLine(Places::upperLeft);
        shape.addInnerRound(verticesRadius, Places::upperRight);
        shape.addInnerRound(verticesRadius, Places::downRight);
        shape.addPit(pitDeepth, Places::down);
        shape.addOuterRound(verticesRadius, Places::downLeft);
        shape.addInnerRound(verticesRadius, Places::upperLeft);
        break;
    case ShapesTypes::nothing:
        return;
    default:
        return;
    }

    shapes.push_back(shape);
}

void SceneController::rotateFigure(size_t i, qreal angle)
{
    if (i >= shapes.size()) {
        return;
    }

    Shape chosenShape = shapes[i];

    if (qAbs(chosenShape.rotationAngle - angle) < 0.01) {
        return;
    }

    QTransform transform;
    transform.translate(chosenShape.getX() + width / 2, chosenShape.getY() + height / 2);
    transform.rotate(angle);
    transform.translate(-chosenShape.getX() - width / 2, -chosenShape.getY() - height / 2);

    shapes[i].outline = transform.map(chosenShape.outline);
    shapes[i].rotationAngle = angle;
}

void SceneController::rotateSelected(qreal angle)
{
    if (qAbs(selected->rotationAngle - angle) < 0.01) {
        return;
    }

    QTransform transform;
    transform.translate(selected->getX() + width / 2, selected->getY() + height / 2);
    transform.rotate(angle);
    transform.translate(-selected->getX() - width / 2, -selected->getY() - height / 2);

    selected->outline = transform.map(selected->outline);
    selected->rotationAngle = angle;
}

void SceneController::selectFigure(size_t i)
{
    if (i >= shapes.size()) {
        return;
    }

    selected = &shapes[i];
}

void SceneController::selectFigure(Shape *figure)
{
    selected = figure;
}

void SceneController::deselectFigure()
{
    selected = nullptr;
}

void SceneController::deleteFigure(Shape *figure)
{
    for (size_t i = 0; i < shapes.size(); i++) {
        if (figure == &shapes[i]) {
            if (figure == selected) {
                selected = nullptr;
            }
            shapes.erase(shapes.begin() + i);
            break;
        }
    }
}

void SceneController::deleteFigure(int index)
{
    shapes.erase(shapes.begin() + index);
}

void SceneController::deleteSelectedFigure()
{
    deleteFigure(selected);
    deselectFigure();
}

void SceneController::editSelectedFigure()
{

}

void SceneController::renderFigures(QPainter & painter)
{
    for (Shape & shape : shapes) {
        if (&shape == selected) {
            painter.strokePath(shape.outline, QPen(Qt::blue, 3));
            continue;
        }
        painter.strokePath(shape.outline, QPen(Qt::black, 1));
    }
}

void SceneController::moveSelectedToCoordinates(qreal x, qreal y, qreal windowWidth, qreal windowHeight)
{
    if (selected == nullptr) {
        return;
    }

    QPainterPath window;
    window.addRect(0, 0, windowWidth, windowHeight);

    if (window.contains(selected->outline)) {
        selected->outline.translate(x - selected->getX(), y - selected->getY());
        selected->setPosition(x, y);
    }
    else {
        selected->restorePosition();
        throw std::out_of_range("FIGURE WAS OUT OF RANGE");
    }
}

bool SceneController::hasSelectedFigure()
{
    return selected != nullptr;
}

Shape *SceneController::getSlectedShape()
{
    return selected;
}
