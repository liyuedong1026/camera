#include <QApplication>
#include <QQmlApplicationEngine>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
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
    MainFunction mFuction(&engine);

    if (NULL != engine.rootContext()) {
        engine.rootContext()->setContextProperty("mainfunction", &mFuction);
//        engine.rootContext()->setContextProperty("cameraview", mFuction.cameraView());
    }
//    QObject *item = engine.rootObjects().first()->findChild<QObject*>("rectangle");

//    QLayout *layout = new QLayout;
//    mFuction.cameraView()->setViewWidget(layout);

//    QLabel* label = new QLabel;

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    QQmlApplicationEngine *m_appEngine = &engine;
    QObject* root = m_appEngine->rootObjects().first();

    QObject* cameraLable = root->findChild<QObject*>("rectangle");
    if (cameraLable) {
        mFuction.cameraView()->setViewWidget((QLayout *)cameraLable);

    }

    return app.exec();
}
