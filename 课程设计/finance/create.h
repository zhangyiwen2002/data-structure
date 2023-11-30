#ifndef CREATE_H
#define CREATE_H

#include <QDialog>
#include"reimbursement.h"
#include"file.h"
namespace Ui {
class Create;
}

class Create : public QDialog
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = 0);
    QStringList inputCash();
    bool isCreatePerson(QStringList cash);
    ~Create();

private:
    Ui::Create *ui;
};

#endif // CREATE_H
