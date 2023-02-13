#ifndef EDITSHAPEDIALOG_H
#define EDITSHAPEDIALOG_H

#include <QDialog>

#include "scenecontroller.h"

namespace Ui {
class EditShapeDialog;
}

class EditShapeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditShapeDialog(QWidget *parent = nullptr);
    ~EditShapeDialog();

private slots:
    void on_submitDialogBox_accepted();

private:
    Ui::EditShapeDialog *ui;

    double qStringToDouble(const QString & value);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // EDITSHAPEDIALOG_H
