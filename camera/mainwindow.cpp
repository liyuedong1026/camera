#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_maiFunction(new MainFunction())
{
    ui->setupUi(this);

    m_comboxDevice = this->findChild<QComboBox*>("cameradevice");
    if (NULL != m_comboxDevice) {
        connect(m_comboxDevice, SIGNAL(currentIndexChanged(QString)), this, SLOT(onDeviceNameChange(QString)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpen_clicked()
{
    if (NULL != m_maiFunction) {
        m_maiFunction->setCameraLable(ui->verticalLayout);
        m_maiFunction->onBtnOpenClicked();
    }
}

void MainWindow::on_btnCapture_clicked()
{
    if (NULL != m_maiFunction) {
        m_maiFunction->onBtnCaptureClicked();
    }

}

void MainWindow::on_btnSave_clicked()
{
    if (NULL != m_maiFunction) {
        m_maiFunction->onBtnSaveClicked();
    }
}

void MainWindow::on_btnLoad_clicked()
{
    if (NULL != m_maiFunction && NULL != m_comboxDevice) {
        QList<QCameraInfo> cameras = m_maiFunction->cameraDevices();
        for (int i = 0; i < cameras.size(); i++) {
            m_comboxDevice->insertItem(i, cameras.at(i).description());
        }
    }
}

void MainWindow::onDeviceNameChange(QString description)
{
    if (NULL != m_maiFunction) {
        QList<QCameraInfo> cameras = m_maiFunction->cameraDevices();
        foreach (QCameraInfo info, cameras) {
            if (info.description() == description) {
                m_maiFunction->setCameraInfo(info);
                return;
            }
        }
    }
}
