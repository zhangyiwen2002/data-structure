#include "submited.h"

Submited::Submited(QObject *parent) : QObject(parent)
{
    filepath="E:/project/finance/txt/submited.txt";
}
QString Submited::showFilePath(){
    return filepath;
}
