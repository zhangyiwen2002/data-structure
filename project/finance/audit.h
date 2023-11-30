#ifndef AUDIT_H
#define AUDIT_H

#include <QObject>
#include<QStringList>
#include"file.h"
#include"authorization.h"
#include"submited.h"
class Audit : public QObject
{
    Q_OBJECT
public:
    explicit Audit(QObject *parent = nullptr);
    void auditForm();
    QString Match(QString status,int money);
    void pass(int line);
    void refuse(int line);
    void showE(QStringList* e, int &num);

signals:

public slots:
private:
    QStringList e[99];
    int num;
    QStringList state;
    File* f;
    authorization *a;
    Submited* s;
};

#endif // AUDIT_H
