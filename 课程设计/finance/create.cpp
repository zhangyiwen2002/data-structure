#include "create.h"
#include "ui_create.h"
#include"file.h"
#include"reimbursement.h"
#include<QDebug>
Create::Create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
}
QStringList Create::inputCash(){
    QStringList cash;
    cash.append(ui->lineEdit->text());
    cash.append(ui->lineEdit_2->text());
    cash.append(ui->lineEdit_3->text());
    cash.append(ui->lineEdit_4->text());
    cash.append("部门审批");
    return cash;
}
bool Create::isCreatePerson(QStringList cash){
    reimbursement* r=new reimbursement();
    File* f=new File();
    QStringList e[99];
    QString filepath=r->showFilePath();
    int k=f->readFile(filepath,e);
    for(int i=1;i<k;i++){
        if(e[i][0]==cash[1]){
            return true;
        }
    }
    return false;
}
Create::~Create()
{
    delete ui;
}
