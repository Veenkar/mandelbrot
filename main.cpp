#include "mandelbrot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mandelbrot w;
    w.show();

    return a.exec();
}
