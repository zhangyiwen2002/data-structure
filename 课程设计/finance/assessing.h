#ifndef ASSESSING_H
#define ASSESSING_H

#include <QObject>
#include<QString>
class assessing : public QObject
{
    Q_OBJECT
public:
    explicit assessing(QObject *parent = nullptr);
    QString showFilePath();

signals:

public slots:
private:
    QString filepath;
};

#endif // ASSESSING_H
