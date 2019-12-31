#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <QMainWindow>

namespace Ui {
class Mandelbrot;
}

class Mandelbrot : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mandelbrot(QWidget *parent = 0);
    ~Mandelbrot();

private:
    Ui::Mandelbrot *ui;
};

#endif // MANDELBROT_H
