#include "CameraView.h"

CameraView::CameraView()
    : m_pCamera(NULL)
    , m_pViewFinder(NULL)
    , m_pImageCapture(NULL)
    , m_saveImage(NULL)
{

}

CameraView::~CameraView()
{

}

void CameraView::initCamera()
{
    m_pCamera = new QCamera();
    m_pViewFinder = new QCameraViewfinder();
    m_pImageCapture = new QCameraImageCapture(m_pCamera);

    if (NULL != m_pImageCapture) {
        connect(m_pImageCapture, SIGNAL(imageCaptured(int,QImage)),
                this, SLOT(startCaptureImage(int,QImage)), Qt::UniqueConnection);
        m_pImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    }

    if (NULL != m_pCamera && NULL != m_pViewFinder) {
        m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
        m_pCamera->setViewfinder(m_pViewFinder);
    }
}

void CameraView::startCamera()
{
    if (NULL != m_pCamera) {
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
