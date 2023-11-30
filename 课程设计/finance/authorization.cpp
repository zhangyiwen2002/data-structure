#include "authorization.h"

authorization::authorization(QObject *parent) : QObject(parent)
{
    filepath="E:/project/finance/txt/authorization.txt";
    map.insert("部门主管","100000");
    map.insert("部门副主管","50000");
    map.insert("财务主管","100000");
    map.insert("财务副主管","50000");
}
QString authorization::showFilePath(){
    return this->filepath;
}
QString authorization::returnValue(QString key){
    return map.value(key);
}
