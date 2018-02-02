#include "MainFunction.h"
#include <QDebug>

MainFunction::MainFunction(QObject *parent) :
    QObject(parent)
  , m_cameraView(new CameraView())
{

}

void MainFunction::onBtnOpenClicked()
{
    qDebug() << "MainFunction::onBtnOpenClicked";
    if (NULL != m_cameraView) {
        m_cameraView->onButtonOpen();
    }
}

void MainFunction::onBtnCaptureClicked()
{
    qDebug() << "MainFunction::onBtnCaptureClicked";
    if (NULL != m_cameraView) {
        m_cameraView->onButtonCapture();
    }
}

void MainFunction::onBtnSaveClicked()
{
    qDebug() << "MainFunction::onBtnSaveClicked";
    if (NULL != m_cameraView) {
        m_cameraView->onButtonSave();
    }
}

void MainFunction::setCameraLable(QLayout *layout)
{
    qDebug() << "MainFunction::setCameraLable";
    if (NULL != m_cameraView) {
        m_cameraView->setViewWidget(layout);
    }
}

CameraView *MainFunction::cameraView()
{
    return m_cameraView;
}
