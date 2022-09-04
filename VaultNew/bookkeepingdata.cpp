#include "BookkeepingData.h"
#include<fstream>
#include<vector>

int Bookkeeping::n=0;


BookkeepingData::BookkeepingData()           //无参构造
{
    first = new VaultOperation;
    first->Next = nullptr;
    n++;
}

int changeIntoDate(string str)         //将string类型日期转化为int型，以便通过日期插入数据
{
    string str1 = str.substr(0, 4);      //用substr提取变量的一段字符
    string str2 = str.substr(5, 2);
    string str3 = str.substr(8, 2);
    str = str1 + str2 + str3;             //将提取出来的年月日字符相连接
    return atoi(str.c_str());             //将string类型日期转化为int型
}

BookkeepingData::BookkeepingData(BookkeepingData& fuzhi)
{
    first = new VaultOperation;
    VaultOperation* jiuzhizhen = fuzhi.first, * xinzhizhen = first;
    while (jiuzhizhen->Next != nullptr) {
        VaultOperation *anew = new VaultOperation;

        anew->setDistinguish(jiuzhizhen->getDistinguish());
        anew->setBalance(jiuzhizhen->getBalance());
        anew->setMoney(jiuzhizhen->getMoney());
        anew->setDate(jiuzhizhen->getDate());
        anew->setId(jiuzhizhen->getId());
        anew->setThing(jiuzhizhen->getThing());

        xinzhizhen->Next = anew;
        xinzhizhen = anew;
        jiuzhizhen = jiuzhizhen->Next;

    }
}

BookkeepingData::BookkeepingData(int a)      //定义形参为int a，与无参构造区别开,用txt文件里的记录使链表初始化
{
    int b=a;
    b++;//防止报警告，警告很烦 xxx定义了但是没用上

    VaultOperation* Ending = new VaultOperation;
    first = new VaultOperation;
    first->Next = Ending;             //定义尾指针，利用尾部的结点使得有一个balance初值
    fstream ifile("E:\\QTprojects\\VaultNew\\notes.txt", ios::in);
    bool Distinguish1 = 0;         //定义临时存储的变量
    int Id1;
    string Date1;
    string Thing1;
    double Money1 = 0;
    vector<initialdata> Initialdata;      //声明一个initialdata的结构体数组以便初始化链表
    while (ifile >> Distinguish1 >> Id1 >> Date1 >> Thing1 >> Money1)
    {
        Initialdata.push_back({ Distinguish1, Id1, Date1, Thing1, Money1 });     //给数组赋值
    }
    for (int i = Initialdata.size(); i > 0; i--)     //逆向读取数组初始化链表
    {
        VaultOperation* s = new VaultOperation;
        s->setDistinguish(Initialdata[i - 1].Distinguish);
        s->setId(Initialdata[i - 1].Id);
        s->setDate(Initialdata[i - 1].Date);
        s->setThing(Initialdata[i - 1].Thing);
        s->setMoney(Initialdata[i - 1].Money);

        s->Next = first->Next;
        if (s->getDistinguish())//根据是收入还是支出，来计算本次数据的Balance
        {
            s->setBalance(s->Next->getBalance() + s->getMoney());
        }
        else
        {
            s->setBalance(s->Next->getBalance() - s->getMoney());
        }
        first->Next = s;
        n++;
    }
    ifile.close();
}

BookkeepingData::~BookkeepingData()           //析构函数
{
    VaultOperation* ptool = nullptr;
    while (first->Next != nullptr)
    {
        ptool = first;
        first = first->Next;
        delete ptool;
        n--;
    }
}

void BookkeepingData::Insert(bool Distinguish, int Id, string Date, string Thing, double Money)
{
    VaultOperation* p0 = first;        //first对应指针，用以修正插入记录之前的balance值
    VaultOperation* p = first;           //工作指针
    while (changeIntoDate(Date) < changeIntoDate(p->Next->getDate()))//根据日期插入一条记录
    {
        p = p->Next;
    }
    if (Id == p->Next->getId()) throw 1;
    else
    {
        VaultOperation* s = new VaultOperation;
        s->setDistinguish(Distinguish);
        s->setId(Id);
        s->setDate(Date);
        s->setThing(Thing);
        s->setMoney(Money);
        s->Next = p->Next;
        p->Next = s;
        if (s->getDistinguish())//根据是收入还是支出，来计算本次数据的Balance ，并修正此前的balance
        {
            s->setBalance(s->Next->getBalance() + s->getMoney());
            while (p0 != p)
            {
                p0->Next->setBalance(p0->Next->getBalance() + s->getMoney());
                p0 = p0->Next;
            }
        }
        else
        {
            s->setBalance(s->Next->getBalance() - s->getMoney());
            while (p0 != p)
            {
                p0->Next->setBalance(p0->Next->getBalance() - s->getMoney());
                p0 = p0->Next;
            }
        }
    }
    n++;
}



initialdata BookkeepingData::Delete(int n=0)        //根据位置删除某一记录
{
    this->n--;
    VaultOperation* s = first, *q = nullptr;
    //int count = 0;
    while (s->Next->getId() != n&&s->Next->getMoney() != 0)  //借用Money不为0来终止指针往下遍历
    {
        s = s->Next;
    }
    if (s->Next->getMoney() == 0){
        string str = "location";
        throw str;
    }
    else
    {
    q = s->Next;
    initialdata deleted_ = { q->getDistinguish(),q->getId(),q->getDate(),q->getThing(),q->getMoney() };
    s->Next = q->Next;
    delete q;
    return deleted_;
    }
}

VaultOperation BookkeepingData::select_id(int n=0)      //根据id查找某一记录
{
    VaultOperation* s = first;
    while (s->getId() != n)
    {
        s = s->Next;
    }
    if (!s->getMoney())
         throw 'a';
    else
        return *s;
//    cout << s->getMoney();     //待输出其他值
}



void BookkeepingData::traverse() {      //遍历输出整个链表
    VaultOperation* s = first;
    while (s != nullptr) {
        if (s->getMoney()) s->show();
        s = s->Next;
    }
}

void BookkeepingData::OutputData()         //将最新的数据写入文件
{
    fstream ofile;;
    ofile.open("E:\\QTprojects\\VaultNew\\notes.txt", ios::out);
    VaultOperation* s = first;
    while (s != nullptr) {
        if (s->getMoney()) ofile << s->getDistinguish() << " " << s->getId() << " " << s->getDate() << " " << s->getThing() << " " << s->getMoney() << endl;
        s = s->Next;
    }
    ofile.close();
}

void BookkeepingData::OutputData(int a)         //将最新的数据写入文件 函数重载 二次备份
{
    fstream ofile;;
    ofile.open("E:\\QTprojects\\notes.txt", ios::out);
    VaultOperation* s = first;
    while (s != nullptr) {
        if (s->getMoney()) ofile << s->getDistinguish() << " " << s->getId() << " " << s->getDate() << " " << s->getThing() << " " << s->getMoney() << endl;
        s = s->Next;
    }
    ofile.close();
}

VaultOperation* BookkeepingData::getfirst()
{
    return first;
}

BookkeepingData book(1);
