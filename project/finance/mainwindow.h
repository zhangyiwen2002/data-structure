#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QStringList>
#include"assessing.h"
#include"reimbursement.h"
#include"authorization.h"
#include"submited.h"
#include"file.h"
#include"audit.h"
#include"expenseshow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int readFile(QString filepath,QStringList* e);
    void writeFile(QString filepath,QStringList* e,int num);
    void clearFile(QString filepath);
    int locateLine(QStringList* e,int num,QString str);
    void deleteLine(QStringList* e,int& num,int line);
    void changeItem(QStringList* empowerList,int line,QString* status);
    bool inquireItem(QString windowTitle,QString& inquireitem,QString& filepath,QStringList* empowerList,int& num,int& line,int flag);
    void showTable(QString filepath);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    assessing* p;
    reimbursement* r;
    authorization *a;
    Submited* s;
    File* f;
    Audit *au;
    int flag;
};

#endif // MAINWINDOW_H
