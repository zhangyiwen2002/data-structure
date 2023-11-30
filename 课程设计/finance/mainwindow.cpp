#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include<QDebug>
#include<QDialog>
#include<add.h>
#include<QMessageBox>
#include<QHBoxLayout>
#include<QWidget>
#include"delete.h"
#include"change.h"
#include"inquire.h"
#include"inquireshow.h"
#include"submited.h"
#include"create.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("财务报销管理系统");
    int width = this->geometry().width();

    int height = this->geometry().height();

    this->setFixedSize(width,height); //设置窗体固定大小
    ui->tableWidget->setVisible(false);
    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(false);
    flag=0;
    this->p=new assessing(this);
    this->r=new reimbursement(this);
    this->a=new authorization(this);
    this->s=new Submited(this);
    this->f=new File(this);
    this->au=new Audit(this);
    connect(ui->toolButton,&QToolButton::clicked,this,[&](){
        ui->tableWidget->setVisible(true);
        ui->groupBox->setVisible(true);
        ui->groupBox_2->setVisible(false);
        ui->tableWidget->setColumnCount(4);
        flag=1;
        QStringList header;
        header << "工号" << "姓名" << "联系电话" << "角色";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        this->showTable(p->showFilePath());
    });
    connect(ui->toolButton_2,&QToolButton::clicked,this,[&](){
        flag=2;
        ui->tableWidget->setVisible(true);
        ui->groupBox->setVisible(true);
        ui->groupBox_2->setVisible(false);
        ui->tableWidget->setColumnCount(3);
        QStringList header;
        header << "工号" << "姓名" << "电话";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        this->showTable(r->showFilePath());
    });
    connect(ui->toolButton_3,&QToolButton::clicked,this,[&](){
        flag=3;
        ui->tableWidget->setVisible(true);
        ui->groupBox->setVisible(false);
        ui->groupBox_2->setVisible(false);
        ui->tableWidget->setColumnCount(4);
        QStringList header;
        header <<"序号"<< "角色" << "额度" << "审批人";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        this->showTable(a->showFilePath());
    });
    connect(ui->pushButton_5,&QPushButton::clicked,this,[&](){
        Add *dia=new Add(this);
        dia->labelContent(flag);
        dia->setWindowTitle("录入");
        if(dia->exec() == QDialog::Accepted){
            QString str1,str2,str3,str4;
            dia->inputContent(str1,str2,str3,str4);
            if(str1==""||str2==""||str3==""){
                QMessageBox::critical(this, "critical", "输入不能为空");
            }else{
                QString filename;
                if(flag==1){
                   filename=p->showFilePath();
                }else{
                   filename=r->showFilePath();
                }
                int tag=1;
                QFile file(filename);
                QStringList empowerList[99];
                int k=f->readFile(p->showFilePath(),empowerList);
                for(int i=1;i<k;i++){
                    if(empowerList[i][0]==str1){
                        tag=0;
                        break;
                    }
                }
                QStringList em[99];
                int t=f->readFile(r->showFilePath(),em);
                for(int i=1;i<t;i++){
                    if(em[i][0]==str1){
                        tag=0;
                        break;
                    }
                }
                if(tag){
                    file.open(QIODevice::Append);
                    file.write(str1.toUtf8());
                    file.write("\t");
                    file.write(str2.toUtf8());
                    file.write("\t");
                    file.write(str3.toUtf8());
                    if(flag==1){
                        file.write("\t");
                        file.write(str4.toUtf8());
                    }
                    file.write("\n");
                    file.close();
                    if(flag==1){
                        QString filepath=a->showFilePath();
                        QFile file(filepath);
                        file.open(QIODevice::Append);
                        file.write(QString::number(k,10).toUtf8());
                        file.write("\t");
                        file.write(str4.toUtf8());
                        file.write("\t");
                        file.write(a->returnValue(str4).toUtf8());
                        file.write("\t");
                        file.write(str1.toUtf8());
                        file.write("\n");
                        file.close();
                    }
                    showTable(filename);
                }else{
                    QMessageBox::critical(this, "critical", "工号不能相同");
                }

            }
        }


    });
    connect(ui->pushButton_3,&QPushButton::clicked,this,[&](){
        Delete *dia=new Delete(this);
        dia->labelContent(flag);
        dia->setWindowTitle("删除");
        if(dia->exec() == QDialog::Accepted){
            QString str=dia->saveInput();
            QString filepath;
            if(str==""){
                QMessageBox::critical(this, "critical", "输入不能为空");
            }
            if(flag==1){
                filepath=p->showFilePath();
            }else if(flag==2){
                filepath=r->showFilePath();
            }
            QStringList empowerList[99];
            int k=f->readFile(filepath,empowerList);
            int line=locateLine(empowerList,k,str);
            if(line==0){
                QMessageBox::warning(this, "warning", "未查询到该项目");
            }else{
                if(flag==1){
                    QStringList e[99];
                    int m=f->readFile(a->showFilePath(),e);
                    dia->deleteLine(e,m,line);
                    for(int i=1;i<m;i++){
                        e[i][0]=QString::number(i,10);
                    }
                    f->writeFile(a->showFilePath(),e,m);
                }
                dia->deleteLine(empowerList,k,line);
                f->writeFile(filepath,empowerList,k);
                showTable(filepath);
            }

        }
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[&](){
        QString inquireitem;
        QStringList empowerList[99];
        QString filepath;
        int k;
        int line;
        if(inquireItem("修改",inquireitem,filepath,empowerList,k,line,flag)){

            if(line==0){
                QMessageBox::warning(this, "warning", "未查询到该项目");
            }else{
                Change *dia=new Change(this);
                dia->labelContent(flag);
                dia->setWindowTitle("请在需要修改的栏目输入内容");
                if(dia->exec() == QDialog::Accepted){
                    QString status[4];
                    dia->inputContent(status,flag);
                    changeItem(empowerList,line,status);
                    f->writeFile(filepath,empowerList,k);
                    showTable(filepath);
                }
            }

        }
    }
    );
    connect(ui->pushButton_4,&QPushButton::clicked,this,[&](){
        QString windowTitle="查询";
        QString inquireitem;
        QStringList empowerList[99];
        QString filepath;
        int k;
        int line;
        if(inquireItem(windowTitle,inquireitem,filepath,empowerList,k,line,flag)){
            if(line==0){
                QMessageBox::warning(this, "warning", "未查询到该项目");
            }else{
                QString msg[4];
                for(int i=0,j=0;i<4&&j<empowerList[line].size();){
                    if(empowerList[line][j]!=""){
                        msg[i]=empowerList[line][j];
                        i++;
                    }
                    j++;
                }
                inquireShow* dia=new inquireShow(this);
                dia->setWindowTitle("查询结果");
                dia->labelShow(msg,flag);
                dia->exec();
            }
        }
    });
    connect(ui->toolButton_4,&QPushButton::clicked,this,[&](){
        flag=4;
        ui->tableWidget->setVisible(true);
        ui->groupBox->setVisible(false);
        ui->groupBox_2->setVisible(true);
        ui->tableWidget->setColumnCount(6);
        QStringList header;
        header <<"报销单编号"<< "提单人" << "提单金额" << "提单日期"<<"状态"<<"处理人";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        showTable(s->showFilePath());
    });
    connect(ui->pushButton_6,&QPushButton::clicked,this,[=](){
        Create *dia=new Create(this);
        dia->setWindowTitle("创建报销单");
        if(dia->exec()==QDialog::Accepted){
            QStringList cash=dia->inputCash();
            int tag=1;
            for(int i=0;i<cash.size();i++){
                if(cash[i]==""){
                    tag=0;
                    break;
                }
            }
            if(tag==0){
                QMessageBox::critical(this, "critical", "输入不能为空");
            }else{
                if(dia->isCreatePerson(cash)==true){
                    QString filepath=s->showFilePath();
                    QStringList empowerList[99];
                    int k=f->readFile(filepath,empowerList);
                    int flag=1;
                    for(int i=1;i<k;i++){
                        if(cash[0]==empowerList[i][0]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag){
                        empowerList[k]=cash;
                        empowerList[k].append(au->Match(empowerList[k][4],empowerList[k][2].toInt()));
                        k++;
                        f->writeFile(filepath,empowerList,k);
                        au->auditForm();
                        showTable(filepath);
                    }else{
                        QMessageBox::warning(this, "warning", "报销单编号不能重复");
                    }

                }else{
                    QMessageBox::warning(this, "warning", "提单人不存在");
                }

            }

        }

    });
    connect(ui->pushButton_7,&QPushButton::clicked,this,[=](){
        QStringList empowerList[99];
        int k;
        au->showE(empowerList,k);
//        for(int i=0;i<k;i++){
//            qDebug()<<empowerList[i];
//        }
        ui->tableWidget->setColumnCount(6);
        ui->tableWidget->setHorizontalHeaderLabels(empowerList[0]);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->setRowCount(k-1);
        for(int i=1;i<k ;i++){
            for( int j=0;j<empowerList[i].size();j++){
                ui->tableWidget->setItem(i-1,j,new QTableWidgetItem(empowerList[i][j]));
            }
        }
        for(int i=1;i<k ;i++){
            QWidget * w = new QWidget();
            w->setFixedHeight(50);
            QPushButton *button = new QPushButton();
            button->setText(tr("通过"));
            button->setEnabled(true);
            QPushButton *button_2 = new QPushButton();
            button_2->setText(tr("驳回"));
            button_2->setEnabled(true);
            QHBoxLayout *box=new QHBoxLayout(w);
            box->addWidget(button);
            box->addWidget(button_2);
            ui->tableWidget->setItem(i-1,5,new QTableWidgetItem(""));
            ui->tableWidget->setCellWidget(i-1,5,w);
            int line=i;
            connect(button,&QPushButton::clicked,this,[=](){
                qDebug()<<line;
                au->pass(line);
                QMessageBox::information(this, "info", "审核成功");
                ui->tableWidget->setColumnCount(6);
                QStringList header;
                header <<"报销单编号"<< "提单人" << "提单金额" << "提单日期"<<"状态"<<"处理人";
                ui->tableWidget->setHorizontalHeaderLabels(header);
                showTable(s->showFilePath());
            });
            connect(button_2,&QPushButton::clicked,this,[=](){
                qDebug()<<line;
                au->refuse(i);
                QMessageBox::information(this, "info", "驳回成功");
                ui->tableWidget->setColumnCount(6);
                QStringList header;
                header <<"报销单编号"<< "提单人" << "提单金额" << "提单日期"<<"状态"<<"处理人";
                ui->tableWidget->setHorizontalHeaderLabels(header);
                showTable(s->showFilePath());
            });
        }
    });
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        if(ui->lineEdit->text()==""){
            QMessageBox::critical(this, "critical", "输入不能为空");
        }else{
            QStringList e[99],t[99];
            int k=f->readFile(s->showFilePath(),e);
            int tag=0,num=0;
            for(int i=0;i<k;i++){
                if(e[i][0]==ui->lineEdit->text()||e[i][1]==ui->lineEdit->text()){
                    t[num]=e[i];
                    num++;
                    tag=1;
                }
            }
            if(tag==1){
                ui->tableWidget->setRowCount(num);
                ui->tableWidget->setVisible(true);
                for(int i=0;i<num ;i++){
                    for( int j=0;j<t[i].size();j++){
                        QWidget *w=new QWidget();
                        ui->tableWidget->setCellWidget(i-1,j,w);
                        ui->tableWidget->setItem(i,j,new QTableWidgetItem(t[i][j]));
                    }
                }
            }else{
                QMessageBox::critical(this, "critical", "未查询到该项目");
            }
        }
    });
}


void MainWindow::showTable(QString filepath){
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList empowerList[99];
    int k=f->readFile(filepath,empowerList);
    ui->tableWidget->setRowCount(k-1);
    for(int i=0;i<k;i++){
        empowerList[i].removeAll("");
    }
    for(int i=1;i<k ;i++){
        for( int j=0;j<empowerList[i].size();j++){
            QWidget *w=new QWidget();
            ui->tableWidget->setCellWidget(i-1,j,w);
            ui->tableWidget->setItem(i-1,j,new QTableWidgetItem(empowerList[i][j]));
        }
    }
}



int MainWindow::locateLine(QStringList* e,int num,QString str){
    for(int i=1;i<num;i++){
        if(QString::compare(e[i][0],str, Qt::CaseSensitive)==0){
            return i;
        }
    }
    return 0;
}
void MainWindow::changeItem(QStringList* empowerList,int line,QString* status){
    QString tempStatus[20];
    int i=1,j=1;
    empowerList[line].removeAll("");
    while(i<4&&j<empowerList[line].size()){
        if(status[i]==""){
            tempStatus[j]=empowerList[line][j];
        }else{
            tempStatus[j]=status[i];
        }
        i++;
        j++;
    }
    if(status[3]!=""){
        QStringList e[99];
        int m=f->readFile(a->showFilePath(),e);
        e[line].clear();
        e[line].append(QString::number(line,10).toUtf8());
        e[line].append(tempStatus[3]);
        e[line].append(a->returnValue(tempStatus[3]));
        e[line].append(empowerList[line][0]);
        f->writeFile(a->showFilePath(),e,m);
    }
    for(int i=1;i<empowerList[line].size();i++){
        empowerList[line][i]=tempStatus[i];
    }
}

bool MainWindow::inquireItem(QString windowTitle,QString& inquireitem,QString& filepath,QStringList* empowerList,int& num,int& line,int flag){
    Inquire *d=new Inquire(this);
    d->labelContent(flag);
    d->setWindowTitle(windowTitle.toUtf8());
    if(d->exec() == QDialog::Accepted){
        inquireitem=d->saveInput();
        if(inquireitem==""){
            QMessageBox::critical(this, "critical", "输入不能为空");
            return false;
        }else{
            if(flag==1){
                filepath=p->showFilePath();
            }else if(flag==2){
                filepath=r->showFilePath();
            }else{
                filepath=a->showFilePath();
            }
            int k=f->readFile(filepath,empowerList);
            num=k;
            line=locateLine(empowerList,k,inquireitem);
            return true;
        }
    }else{
        return false;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
