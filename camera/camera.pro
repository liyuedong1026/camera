#-------------------------------------------------
#
# Project created by QtCreator 2018-02-01T10:12:21
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MainFunction.cpp \
    CameraView.cpp

HEADERS  += mainwindow.h \
    MainFunction.h \
    CameraView.h

FORMS    += mainwindow.ui
