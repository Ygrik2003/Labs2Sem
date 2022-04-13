#ifndef MYSTRING_H
#define MYSTRING_H

#include "mychar.h"


class MyString
{
public:
    MyString();
    MyString(char *, int);
    MyString(std::string);
    MyString(MyChar*, int);
    MyString(int);
    MyString(const MyString &);
    ~MyString();

    friend MyString operator+(MyString, MyString);
    friend MyString operator+(MyString, MyChar);
    friend MyString operator+(MyChar, MyString);

    MyChar &operator[](int index);
    bool operator<(MyString);
    bool operator<=(MyString);
    bool operator>(MyString);
    bool operator>=(MyString);
    bool operator==(MyString);
    bool operator!=(MyString);
    MyString &operator=(MyString);
    friend std::ostream &operator<<(std::ostream &, MyString &);
    friend std::istream &operator>>(std::istream &, MyString &);


    void setValue(MyChar*, int);
    void setValue(int);
    MyChar *getValue() const;
    QString getString() const;
    int getLength() const;

    private:
    MyChar *value = new MyChar[1];
    int length = 1;
};


#endif // MYSTRING_H
