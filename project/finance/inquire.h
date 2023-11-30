#ifndef INQUIRE_H
#define INQUIRE_H

#include <QDialog>

namespace Ui {
class Inquire;
}

class Inquire : public QDialog
{
    Q_OBJECT

public:
    explicit Inquire(QWidget *parent = 0);
    void labelContent(int flag);
    QString saveInput();
    ~Inquire();

private:
    Ui::Inquire *ui;
};

#endif // INQUIRE_H
