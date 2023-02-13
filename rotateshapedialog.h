#ifndef ROTATESHAPEDIALOG_H
#define ROTATESHAPEDIALOG_H

#include <QDialog>

#include "scenecontroller.h"

namespace Ui {
class RotateShapeDialog;
}

class RotateShapeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RotateShapeDialog(QWidget *parent = nullptr);
    ~RotateShapeDialog();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::RotateShapeDialog *ui;
};

#endif // ROTATESHAPEDIALOG_H
