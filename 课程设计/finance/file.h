#ifndef FILE_H
#define FILE_H

#include <QObject>

class File : public QObject
{
    Q_OBJECT
public:
    explicit File(QObject *parent = nullptr);
    int readFile(QString filepath,QStringList* e);
    void writeFile(QString filepath,QStringList* e,int num);
    void clearFile(QString filepath);
signals:

public slots:
};

#endif // FILE_H
