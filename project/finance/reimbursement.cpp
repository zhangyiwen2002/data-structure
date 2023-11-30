#include "reimbursement.h"

reimbursement::reimbursement(QObject *parent) : QObject(parent)
{
    filepath="E:/project/finance/txt/reimbursement.txt";
}
QString reimbursement::showFilePath(){
    return this->filepath;
}
