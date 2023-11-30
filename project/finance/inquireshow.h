#ifndef INQUIRESHOW_H
#define INQUIRESHOW_H

#include <QDialog>

namespace Ui {
class inquireShow;
}

class inquireShow : public QDialog
{
    Q_OBJECT

public:
    explicit inquireShow(QWidget *parent = 0);
    void labelShow(QString* msg,int flag);
    ~inquireShow();

private:
    Ui::inquireShow *ui;
};

#endif // INQUIRESHOW_H
