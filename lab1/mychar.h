#ifndef MYCHAR_H
#define MYCHAR_H

#include <iostream>
#include <myexception.h>

class MyChar
{
public:
    MyChar(){};
    MyChar(char);
    MyChar(MyChar &);

    MyChar operator+(MyChar);

    bool operator<(MyChar);
    bool operator<=(MyChar);
    bool operator>(MyChar);
    bool operator>=(MyChar);
    bool operator==(MyChar);
    bool operator!=(MyChar);
    MyChar &operator=(MyChar);
    friend std::ostream &operator<<(std::ostream &, MyChar);
    friend std::istream &operator>>(std::istream &, MyChar &);
//    void *operator new[](std::size_t);
//    void operator delete[](void *);

    void setValue(char);
    char getValue();
    MyChar lower();

private:
    char value = '0';
};

#endif // MYCHAR_H
