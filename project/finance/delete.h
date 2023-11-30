#ifndef DELETE_H
#define DELETE_H

#include <QDialog>

namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = 0);
    void labelContent(int flag);
    QString saveInput();
    void deleteLine(QStringList* e,int& num,int line);
    ~Delete();

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
