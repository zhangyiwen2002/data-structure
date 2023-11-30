#include "audit.h"
#include"submited.h"
#include"file.h"
#include"authorization.h"
#include"delete.h"
#include<QString>
#include<QDebug>
#include<ctime>
Audit::Audit(QObject *parent) : QObject(parent)
{
    a=new authorization();
    s=new Submited();
    f=new File();
    num=0;
    state<<"创建"<<"部门审批"<<"财务审批"<<"付款结束";
    e[0]<<"报销单编号"<<"提单金额"<<"提单日期"<<"状态"<<"处理人"<<"审核意见";
    this->auditForm();
}
void Audit::auditForm(){
    QStringList empowerList[99];
    QString filepath=s->showFilePath();
    int k=f->readFile(filepath,empowerList);
    int i=1,j=1;
    while(i<k){
        if(empowerList[i][4]==state[1]||empowerList[i][4]==state[2]){
            e[j].clear();
            for(int l=0;l<empowerList[i].size();l++){
                if(l!=1){
                    e[j].append(empowerList[i][l]);
                }
            }
//            qDebug()<<e[j];
//            e[j].append(Match(empowerList[i][4],empowerList[i][2].toInt()));
//            empowerList[i][5]=Match(empowerList[i][4],empowerList[i][2].toInt());
            j++;
        }/*else{
            if(empowerList[i][4]==state[0]){
                empowerList[i][5]=empowerList[i][1]+"\r\n";
            }else{
                empowerList[i][5]="\r\n";
            }

        }*/
        i++;
    }
    for(int i=0;i<k;i++){
        qDebug()<<empowerList[i];
    }
    num=j;
    f->writeFile(filepath,empowerList,k);
}

QString Audit::Match(QString status,int money){
    QStringList empowerList[99];
    QString proper[99];
    int properNum=0;
    int k=f->readFile(a->showFilePath(),empowerList);
    for(int i=0;i<k;i++){
        empowerList[i].removeAll("");
    }
    if(status==state[1]){
        for(int i=1;i<k;i++){
            if(empowerList[i][1]=="部门主管"||empowerList[i][1]=="部门副主管"){
                if(empowerList[i][2].toInt()>=money){
                    proper[properNum]=empowerList[i][3];
                    properNum++;
                }
            }
        }
        if(properNum!=0){
            qsrand(time(NULL));
            int n = qrand() % properNum;
            return proper[n];
        }
        return "未匹配到对应审批人";
    }else if(status==state[2]){
        for(int i=1;i<k;i++){
            if(empowerList[i][1]=="财务主管"||empowerList[i][1]=="财务副主管"){
                if(empowerList[i][2].toInt()>=money){
                    proper[properNum]=empowerList[i][3];
                    properNum++;
                }
            }
        }
        if(properNum!=0){
            qsrand(time(NULL));
            int n = qrand() % properNum;
            return proper[n];
        }
        return "未匹配到对应审批人";
    }
    return "\r\n";
}
void Audit::pass(int line){
    QStringList empowerList[99];
    int k=f->readFile(s->showFilePath(),empowerList);
    for(int i=0;i<k;i++){
        empowerList[i].removeAll("");
//        qDebug()<<empowerList[i];
    }
    for(int i=1;i<k;i++){
//        qDebug()<<empowerList[i][0];
//        qDebug()<<e[line][0];
        if(empowerList[i][0]==e[line][0]){

            if(empowerList[i][4]==state[1]){
                empowerList[i][4]=state[2];

            }else if(empowerList[i][4]==state[2]){
                empowerList[i][4]=state[3];
            }
            empowerList[i].removeLast();
            empowerList[i].append(Match(empowerList[i][4],empowerList[i][2].toInt()));
            break;
        }
    }
    f->writeFile(s->showFilePath(),empowerList,k);
    auditForm();
}
void Audit::refuse(int line){
    QStringList empowerList[99];
    int k=f->readFile(s->showFilePath(),empowerList);
    for(int i=0;i<k;i++){
        empowerList[i].removeAll("");
    }
    for(int i=1;i<k;i++){
        if(empowerList[i][0]==e[line][0]){
            empowerList[i][4]=state[0];
            empowerList[i].removeLast();
            QString temp=empowerList[i][1];
            empowerList[i].append(temp+"\r\n");
            break;
        }
    }
    f->writeFile(s->showFilePath(),empowerList,k);
    auditForm();
}

void Audit::showE(QStringList* e, int& num){
    num=this->num;
    for(int i=0;i<num;i++){
        e[i]=this->e[i];
    }
}
