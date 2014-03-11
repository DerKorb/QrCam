#-------------------------------------------------
#
# Project created by QtCreator 2013-12-17T13:35:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QrCam
TEMPLATE = app

include(QZXing/QZXing.pri)

SOURCES += main.cpp\
        qrcam.cpp

HEADERS  += qrcam.h

FORMS    += qrcam.ui
