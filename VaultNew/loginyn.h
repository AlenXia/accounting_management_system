#ifndef LOGINYN_H
#define LOGINYN_H

#include <QMainWindow>
#include"bookkeepingdata.h"

extern int judge;
extern BookkeepingData book;

namespace Ui {
class LogInYN;
}

class LogInYN : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogInYN(QWidget *parent = 0);
    ~LogInYN();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LogInYN *ui;
};

#endif // LOGINYN_H
