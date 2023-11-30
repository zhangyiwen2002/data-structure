#ifndef REIMBURSEMENT_H
#define REIMBURSEMENT_H

#include <QObject>

class reimbursement : public QObject
{
    Q_OBJECT
public:
    explicit reimbursement(QObject *parent = nullptr);
    QString showFilePath();

signals:

public slots:
private:
    QString filepath;
};

#endif // REIMBURSEMENT_H
