#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>
#include<QMap>
class authorization : public QObject
{
    Q_OBJECT
public:
    explicit authorization(QObject *parent = nullptr);
    QString showFilePath();
    QString returnValue(QString key);
signals:

public slots:
private:
    QString filepath;
    QMap<QString,QString> map;
};

#endif // AUTHORIZATION_H
