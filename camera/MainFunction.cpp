#include "MainFunction.h"
#include <QDebug>

MainFunction::MainFunction(QQmlApplicationEngine *engine, QObject *parent) :
    QObject(parent)
  , m_appEngine(engine)
  , m_cameraView(new CameraView())
{

}

void MainFunction::onBtnOpenClicked()
{
    qDebug() << "MainFunction::onBtnOpenClicked";
    m_cameraView->onButtonOpen();
}

void MainFunction::onBtnCaptureClicked()
{
    qDebug() << "MainFunction::onBtnCaptureClicked";
    m_cameraView->onButtonCapture();
}

void MainFunction::onBtnSaveClicked()
{
    qDebug() << "MainFunction::onBtnSaveClicked";
    m_cameraView->onButtonSave();
}

void MainFunction::setCameraLable()
{
    qDebug() << "MainFunction::setCameraLable";
    if (NULL != m_appEngine) {
        QObject* root = m_appEngine->rootObjects().first();

        QObject* cameraLable = root->findChild<QObject*>("showcamera");
        if (cameraLable) {

        }
    }
}

CameraView *MainFunction::cameraView()
{
    return m_cameraView;
}
