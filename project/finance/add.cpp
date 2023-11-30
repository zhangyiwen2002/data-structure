#include "add.h"
#include "ui_add.h"

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}
void Add::labelContent(int flag){
    if(flag==1){
        ui->widget_3->setVisible(true);
    }else if(flag==2){
        ui->widget_3->setVisible(false);
    }
}
void Add::inputContent(QString& str1,QString& str2,QString& str3,QString& str4){
    str1=ui->lineEdit->text();
    str2=ui->lineEdit_2->text();
    str3=ui->lineEdit_3->text();
    str4=ui->comboBox->currentText();
}


Add::~Add()
{
    delete ui;
}
