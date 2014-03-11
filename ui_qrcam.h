/********************************************************************************
** Form generated from reading UI file 'qrcam.ui'
**
** Created: Fri 10. Jan 15:57:23 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCAM_H
#define UI_QRCAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QrCam
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QrCam)
    {
        if (QrCam->objectName().isEmpty())
            QrCam->setObjectName(QString::fromUtf8("QrCam"));
        QrCam->resize(400, 300);
        menuBar = new QMenuBar(QrCam);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QrCam->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QrCam);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QrCam->addToolBar(mainToolBar);
        centralWidget = new QWidget(QrCam);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QrCam->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QrCam);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QrCam->setStatusBar(statusBar);

        retranslateUi(QrCam);

        QMetaObject::connectSlotsByName(QrCam);
    } // setupUi

    void retranslateUi(QMainWindow *QrCam)
    {
        QrCam->setWindowTitle(QApplication::translate("QrCam", "QrCam", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QrCam: public Ui_QrCam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCAM_H
