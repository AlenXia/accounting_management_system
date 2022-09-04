#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_in_triggered()//登录按钮被按下  需要新建页面
{
    LogIn *d = new LogIn();//显示登录界面
    d->show();
}

void MainWindow::on_Write_clicked()//记账按钮被按下  需要新建页面
{
    if(judge==1)//判断是否已经登陆
    {
        Function *d = new Function();//显示Function界面
        d->show();
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_Function1_clicked()//功能按钮被按下  需要新建页面
{
    if(judge==1)//判断是否已经登陆
    {
        Function *d = new Function();//显示Function界面
        d->show();
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_Out_clicked()//输出按钮被按下
{
    if(judge==1)//判断是否已经登陆
    {
        //-------------------------------------------------------------------------//
        book.OutputData();
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_Statistics_clicked()//统计按钮被按下  需要新建页面
{
    if(judge==1)//判断是否已经登陆
    {
        //-------------------------------------------------------------------------//
        Statistics *d = new Statistics();//显示Function界面
        d->show();
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_UpDate_clicked()//更新流水按钮被按下
{
    if(judge==1)//判断是否已经登陆
    {

        //-------------------------------------------------------------------------//
        VaultOperation* choose=book.getfirst();

        ui->ShowShow->insertPlainText("---------------------------------------------------------");
        ui->ShowShow->insertPlainText("                                              ");//分隔符

        while (choose != nullptr) {
            if (choose->getMoney())
            {
                bool Distinguish=choose->getDistinguish();           //辨别是收入还是支出，true为收入，false为支出
                int Id=choose->getId();
                string Date=choose->getDate();                 //格式"2020-05-11"
                string Thing=choose->getThing();
                double Money=choose->getMoney();
                double Balance=choose->getBalance();

                if(Distinguish) ui->ShowShow->insertPlainText("收入 ");
                else ui->ShowShow->insertPlainText("支出 ");

                //int转string
                string sId=to_string(Id);
                ui->ShowShow->insertPlainText(QString::fromStdString(sId));
                ui->ShowShow->insertPlainText(" ");

                ui->ShowShow->insertPlainText(QString::fromStdString(Date));
                ui->ShowShow->insertPlainText(" ");

                ui->ShowShow->insertPlainText(QString::fromStdString(Thing));
                ui->ShowShow->insertPlainText(" ");

                //double转string
                string sMoney=to_string(Money);
                string sBalance=to_string(Balance);

                ui->ShowShow->insertPlainText(QString::fromStdString(sMoney));
                ui->ShowShow->insertPlainText(" ");

                ui->ShowShow->insertPlainText(QString::fromStdString(sBalance));
                ui->ShowShow->insertPlainText(" ");

                ui->ShowShow->insertPlainText("                                                                                           ");
            }
            choose = choose->Next;
        }
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_Picture_clicked()//显示图表按钮被按下  需要新建页面
{
    if(judge==1)//判断是否已经登陆
    {
        //-------------------------------------------------------------------------//
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(judge==1)//判断是否已经登陆
    {
        //-------------------------------------------------------------------------//
        book.OutputData(1);
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(judge==1)//判断是否已经登陆
    {
        int num=BookkeepingData::n;
        ui->lineEdit->setText(QString::number(num,10));
    }
    else
    {
        LogIn *d = new LogIn();//显示登录界面
        d->show();
    }
}
