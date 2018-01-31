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

//    qmlRegisterType<MainFunction>("function_main", 1, 0, "MainFunction");
    QQmlApplicationEngine engine;

    if (NULL != engine.rootContext()) {
        engine.rootContext()->setContextProperty("test", new MainFunction);
    }

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
