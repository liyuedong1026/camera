#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_maiFunction(new MainFunction())
{
    ui->setupUi(this);

    m_maiFunction->setCameraLable(ui->verticalLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpen_clicked()
{
    if (NULL != m_maiFunction) {
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
