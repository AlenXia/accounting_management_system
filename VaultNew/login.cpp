#include "login.h"
#include "ui_login.h"

using namespace std;

LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text().trimmed();//读取用户名
    string loginname;
    loginname=name.toStdString();

    QString password=ui->lineEdit_2->text().trimmed();//读取密码
    string loginpassword;
    loginpassword=password.toStdString();

    if(loginname=="root"&&loginpassword=="123456")//如果用户名和密码都正确，则修改judge的值
    {
        judge=1;
    }

    LogInYN *d = new LogInYN();//显示登录状态提示窗口
    d->show();
}
