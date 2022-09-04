#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<iostream>
#include <QMainWindow>
#include"login.h"
#include"function.h"
#include"bookkeepingdata.h"
#include"vaultoperation.h"
#include"statistics.h"

extern int judge;
extern BookkeepingData book;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_log_in_triggered();
    void on_Write_clicked();
    void on_Function1_clicked();
    void on_Out_clicked();
    void on_Statistics_clicked();
    void on_UpDate_clicked();
    void on_Picture_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
