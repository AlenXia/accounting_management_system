#include "function.h"
#include "ui_function.h"
#include<qstring.h>
#include <string.h>
#include <string>
#include<iostream>

using namespace std;

Function::Function(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Function)
{
    ui->setupUi(this);
}

Function::~Function()
{
    delete ui;
}

void Function::on_Find_clicked()//读取文本框里的ID 输出整个内容到line文本框
{
    QString qstr=ui->line1->text().trimmed();//读取ID
    string ID;
    ID=qstr.toStdString();
    VaultOperation choose;
    //-------------------------------------------------------------------------//
    try
    {
        choose=book.select_id(atoi(ID.c_str()));
    }
    catch(...)
    {
        std::cout<<"have no result!"<<endl;
    }

    bool Distinguish=choose.getDistinguish();           //辨别是收入还是支出，true为收入，false为支出
    if(Distinguish) ui->line0->setText(QString::fromStdString("收入"));
    else ui->line0->setText(QString::fromStdString("支出"));

    int Id=choose.getId();
    ui->line1->setText(QString::number(Id,10));

    string Date=choose.getDate();                 //格式"2020-05-11"
    ui->line2->setText(QString::fromStdString(Date));

    string Thing=choose.getThing();
    ui->line3->setText(QString::fromStdString(Thing));

    double Money=choose.getMoney();
    ui->line4->setText(QString::fromStdString(to_string(Money)));

    double Balance=choose.getBalance();
    ui->line5->setText(QString::fromStdString(to_string(Balance)));

}

void Function::on_Jizhang_clicked()//读取文本框所有内容 新建一个数据类 并插入到合适的位置
{
    QString qstr0=ui->line0->text().trimmed();//读取类型
    string distinguish;
    distinguish=qstr0.toStdString();

    QString qstr=ui->line1->text().trimmed();//读取ID
    string ID;
    ID=qstr.toStdString();

    QString qstr1=ui->line2->text().trimmed();//读取日期
    string Date;
    Date=qstr1.toStdString();

    QString qstr2=ui->line3->text().trimmed();//读取事件
    string Thing;
    Thing=qstr2.toStdString();

    QString qstr3=ui->line4->text().trimmed();//读取操作金额
    string Money;
    Money=qstr3.toStdString();

    //-------------------------------------------------------------------------//
    //这个地方还需要类型转换
    string strr="收入";
    try
    {
        book.Insert(strcmp(distinguish.c_str(), strr.c_str()) == 0,atoi(ID.c_str()),Date,Thing,atof(Money.c_str()));
    }
    catch (int a)
    {
        cout << "Id is not good!" <<a<< endl;
    }


}

void Function::on_Shanchu_clicked()//通过ID删除某一条数据
{
    QString qstr=ui->line1->text().trimmed();//读取ID
    string ID;
    ID=qstr.toStdString();
    //-------------------------------------------------------------------------//
    book.Delete(atoi(ID.c_str()));

}

void Function::on_Xiugai_clicked()//输出内容到文本框 直接修改当前查询的数据
//可以先删除，再插入
{
    QString qstr=ui->line1->text().trimmed();//读取ID
    string ID;
    ID=qstr.toStdString();
    //-------------------------------------------------------------------------//

    try
    {
        book.Delete(atoi(ID.c_str()));//删除这个ID的数据
    }
    catch (...)
    {
        std::cout << "location error!" << endl;
    }

    //插入这个数据
    QString qstr0=ui->line0->text().trimmed();//读取类型
    string distinguish;
    distinguish=qstr0.toStdString();

    QString qstr1=ui->line2->text().trimmed();//读取日期
    string Date;
    Date=qstr1.toStdString();

    QString qstr2=ui->line3->text().trimmed();//读取事件
    string Thing;
    Thing=qstr2.toStdString();

    QString qstr3=ui->line4->text().trimmed();//读取操作金额
    string Money;
    Money=qstr3.toStdString();

    //-------------------------------------------------------------------------//
    //这个地方还需要类型转换
    string strr="支出";
    book.Insert(strcmp(distinguish.c_str(), strr.c_str()) == 0,
                atoi(ID.c_str()),Date,Thing,atof(Money.c_str()));
}
