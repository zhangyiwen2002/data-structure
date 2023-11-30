#include "expenseshow.h"
#include "ui_expenseshow.h"

expenseShow::expenseShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expenseShow)
{
    ui->setupUi(this);
}
void expenseShow::show(QStringList str){
    ui->label_2->setText(str[1]);
    ui->label_4->setText(str[2]);
    ui->label_6->setText(str[3]);
    ui->label_8->setText(str[4]);
    ui->label_10->setText(str[5]);
    ui->label_12->setText(str[0]);
}

expenseShow::~expenseShow()
{
    delete ui;
}
