#include "MainFunction.h"
#include <QDebug>

MainFunction::MainFunction(QObject *parent) :
    QObject(parent)
{

}

void MainFunction::onBtnOpenClicked()
{
    qDebug() << "onBtnOpenClicked";
}

void MainFunction::onBtnCaptureClicked()
{
    qDebug() << "onBtnCaptureClicked";
}

void MainFunction::onBtnSaveClicked()
{
    qDebug() << "onBtnSaveClicked";
}
