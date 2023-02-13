#include "rotateshapedialog.h"
#include "ui_rotateshapedialog.h"

RotateShapeDialog::RotateShapeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RotateShapeDialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setMinimum(-180);
    ui->horizontalSlider->setMaximum(180);
    ui->horizontalSlider->setSingleStep(1);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), parent, SLOT(update()));
}

RotateShapeDialog::~RotateShapeDialog()
{
    delete ui;
}

void RotateShapeDialog::on_horizontalSlider_valueChanged(int value)
{
    SceneController::getInstance().rotateSelected(qDegreesToRadians(value));
}

