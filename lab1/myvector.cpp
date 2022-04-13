#include "myvector.h"

#include <qdebug.h>

MyVector::MyVector()
{
    this->setValue(1);
}
MyVector::MyVector(MyString *value, int size)
{
    this->setValue(size);
    for (int i = 0; i < length; i++) {
        this->value[i] = value[i];
    }
}
MyVector::MyVector(int size)
{
    this->setValue(size);
}
MyVector::MyVector(const MyVector &value)
{
    this->setValue(value.getValue(), value.getLength());
}
MyVector::~MyVector()
{
    delete[] this->value;
}

MyString &MyVector::operator[](int index)
{
    if (index >= this->length)
        throw MyException("Index out of range", QString::number(index) + " out of range is " + QString::number(length));
    return value[index];
}

bool MyVector::operator<(MyVector value)
{
    if (this->getLength() < value.getLength())
        return true;
    else
        return false;
}
bool MyVector::operator<=(MyVector value)
{
    if (this->getLength() <= value.getLength())
        return true;
    else
        return false;
}
bool MyVector::operator>(MyVector value)
{
    if (this->getLength() > value.getLength())
        return true;
    else
        return false;
}
bool MyVector::operator>=(MyVector value)
{
    if (this->getLength() >= value.getLength())
        return true;
    else
        return false;
}
bool MyVector::operator==(MyVector value)
{
    if (this->getLength() != value.getLength())
        return false;
    for (int i = 0; i < length; i++) {
        if (this->value[i] != value[i])
            return false;
    }
    return true;
}
bool MyVector::operator!=(MyVector value)
{
    if (this->getLength() == value.getLength())
        return false;
    else
        return true;
}

MyVector &MyVector::operator=(MyVector value)
{
    this->setValue(value.getLength());
    for (int i = 0; i < this->length; i++) {
        this->value[i] = value[i];
    }
    return *this;
}

void MyVector::setValue(MyString *value, int length)
{
    if (length == 0)
        throw MyException("Null object", "You cannot create null object");

    this->length = length;
    delete[] this->value;
    this->value = new MyString[length];
    for (int i = 0; i < length; i++) {
        this->value[i] = value[i];
    }
}
void MyVector::setValue(int length)
{
    if (length == 0)
        throw MyException("Null object", "You cannot create null object");

    this->length = length;
    delete[] this->value;
    this->value = new MyString[length];
}

MyString *MyVector::getValue() const
{
    return this->value;
}
int MyVector::getLength() const
{
    return length;
}

std::ostream &operator<<(std::ostream &out, MyVector &value)
{
    for (int i = 0; i < value.getLength(); i++) {
        out << value[i] << " ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, MyVector &value)
{
    MyString temp;
    MyVector temp1;
    while (!in.eof()) {
        in >> temp;
        temp1 = temp1 + temp;
    }

    value.setValue(temp1.getLength() - 1);
    for (int i = 0; i < value.getLength(); i++) {
        value[i] = temp1[i + 1];
    }
    return in;
}

MyVector operator+(MyVector summand, MyVector addend)
{
    MyVector value(summand.getLength() + addend.getLength());
    for (int i = 0; i < summand.getLength(); i++) {
        value[i].setValue(summand.getValue()[i].getValue(), summand.getValue()[i].getLength());
    }
    for (int i = summand.getLength(); i < addend.getLength(); i++) {
        value[i].setValue(addend.getValue()[i - summand.getLength()].getValue(), addend.getValue()[i - summand.getLength()].getLength());
    }
    return value;
}
MyVector operator+(MyString summand, MyVector addend)
{
    MyVector value(addend.getLength() + 1);
    value[0].setValue(summand.getValue(), summand.getLength());
    for (int i = 0; i < addend.getLength(); i++) {
        value[i + 1].setValue(addend.getValue()[i].getValue(), addend.getValue()[i].getLength());
    }
    return value;
}
MyVector operator+(MyVector summand, MyString addend)
{
    MyVector value(summand.getLength() + 1);

    for (int i = 0; i < summand.getLength(); i++)
        value[i] = summand[i];
    value[summand.getLength()] = addend;
    return value;
}
