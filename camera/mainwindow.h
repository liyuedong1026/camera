#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    MainFunction* m_maiFunction;
};

#endif // MAINWINDOW_H
