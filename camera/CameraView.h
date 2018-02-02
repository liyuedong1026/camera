#ifndef CAMERAVIEW_H
#define CAMERAVIEW_H

#include <QObject>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QLayout>

class CameraView : public QObject
{
    Q_OBJECT
public:
    explicit CameraView(QObject *parent = 0);
    void setViewWidget(QLayout *layout);

signals:
    void signal_buttonOpen();
    void signal_buttonCapture();
    void signal_buttonSave();

public slots:
    void initCamera();
    void startCamera();
    void startCaptureImage();
    void saveCaptureImage();
    void cameraImageCaptured(int id, QImage image);

    void onButtonOpen();
    void onButtonCapture();
    void onButtonSave();

private:
    QCamera* m_pCamera;                        // camera
    QCameraViewfinder* m_pViewFinder;          // view finder
    QCameraImageCapture* m_pImageCapture;      // capture image
    QImage* m_saveImage;
};

#endif // CAMERAVIEW_H
