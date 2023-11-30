#ifndef EXPENSESHOW_H
#define EXPENSESHOW_H

#include <QDialog>

namespace Ui {
class expenseShow;
}

class expenseShow : public QDialog
{
    Q_OBJECT

public:
    explicit expenseShow(QWidget *parent = 0);
    void show(QStringList str);
    ~expenseShow();

private:
    Ui::expenseShow *ui;
};

#endif // EXPENSESHOW_H
