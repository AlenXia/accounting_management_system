#include "VaultOperation.h"

VaultOperation::VaultOperation(bool distinguish, int id, string date, string thing, double money, VaultOperation* first)
{
    Distinguish = distinguish;
    Id = id;
    Date = date;
    Thing = thing;
    Money = money;
    this->Balance=0;
    if(first!=nullptr)
    {
        if (Distinguish)//根据是收入还是支出，来计算本次数据的Balance
        {
            this->Balance = first->Next->getBalance() + Money;
        }
        else
        {
            this->Balance = first->Next->getBalance() - Money;
        }
    }
}

VaultOperation::VaultOperation()       //无参构造，可以用于链表头结点和尾结点的初始化
{
    Distinguish = true;
    Id = 0;
    Date = "0000-00-00";
    Thing = "00";
    Money = 0;
    Balance = 50000;
    Next = nullptr;
}

VaultOperation::~VaultOperation()
{

}

void VaultOperation::show() const{
    cout << "收支记录编号" << Id << "：" << Date << ",通过" << Thing;
    if (Distinguish) cout << "增加";
    else cout << "减少";
    cout << Money << "元，剩余" << Balance << "元" << endl;
}

//VaultOperation operator+(const VaultOperation &v1,const VaultOperation &v2)
//{}

//VaultOperation operator-(const VaultOperation &v1,const VaultOperation &v2)
//{}

ostream & operator << (ostream &out,const VaultOperation &c)
{
    out<<c.Distinguish<<" "<<c.Id<<" "<<c.Thing<<" "<<c.Money<<" "<<c.Balance<<endl;
    return out;
}

//VaultOperation* VaultOperation::getstress() {
//	return Next;
//}
