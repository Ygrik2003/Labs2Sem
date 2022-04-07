#include "mychar.h"

#include <qdebug.h>


MyChar::MyChar(char value)
{
    this->value = value;
}
MyChar::MyChar(MyChar &value)
{
    this->setValue(value.getValue());
}

MyChar MyChar::operator+(MyChar addend)
{
    MyChar result;
    result = this->value + addend.value;
    return result;
}
bool MyChar::operator<(MyChar value)
{
    return this->lower().getValue() < value.lower().getValue();
}
bool MyChar::operator<=(MyChar value)
{
    return this->lower().getValue() <= value.lower().getValue();
}
bool MyChar::operator>(MyChar value)
{
    return this->lower().getValue() > value.lower().getValue();
}
bool MyChar::operator>=(MyChar value)
{
    return this->lower().getValue() >= value.lower().getValue();
}
bool MyChar::operator==(MyChar value)
{
    return this->lower().getValue() == value.lower().getValue();
}
bool MyChar::operator!=(MyChar value)
{
    return this->lower().getValue() != value.lower().getValue();
}

MyChar &MyChar::operator=(MyChar value)
{
    this->setValue(value.getValue());
    return *this;
}

std::ostream &operator<<(std::ostream &out, MyChar value)
{
    out << value.getValue();
    return out;
}
std::istream &operator>>(std::istream &in, MyChar &value)
{
    char temp;
    in >> temp;
    value.setValue(temp);
    return in;
}

void MyChar::setValue(char value)
{
    this->value = value;
}
char MyChar::getValue()
{
    return this->value;
}

MyChar MyChar::lower()
{
    char value_lower = this->getValue();
    if (value_lower >= 'A' && value_lower <= 'Z')
    {
        value_lower -= 'A' + 'a';
    }
    return value_lower;
}
