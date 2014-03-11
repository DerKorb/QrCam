#ifndef QRCAM_H
#define QRCAM_H

#include <QMainWindow>
#include <QImage>
#include <QColor>
#include <QFile>
#include <QTextStream>

namespace Ui {
class QrCam;
}


class QrCam : public QMainWindow
{
    Q_OBJECT
    
public:
    struct MillSettings
    {
        float headsize;
        float width;
        float top;
        float depth;
        float feedrate;
        float tileWidth;
    };

    explicit QrCam(QWidget *parent = 0);
    ~QrCam();
    
private:
    Ui::QrCam *ui;

    QString millQr(QImage qrcode, MillSettings ms);
    QString millBit(int x, int y, bool nextX, bool nextY, MillSettings ms);

};

#endif // QRCAM_H
