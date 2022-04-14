#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "mystring.h"



class MyVector
{
public:
    MyVector();
    MyVector(MyString *, int);
    MyVector(int);
    MyVector(const MyVector &);
    ~MyVector();

    friend MyVector operator+(MyVector, MyVector);
    friend MyVector operator+(MyString, MyVector);
    friend MyVector operator+(MyVector, MyString);

    MyString &operator[](int index);
    bool operator<(MyVector);
    bool operator<=(MyVector);
    bool operator>(MyVector);
    bool operator>=(MyVector);
    bool operator==(MyVector);
    bool operator!=(MyVector);
    MyVector &operator=(MyVector);
    friend std::ostream &operator<<(std::ostream &, MyVector &);
    friend std::istream &operator>>(std::istream &, MyVector &);

    void setValue(MyString*, int);
    void setValue(int);
    MyString *getValue() const;
    int getLength() const;

private:
    MyString *value = new MyString[1];
    int length = 1;
};

#endif // MYVECTOR_H
