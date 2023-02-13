#include "shapesmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShapesMain w;
    w.show();
    return a.exec();
}
