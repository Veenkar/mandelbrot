#include "mandelbrot.h"
#include "ui_mandelbrot.h"
#include <QPainter>
#include <QDebug>
#include <complex>
#include <vector>

using namespace std;

Mandelbrot::Mandelbrot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mandelbrot)
{
    ui->setupUi(this);

    int sizex=1600;
    int sizey=1600;
    QImage img(sizex,sizey, QImage::Format_ARGB32);

    QPainter painter(&img);


    double midx=sizex*2;
    double midy=sizey*2;
    double r=1,g=1,b=1;
    double res=1.5;
    double THRESHOLD=2;
    int N_ITER=200;


    vector<vector<complex<double>>> mat;
    vector<vector<int>> iters;


    for(int i=0; i<N_ITER; i++){
        qDebug()<<i;
        mat.resize(sizex);
        iters.resize(sizex);
        for(int r=0; r<sizex;r++){
            mat[r].resize(sizey);
            iters[r].resize(sizey);
            for(int c=0; c<sizey; c++){
                mat[r][c]=(mat[r][c]*mat[r][c])+complex<double>((r-midx)/(midx*res), (c-midy)/(midy*res));
                if(abs(mat[r][c])<THRESHOLD){
                    iters[r][c]=i;
                }
            }
        }
    }

    for(int r=0; r<sizex;r++){
        for(int c=0; c<sizey; c++){
            double absv=abs(mat[r][c]);
            if(absv<THRESHOLD){
                painter.setPen(Qt::black);
            }
            else{
               QColor col;
               col=QColor::fromHsvF(1-(double)iters[r][c]/N_ITER,1,1);
               painter.setPen(col);
            }
            painter.drawPoint(r,c);
        }
    }
    img.save("frac.tiff");
    ui->label->setPixmap(QPixmap::fromImage(img));

}

Mandelbrot::~Mandelbrot()
{
    delete ui;
}
