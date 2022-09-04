#include "statistics.h"
#include "ui_statistics.h"
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

template<class T>
double getYearSum(BookkeepingData b,T y)//得到y年的结余是多少
{
    double sumyear=0;
    VaultOperation* s = b.first;
    while (s != nullptr) {
        string str=s->getDate();
        string str1=str.substr(0, 4);
        T year=atoi(str1.c_str());
        if(year==y)
        {
            if(s->getDistinguish())
                sumyear+=s->getMoney();
            else
                sumyear-=s->getMoney();
        }
        s = s->Next;
    }
    return sumyear;

//    string str1 = str.substr(0, 4);      //用substr提取变量的一段字符
//    string str2 = str.substr(5, 2);
//    string str3 = str.substr(8, 2);
//    str = str1 + str2 + str3;             //将提取出来的年月日字符相连接
//    return atoi(str.c_str());             //将string类型日期转化为int型
}

double getMonthSum(BookkeepingData b, int m=1,int y=2020)
{
    double summonth=0;
    VaultOperation* s = b.first;
    while (s != nullptr) {
        string str=s->getDate();
        string str1=str.substr(0, 4);
        int year=atoi(str1.c_str());

        string str2;
        string str10="10";
        string str11="11";
        string str12="12";

        if(strcmp(str.substr(5,2).c_str(),str10.c_str())==0||strcmp(str.substr(5,2).c_str(),str11.c_str())==0||strcmp(str.substr(5,2).c_str(),str12.c_str())==0)
            str2 = str.substr(5, 2);
        else
            str2 = str.substr(6, 1);
        int month=atoi(str2.c_str());

        if(year==y&&month==m)
        {
            if(s->getDistinguish())
                summonth+=s->getMoney();
            else
                summonth-=s->getMoney();
        }
        s = s->Next;
    }
    return summonth;
}


Statistics::Statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::on_pushButton_clicked()
{
    double M1=0;double M2=0;double M3=0;double M4=0;double M5=0;double M6=0;double M7=0;double M8=0;double M9=0;double M10=0;double M11=0;double M12=0;
    double sumyear20=0;

    sumyear20=getYearSum(book,2020);
    M1=getMonthSum(book);
    M2=getMonthSum(book,2);
    M3=getMonthSum(book,3);
    M4=getMonthSum(book,4);
    M5=getMonthSum(book,5);
    M6=getMonthSum(book,6);
    M7=getMonthSum(book,7);
    M8=getMonthSum(book,8);
    M9=getMonthSum(book,9);
    M10=getMonthSum(book,10);
    M11=getMonthSum(book,11);
    M12=getMonthSum(book,12);

    ui->ShowShowShow->insertPlainText("2020年结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(sumyear20)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("一月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M1)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("二月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M2)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("三月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M3)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("四月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M4)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("五月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M5)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("六月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M6)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("七月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M7)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("八月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M8)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("九月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M9)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M10)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十一月结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M11)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十二月结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M12)));ui->ShowShowShow->insertPlainText("                                                     ");
}

void Statistics::on_pushButton_2_clicked()
{
    double M1=0;double M2=0;double M3=0;double M4=0;double M5=0;double M6=0;double M7=0;double M8=0;double M9=0;double M10=0;double M11=0;double M12=0;
    double sumyear21=0;

    sumyear21=getYearSum(book,2021);
    M1=getMonthSum(book,1,2021);
    M2=getMonthSum(book,2,2021);
    M3=getMonthSum(book,3,2021);
    M4=getMonthSum(book,4,2021);
    M5=getMonthSum(book,5,2021);
    M6=getMonthSum(book,6,2021);
    M7=getMonthSum(book,7,2021);
    M8=getMonthSum(book,8,2021);
    M9=getMonthSum(book,9,2021);
    M10=getMonthSum(book,10,2021);
    M11=getMonthSum(book,11,2021);
    M12=getMonthSum(book,12,2021);


    ui->ShowShowShow->insertPlainText("2021年结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(sumyear21 )));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("一月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M1)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("二月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M2)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("三月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M3)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("四月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M4)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("五月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M5)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("六月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M6)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("七月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M7)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("八月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M8)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("九月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M9)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M10)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十一月结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M11)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十二月结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M12)));ui->ShowShowShow->insertPlainText("                                                     ");
}

void Statistics::on_pushButton_3_clicked()
{
    double M1=0;double M2=0;double M3=0;double M4=0;double M5=0;double M6=0;double M7=0;double M8=0;double M9=0;double M10=0;double M11=0;double M12=0;
    double sumyear22=0;

    sumyear22=getYearSum(book,2022);
    M1=getMonthSum(book,1,2022);
    M2=getMonthSum(book,2,2022);
    M3=getMonthSum(book,3,2022);
    M4=getMonthSum(book,4,2022);
    M5=getMonthSum(book,5,2022);
    M6=getMonthSum(book,6,2022);
    M7=getMonthSum(book,7,2022);
    M8=getMonthSum(book,8,2022);
    M9=getMonthSum(book,9,2022);
    M10=getMonthSum(book,10,2022);
    M11=getMonthSum(book,11,2022);
    M12=getMonthSum(book,12,2022);


    ui->ShowShowShow->insertPlainText("2022年结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(sumyear22)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("一月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M1)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("二月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M2)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("三月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M3)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("四月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M4)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("五月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M5)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("六月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M6)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("七月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M7)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("八月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M8)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("九月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M9)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十月结余： ");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M10)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十一月结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M11)));ui->ShowShowShow->insertPlainText("                                                     ");
    ui->ShowShowShow->insertPlainText("十二月结余：");ui->ShowShowShow->insertPlainText(QString::fromStdString(to_string(M12)));ui->ShowShowShow->insertPlainText("                                                     ");
}
