#include "delete.h"
#include "ui_delete.h"
#include<QStringList>
Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}
void Delete::labelContent(int flag){
    if(flag==3){
        ui->label->setText("请输入需要删除项目的序号:");
    }else{
        ui->label->setText("请输入需要删除项目的工号:");
    }
}

QString Delete::saveInput(){
    return ui->lineEdit->text();
}
void Delete::deleteLine(QStringList* e,int& num,int line){
    for(int i=line+1;i<num;i++){
        e[i-1]=e[i];
    }
    num--;
}
Delete::~Delete()
{
    delete ui;
}
