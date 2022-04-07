#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QString>
#include <QDebug>


class MyException
{
public:
    MyException(QString, QString);


    QString err; // Message error
    QString info; // info error

    void print();
};

#endif // MYEXCEPTION_H
