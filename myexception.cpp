#include "myexception.h"
#include "iostream"

MyException::MyException(QString err, QString info)
{
    this->err = err;
    this->info = info;
}

void MyException::print()
{
    std::cout << "[" << err.toStdString() << "]: " << info.toStdString() << std::endl;
}



