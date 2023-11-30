#include "change.h"
#include "ui_change.h"

Change::Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
}
void Change::labelContent(int flag){
    if(flag==1){
        ui->widget_3->setVisible(true);
    }else if(flag==2){
        ui->widget_3->setVisible(false);
    }
}
void Change::inputContent(QString* str,int flag){
    str[1]=ui->lineEdit_2->text();
    str[2]=ui->lineEdit_3->text();
    if(flag==1){
        str[3]=ui->comboBox->currentText();
    }else{
        str[3]="";
    }
}

Change::~Change()
{
    delete ui;
}
