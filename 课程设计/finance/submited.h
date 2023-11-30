#ifndef SUBMITED_H
#define SUBMITED_H

#include <QObject>

class Submited : public QObject
{
    Q_OBJECT
public:
    explicit Submited(QObject *parent = nullptr);
    QString showFilePath();
signals:

public slots:
private:
    QString filepath;
};

#endif // SUBMITED_H
