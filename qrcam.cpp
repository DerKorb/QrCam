#include "qrcam.h"
#include "ui_qrcam.h"
#include <QDebug>
#include <QZXing.h>

using namespace zxing;

QrCam::QrCam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QrCam)
{
    ui->setupUi(this);
    /*QImage testCode(10,10, QImage::Format_Mono);
    testCode.setColor(0, 0);
    testCode.setColor(1, 1);
    testCode.fill(0);
    testCode.setPixel(2,2,1);
    testCode.setPixel(3,3,1);
    testCode.setPixel(5,6,1);
    testCode.setPixel(5,3,1);
    testCode.setPixel(3,2,1);
    testCode.setPixel(7,3,1);
    testCode.setPixel(5,4,1);
    testCode.setPixel(3,9,1);
    testCode.setPixel(2,8,1);
    testCode.setPixel(3,3,1);
    testCode.setPixel(8,1,1);
    MillSettings ms;
    ms.depth = -2;
    ms.feedrate = 100;
    ms.headsize = 2;
    ms.top = 0;
    ms.width = 50;
    QFile file("E:\\qr\\qr.ngc");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
     return;

    QTextStream out(&file);
    out << millQr(testCode, ms);*/

    QZXing zx;
    zxing::Ref<zxing::Result> res = zx.decodeImageRes(QImage("testcdoe.jpg"));
    ArrayRef<Ref<ResultPoint> > rp = res->getResultPoints();

    qDebug() << rp[0]->getX() ;
    qDebug() << rp[0]->getY() ;
    qDebug() << rp[1]->getX() ;
    qDebug() << rp[1]->getY() ;
    qDebug() << rp[2]->getX() ;
    qDebug() << rp[2]->getY() ;
    qDebug() << res->getText()->getText().c_str();

}

QrCam::~QrCam()
{
    delete ui;
}


QString QrCam::millQr(QImage qrcode, MillSettings ms)
{
    ms.tileWidth = ms.width / qrcode.width();
    QString result("T1 M06 G43\nG17 G90 G21\nG00 Z5 S7000 M03\n");
    for (int x = 0; x < qrcode.width(); x++)
    {
        for (int y = 0; y < qrcode.height(); y++)
        {
            qDebug() << qrcode.pixel(x,y);
            if (qrcode.pixel(x,y) == 0)
                continue;

            bool nextX = x == qrcode.width() -1 ? false : qrcode.pixel(x+1,y) == 0;
            bool nextY = y == qrcode.height() -1 ? false : qrcode.pixel(x,y+1) == 0;

            result += millBit(x,y, nextX, nextY, ms);
        }
    }
    return result + "\nT0 M06 M02\n";
}

QString QrCam::millBit(int x, int y, bool nextX, bool nextY, MillSettings ms)
{
    float xMin = x*ms.tileWidth;
    float xMax = (x+1)*ms.tileWidth - (!nextX ? ms.headsize : 0);
    float yMin = y*ms.tileWidth;
    float yMax = (y+1)*ms.tileWidth - (!nextY ? ms.headsize : 0);
    QString result = QString("G00 Z5\nX%1 Y%2\nZ%3\nG01 Z%4 F%5\n").arg(xMin).arg(yMin).arg(ms.top).arg(ms.depth).arg(ms.feedrate);
    for (int y2 = 0; y2 < (yMax-yMin)/ms.headsize; y2++)
    {
       result += QString("X%1 Y%2\n").arg(xMin).arg(yMin+y2*ms.headsize); // Top left
       result += QString("X%1 Y%2\n").arg(xMax).arg(yMin+y2*ms.headsize); // Top right
       if (++y2 >= (yMax-yMin)/ms.headsize)
           break;
       result += QString("X%1 Y%2\n").arg(xMax).arg(yMin+y2*ms.headsize); // Bottom right
       result += QString("X%1 Y%2\n").arg(xMin).arg(yMin+y2*ms.headsize); // Bottom left
    }
    result += QString("G0 z%1\nz%2\n").arg(ms.top).arg(ms.top);
    return result;
}
