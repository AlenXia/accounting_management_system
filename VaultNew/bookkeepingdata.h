#ifndef BOOKKEEPINGDATA_H
#define BOOKKEEPINGDATA_H


#include<string>
#include"vaultoperation.h"
#include<iostream>

using namespace std;

class BookkeepingData;
extern BookkeepingData book;
struct initialdata;
class VaultOperation;

class Bookkeeping
{
public:
    static int n;
    VaultOperation* first;//存指向链表头结点的指针 通过头指针遍历链表
    Bookkeeping(){}
    ~Bookkeeping(){}
    virtual void Insert(bool Distinguish, int Id, string Date,
    string Thing, double Money)=0;//通过日期的先后插入一条记录
    virtual initialdata Delete(int n)=0;//删除第n个记录
    virtual VaultOperation select_id(int id)=0;//通过id来查询记录
    virtual void traverse()=0;//遍历链表
    virtual VaultOperation* getfirst(){return first;}//获得头指针
    virtual void OutputData()=0;//输出到txt文件
    virtual void OutputData(int a)=0;//备份

};

class BookkeepingData: public Bookkeeping
{
public:
    BookkeepingData();
    BookkeepingData(int a);
    ~BookkeepingData();
    void Insert(bool Distinguish, int Id, string Date,
    string Thing, double Money);//通过日期的先后插入一条记录
    initialdata Delete(int n);//删除第n个记录
    VaultOperation select_id(int id);//通过id来查询记录
    void traverse();//遍历链表
    VaultOperation* getfirst();//获得头指针
    void OutputData();//输出到txt文件
    void OutputData(int a);//备份
    template<class T>
    friend double getYearSum(BookkeepingData b,T y);//得到年结余的友元函数
    friend double getMonthSum(BookkeepingData b, int m,int y);//得到某年某月结余的友元函数

    BookkeepingData(BookkeepingData& fuzhi) ;
};

struct initialdata {          //从文件读取信息的结构体
    bool Distinguish;
    int Id;
    string Date;
    string Thing;
    double Money;
};

#endif // BOOKKEEPINGDATA_H


