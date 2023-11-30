#include "file.h"
#include"QFile"
File::File(QObject *parent) : QObject(parent)
{

}
int File::readFile(QString filepath,QStringList* e){
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    int k = 0 ;
    while( !file.atEnd()){
        QByteArray line = file.readLine();
        QString str(line) ;
        e[k]=str.split("\t");
        if(e[k].size()!=0){
            k++;
        }
    }
    file.close();
    return k;
}
void File::writeFile(QString filepath,QStringList* e,int num){
    clearFile(filepath);
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    for(int i=0;i<num ;i++){
        for( int j=0;j<e[i].size();j++){
            file.write(e[i][j].toUtf8());
            if(j<e[i].size()-1){
                file.write("\t");
            }

        }
    }
    file.close();
}
void File::clearFile(QString filepath){
    QFile file(filepath);
    file.open(QFile::WriteOnly|QFile::Truncate);
    file.close();
}
