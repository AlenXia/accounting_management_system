#ifndef STATISTICS_H
#define STATISTICS_H

#include <QMainWindow>
#include<iostream>
#include"bookkeepingdata.h"
#include"vaultoperation.h"
#include<string>
#include<string.h>

extern BookkeepingData book;

namespace Ui {
class Statistics;
}

class Statistics : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = 0);
    ~Statistics();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
