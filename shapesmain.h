#ifndef SHAPESMAIN_H
#define SHAPESMAIN_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <stdexcept>
#include <algorithm>

#include "editshapedialog.h"
#include "rotateshapedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ShapesMain; }
QT_END_NAMESPACE

class ShapesMain : public QMainWindow
{
    Q_OBJECT

public:
    ShapesMain(QWidget *parent = nullptr);
    ~ShapesMain();
private:
    Ui::ShapesMain *ui;

    bool canMoveObjects = true;
    bool updateFrames = false;
    int frameCounter = 0;

    void moveFigureToCursor();

private slots:
    void deleteFigure(bool);
    void editFigure(bool);
    void moveFigure(bool);
    void rotateFigure(bool);

    void on_deleteSelectedButton_clicked();

    void on_firstShapeButton_toggled(bool checked);

    void on_secondShapeButton_toggled(bool checked);

    void on_actionDelete_All_triggered();

    void on_actionDelete_Intersecting_triggered();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

public:
    ShapesTypes selectedType = ShapesTypes::nothing;
};

#endif // SHAPESMAIN_H
