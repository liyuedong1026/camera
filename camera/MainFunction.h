#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <QObject>
#include <CameraView.h>
#include <QQmlApplicationEngine>

class MainFunction : public QObject
{
    Q_OBJECT
public:
    explicit MainFunction(QQmlApplicationEngine* engine, QObject *parent = 0);

    Q_INVOKABLE void onBtnOpenClicked();
    Q_INVOKABLE void onBtnCaptureClicked();
    Q_INVOKABLE void onBtnSaveClicked();
    void setCameraLable();
    CameraView *cameraView();

signals:

public slots:

private:
    QQmlApplicationEngine* m_appEngine;
    CameraView* m_cameraView;
};

#endif // MAINFUNCTION_H
