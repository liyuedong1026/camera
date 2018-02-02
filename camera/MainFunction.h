#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <QObject>
#include <CameraView.h>
#include <QCameraInfo>

class MainFunction : public QObject
{
    Q_OBJECT
public:
    explicit MainFunction(QObject *parent = 0);

    void onBtnOpenClicked();
    void onBtnCaptureClicked();
    void onBtnSaveClicked();
    void setCameraLable(QLayout *layout);
    void setCameraInfo(const QCameraInfo& info);

    CameraView *cameraView();
    QList<QCameraInfo> cameraDevices();
signals:

public slots:

private:
    CameraView* m_cameraView;
};

#endif // MAINFUNCTION_H
