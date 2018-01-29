#ifndef CAMERAVIEW_H
#define CAMERAVIEW_H

#include <QObject>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

class CameraView : public QObject
{
public:
    CameraView();
    ~CameraView();

    void initCamera();
    void startCamera();

    void startCaptureImage();
    void saveCaptureImage();

public slots:
    void cameraImageCaptured(int id, QImage image);

private:
    QCamera* m_pCamera;                        // camera
    QCameraViewfinder* m_pViewFinder;          // view finder
    QCameraImageCapture* m_pImageCapture;      // capture image
    QImage* m_saveImage;
};

#endif // CAMERAVIEW_H
