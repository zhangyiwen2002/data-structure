#include "inquireshow.h"
#include "ui_inquireshow.h"

inquireShow::inquireShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inquireShow)
{
    ui->setupUi(this);
}
void inquireShow::labelShow(QString* msg,int flag){
    if(flag!=3){
        ui->label->setText("姓名："+msg[1]);
        ui->label_2->setText("联系电话："+msg[2]);
        if(flag==1){
            ui->label_3->setText("角色："+msg[3]);
        }

    }else{
        ui->label->setText("角色："+msg[1]);
        ui->label_2->setText("额度："+msg[2]);
        ui->label_3->setText("审批人："+msg[3]);
    }


}

inquireShow::~inquireShow()
{
    delete ui;
}
