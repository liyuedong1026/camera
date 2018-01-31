#include "CameraView.h"

CameraView::CameraView(QObject *parent) : QObject(parent)
  , m_pViewFinder(new QCameraViewfinder())
  , m_pCamera(new QCamera())
  , m_pImageCapture(new QCameraImageCapture(m_pCamera))
  , m_saveImage(NULL)
{
    initCamera();
    connect(this, SIGNAL(signal_buttonOpen()), this, SLOT(startCamera()), Qt::UniqueConnection);
    connect(this, SIGNAL(signal_buttonCapture()), this, SLOT(startCaptureImage()), Qt::UniqueConnection);
    connect(this, SIGNAL(signal_buttonSave()), this, SLOT(saveCaptureImage()), Qt::UniqueConnection);

}

void CameraView::setViewWidget(QLayout *layout)
{
    layout->addWidget(m_pViewFinder);
}

void CameraView::initCamera()
{
    qDebug() << "initCamera";

    if (NULL != m_pImageCapture) {
        connect(m_pImageCapture, SIGNAL(imageCaptured(int, QImage)),
                this, SLOT(cameraImageCaptured(int, QImage)), Qt::UniqueConnection);
        m_pImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    }

    if (NULL != m_pCamera && NULL != m_pViewFinder) {
        m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
        m_pCamera->setViewfinder(m_pViewFinder);
    }
}

void CameraView::startCamera()
{
    qDebug() << "startCamera";
    if (NULL != m_pCamera && m_pCamera->isAvailable()) {
        m_pCamera->start();
    }
}

void CameraView::startCaptureImage()
{
    if (NULL != m_pImageCapture && m_pImageCapture->isReadyForCapture()) {
        m_pImageCapture->capture();
    }
}

void CameraView::saveCaptureImage()
{
    if (NULL != m_saveImage) {
        m_saveImage->save("test.jpg");
    }
}

void CameraView::cameraImageCaptured(int id, QImage image)
{
    Q_UNUSED(id);
    m_saveImage = new QImage(image);
}

void CameraView::onButtonOpen()
{
    qDebug() << "CameraView::onButtonOpen";
    emit signal_buttonOpen();
}

void CameraView::onButtonCapture()
{
    qDebug() << "CameraView::onButtonCapture";
    emit signal_buttonCapture();

}

void CameraView::onButtonSave()
{
    qDebug() << "CameraView::onButtonSave";
    emit signal_buttonSave();

}
