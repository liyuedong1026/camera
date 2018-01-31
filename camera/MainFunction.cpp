#include "MainFunction.h"
#include <QDebug>

MainFunction::MainFunction(QObject *parent) :
    QObject(parent)
  , m_cameraView(new CameraView())
{

}

void MainFunction::onBtnOpenClicked()
{
    qDebug() << "onBtnOpenClicked";
    m_cameraView->initCamera();
    m_cameraView->startCamera();
}

void MainFunction::onBtnCaptureClicked()
{
    qDebug() << "onBtnCaptureClicked";
}

void MainFunction::onBtnSaveClicked()
{
    qDebug() << "onBtnSaveClicked";
}
