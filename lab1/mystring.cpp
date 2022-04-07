 #include "mystring.h"

#include <myexception.h>
#include <QDebug>

MyString::MyString()
{
     this->setValue(1);
}
MyString::MyString(MyString &value)
{
    //for (int i = 0; i < value.length; i++) {
        this->setValue(value.getValue(), value.getLength());
    //}
}
MyString::MyString(char *value, int size)
{
    this->setValue(size);
    for (int i = 0; i < length; i++) {
        this->value[i].setValue(value[i]);
    }
}
MyString::MyString(std::string value)
{
    this->setValue(value.length());
    for(int i = 0; i < this->length; i++) {
        this->value[i].setValue(value[i]);
    }
}
MyString::MyString(MyChar* value, int size)
{
    this->setValue(value, size);
}
MyString::MyString(int size)
{
    this->setValue(size);
}
MyString::~MyString()
{
    delete[] this->value;
}

MyChar &MyString::operator[](int index)
{
    if (index >= this->length)
        throw MyException("Index out of range", QString::number(index) + " out of range is " + QString::number(length));
    return value[index];
}

bool MyString::operator<(MyString value)
{
    if (this->getLength() < value.getLength())
        return true;
    else
        return false;
    int count = 0;
    bool isEqual = true;
    while (isEqual) {
        if (this->value[count].lower() == value.getValue()[count].lower()) {
            if (count < length)
                count += 1;
            else
                return false;
        } else {
            isEqual = false;
        }
    }

    return this->value[count].lower() < value.getValue()[count].lower();
}
bool MyString::operator<=(MyString value)
{
    if (this->getLength() < value.getLength())
        return true;
    else
        return false;
    int count = 0;
    bool isEqual = true;
    while (isEqual) {
        if (this->value[count].lower() == value.getValue()[count].lower()) {
            if (count < length)
                count += 1;
            else
                return true;
        } else {
            isEqual = false;
        }
    }

    return this->value[count].lower() <= value.getValue()[count].lower();
}
bool MyString::operator>(MyString value)
{
    if (this->getLength() > value.getLength())
        return true;
    else
        return false;
    int count = 0;
    bool isEqual = true;
    while (isEqual) {
        if (this->value[count].lower() == value.getValue()[count].lower()) {
            if (count < length)
                count += 1;
            else
                return false;
        } else {
            isEqual = false;
        }
    }

    return this->value[count].lower() > value.getValue()[count].lower();
}
bool MyString::operator>=(MyString value)
{
    if (this->getLength() > value.getLength())
        return true;
    else
        return false;
    int count = 0;
    bool isEqual = true;
    while (isEqual) {
        if (this->value[count].lower() == value.getValue()[count].lower()) {
            if (count < length)
                count += 1;
            else
                return true;
        } else {
            isEqual = false;
        }
    }

    return this->value[count].lower() >= value.getValue()[count].lower();
}
bool MyString::operator==(MyString value)
{
    if (this->getLength() != value.getLength())
        return false;
    int count = 0;
    bool isEqual = true;
    while (isEqual) {
        if (this->value[count].lower() == value.getValue()[count].lower()) {
            if (count < length)
                count += 1;
            else
                return true;
        } else {
            isEqual = false;
        }
    }

    return false;
}
bool MyString::operator!=(MyString value)
{
    if (this->getLength() != value.getLength())
        return true;
    int count = 0;
    bool isEqual = true;
    while (isEqual) {
        if (this->value[count].lower() == value.getValue()[count].lower()) {
            if (count < length)
                count += 1;
            else
                return false;
        } else {
            isEqual = false;
        }
    }

    return true;
}
MyString &MyString::operator=(MyString value)
{
    this->setValue(value.getValue(), value.getLength());
    return *this;
}

std::ostream &operator<<(std::ostream &out, MyString &value)
{
    for (int i = 0; i < value.getLength(); i++) {
        out << value[i];
    }
    return out;
}
std::istream &operator>>(std::istream &in, MyString &value)
{
    std::string str;
    in >> str;
    value = MyString(str);
    return in;
}

void MyString::setValue(MyChar *value, int length)
{
    if (length == 0)
        throw MyException("Null object", "You cannot create null object");

    this->length = length;
    delete[] this->value;

    this->value = new MyChar[length];
    for (int i = 0; i < length; i++) {
        this->value[i] = value[i];
    }

}
void MyString::setValue(int length)
{
    if (length == 0)
        throw MyException("Null object", "You cannot create null object");

    this->length = length;
    delete[] this->value;
    this->value = new MyChar[length];
}

MyChar *MyString::getValue()
{
    return this->value;
}

QString MyString::getString()
{
    QString chars;

    for (int i = 0; i < this->length; i++) {
        chars += value[i].getValue();
    }
    return chars;
}

int MyString::getLength()
{
    return this->length;
}

MyString operator+(MyString summand, MyString addend)
{
    MyString value(summand.getLength() + addend.getLength());

    for (int i = 0; i < summand.getLength(); i++) {
        value[i].setValue(summand.getValue()[i].getValue());
    }
    for (int i = summand.getLength(); i < addend.getLength(); i++) {
        value[i].setValue(addend.getValue()[i - summand.getLength()].getValue());
    }
    return value;
}
MyString operator+(MyString summand, MyChar addend)
{
    MyString value(summand.getLength() + 1);
    for (int i = 0; i < summand.getLength(); i++) {
        value[i].setValue(summand.getValue()[i].getValue());
    }
    value[summand.getLength()].setValue(addend.getValue());
    return value;
}
MyString operator+(MyChar summand, MyString addend)
{
    MyString value(addend.getLength() + 1);
    value[0].setValue(summand.getValue());
    for (int i = 0; i < addend.getLength(); i++) {
        value[i + 1].setValue(addend.getValue()[i].getValue());
    }
    return value;
}
