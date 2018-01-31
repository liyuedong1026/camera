#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <QObject>

class MainFunction : public QObject
{
    Q_OBJECT
public:
    explicit MainFunction(QObject *parent = 0);

    Q_INVOKABLE void onBtnOpenClicked();
    Q_INVOKABLE void onBtnCaptureClicked();
    Q_INVOKABLE void onBtnSaveClicked();


signals:

public slots:

};

#endif // MAINFUNCTION_H
