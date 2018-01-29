TEMPLATE = app

QT += qml quick widgets multimedia multimediawidgets

SOURCES += main.cpp \
    MainScreen.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

SOURCES += \
    CameraView.cpp

HEADERS += \
    CameraView.h \
    MainScreen.h
