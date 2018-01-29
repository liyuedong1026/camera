#include <QApplication>
#include <QQmlApplicationEngine>
#include <QPushButton>
#include <QDebug>
#include "MainScreen.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<MainScreen>("MainScreen", 1, 0, "MainScreen");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    QObject *rootObject = engine.rootObjects().first();
    if (NULL != rootObject) {
        QObject *button = rootObject->findChild<QObject*>("save");
        if (button) {
            qDebug() << "123";
            //        button->setText("123");
        }
        else {
            qDebug() << "456";
        }

        QObject *screen = rootObject->findChild<QObject*>("mainscreen");
        if (screen) {
            qDebug() << "screen123";
        }
        else {
            qDebug() << "screen456";
        }
    }

    return app.exec();
}
