#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>
#include<string>
#include"bookkeepingdata.h"
#include"vaultoperation.h"

extern BookkeepingData book;
extern int judge;

namespace Ui {
class Function;
}

class Function : public QMainWindow
{
    Q_OBJECT

public:
    explicit Function(QWidget *parent = 0);
    ~Function();

private slots:
    void on_Find_clicked();
    void on_Jizhang_clicked();
    void on_Shanchu_clicked();
    void on_Xiugai_clicked();

private:
    Ui::Function *ui;
};

#endif // FUNCTION_H
