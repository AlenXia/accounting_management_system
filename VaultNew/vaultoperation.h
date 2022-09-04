#ifndef VAULTOPERATION_H
#define VAULTOPERATION_H


#include<iostream>
#include"bookkeepingdata.h"

using namespace std;
class BookkeepingData;
extern BookkeepingData book;

class VaultOperation
{
private://记录ID，发生日期，发生事件，操作金额，余额
    bool Distinguish;//辨别是收入还是支出，true为收入，false为支出
    int Id;
    string Date;
    string Thing;
    double Money;
    double Balance;

public:
    VaultOperation* Next;//指向下一条记账数据
    VaultOperation(bool distinguish, int id, string date, string thing, double money, VaultOperation* first);//有参构造函数
    VaultOperation();//无参构造函数
    ~VaultOperation();//析构函数
//    VaultOperation( VaultOperation& a)
//    {
//        this->setDistinguish(a.getDistinguish());
//        this->setBalance(a.getBalance());
//        this->setMoney(a.getMoney());
//        this->setDate(a.getDate());
//        this->setId(a.getId());
//        this->setThing(a.getThing());
//    }//复制构造函数

    //+重载
    //friend VaultOperation operator+(const VaultOperation &v1,const VaultOperation &v2);//只能同类型的才能相加或相减
    //-重载
    //friend VaultOperation operator-(const VaultOperation &v1,const VaultOperation &v2);
    //<<重载
    friend ostream & operator << (ostream &out,const VaultOperation &c); 	//运算符<<重载
    //重载++
    VaultOperation& operator++()
    {
        if (Distinguish == 1) Money += 100;
        else Money -= 100;
        Balance += 100;
        return *this;
    }
    //重载++
    VaultOperation operator++(int)
    {
        VaultOperation* old = this;
        ++(*this);
        return *old;
    }

    void setId(int id) { Id = id; }  //id、盈亏、发生日期、发生事件、操作金额、余额的get set函数
    int getId() { return Id; }
    void setDistinguish(bool a) { Distinguish = a; }
    bool getDistinguish() const{ return Distinguish; }
    void setDate(string str) { Date = str; }
    string getDate() const{ return Date; }
    void setThing(string str) { Thing = str; }
    string getThing() const{ return Thing; }
    void setMoney(double money) { Money = money; }
    double getMoney() const{ return Money; }
    void setBalance(double balance) { Balance = balance; }
    double getBalance() const{ return Balance; }
    void show()const;                   //显示某一收支记录信息
    friend class Bookkeeping;
//	VaultOperation* getstress();
};

#endif // VAULTOPERATION_H
