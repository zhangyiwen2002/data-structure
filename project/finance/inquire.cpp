#include "inquire.h"
#include "ui_inquire.h"

Inquire::Inquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inquire)
{
    ui->setupUi(this);
}

void Inquire::labelContent(int flag){
    if(flag==3){
        ui->label->setText("请输入序号:");
    }else{
        ui->label->setText("请输入工号:");
    }
}

QString Inquire::saveInput(){
    return ui->lineEdit->text();
}



Inquire::~Inquire()
{
    delete ui;
}
