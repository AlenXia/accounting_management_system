#include "loginyn.h"
#include "ui_loginyn.h"

LogInYN::LogInYN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogInYN)
{
    ui->setupUi(this);

}

LogInYN::~LogInYN()
{
    delete ui;
}

void LogInYN::on_pushButton_clicked()
{
    if(judge==1)
    {
        ui->plainTextEdit->insertPlainText("    登陆成功！");
    }
    else
    {
        ui->plainTextEdit->insertPlainText("    登陆失败！");
    }
}
