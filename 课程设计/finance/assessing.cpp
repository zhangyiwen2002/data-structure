#include "assessing.h"

assessing::assessing(QObject *parent) : QObject(parent)
{
    filepath="E:/project/finance/txt/assessing.txt";
}
QString assessing::showFilePath(){
    return this->filepath;
}
