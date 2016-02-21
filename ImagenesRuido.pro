#-------------------------------------------------
#
# Project created by QtCreator 2016-02-14T17:10:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImagenesRuido
TEMPLATE = app

LIBS += -lopencv_core -lopencv_photo\
        -lopencv_ts -lopencv_highgui\
        -lopencv_imgproc -lopencv_features2d\
        -lopencv_calib3d -lopencv_gpu -lOpenCL

SOURCES += main.cpp\
        mainwindow.cpp \
    salpimienta.cpp \
    gamma.cpp

HEADERS  += mainwindow.h \
    salpimienta.h \
    gamma.h

FORMS    += mainwindow.ui \
    salpimienta.ui \
    gamma.ui
