#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<string>
#include"loginyn.h"
#include"bookkeepingdata.h"

extern int judge;
extern BookkeepingData book;

namespace Ui {
class LogIn;
}

class LogIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
