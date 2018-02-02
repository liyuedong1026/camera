#include "CameraView.h"


CameraView::CameraView(QObject *parent) :
    QObject(parent)
  , m_pCamera(new QCamera())
  , m_pViewFinder(new QCameraViewfinder())
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
    qDebug() << "CameraView::initCamera";

    if (NULL != m_pCamera && NULL != m_pViewFinder) {
        m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
        m_pCamera->setViewfinder(m_pViewFinder);
    }

    if (NULL != m_pImageCapture) {
        connect(m_pImageCapture, SIGNAL(imageCaptured(int, QImage)),
                this, SLOT(cameraImageCaptured(int, QImage)), Qt::UniqueConnection);
        m_pImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    }

}

void CameraView::startCamera()
{
    qDebug() << "CameraView::startCamera";
    if (NULL != m_pCamera && m_pCamera->isAvailable()) {
        qDebug() << "startCamera start";
        m_pCamera->start();
    }
}

void CameraView::startCaptureImage()
{
    qDebug() << "CameraView::startCaptureImage";
    if (NULL != m_pImageCapture && m_pImageCapture->isReadyForCapture()) {
        m_pImageCapture->capture();
    }
}

void CameraView::saveCaptureImage()
{
    qDebug() << "CameraView::saveCaptureImage";
    if (NULL != m_saveImage) {
        m_saveImage->save("test.jpg");
        delete m_saveImage;
        m_saveImage = NULL;
    }
}

void CameraView::cameraImageCaptured(int id, QImage image)
{
    Q_UNUSED(id);

    if (NULL != m_saveImage) {
        delete m_saveImage;
        m_saveImage = NULL;
    }

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
