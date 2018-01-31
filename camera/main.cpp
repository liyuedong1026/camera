#include <QApplication>
#include <QQmlApplicationEngine>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QQmlComponent>
#include <QQmlContext>
#include <QDebug>
#include <QQuickView>
#include "MainFunction.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MainFunction ff;

    if (NULL != engine.rootContext()) {
        engine.rootContext()->setContextProperty("mainfunction", &ff);
    }

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
