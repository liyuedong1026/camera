#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "MainFunction.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnOpen_clicked();

    void on_btnCapture_clicked();

    void on_btnSave_clicked();

    void on_btnLoad_clicked();

    void onDeviceNameChange(QString description);

private:
    Ui::MainWindow *ui;
    MainFunction* m_maiFunction;
    QComboBox* m_comboxDevice;
};

#endif // MAINWINDOW_H
