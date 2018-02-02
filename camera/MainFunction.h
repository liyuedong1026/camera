#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <QObject>
#include <CameraView.h>

class MainFunction : public QObject
{
    Q_OBJECT
public:
    explicit MainFunction(QObject *parent = 0);

    void onBtnOpenClicked();
    void onBtnCaptureClicked();
    void onBtnSaveClicked();
    void setCameraLable(QLayout *layout);
    CameraView *cameraView();

signals:

public slots:

private:
    CameraView* m_cameraView;
};

#endif // MAINFUNCTION_H
