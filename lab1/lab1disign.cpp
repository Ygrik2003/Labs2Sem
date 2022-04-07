#include "lab1disign.h"
#include "ui_lab1disign.h"

#include <myexception.h>

using namespace std;

lab1Disign::lab1Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab1Disign)
{
    ui->setupUi(this);

//    try {
//        MyVector vector2(0);
//    }  catch (MyException e) {
//        e.print();
//    }

//    MyChar chr1('a');
//    MyChar chr2(chr1);

//    MyString str1("Hello");
//    MyString str2(str1);

//    MyString *str_arr = new MyString[2];
//    str_arr[0] = str1;
//    str_arr[1] = str2;
//    MyVector vector2(str_arr, 2);
//    MyVector vector1(vector2);

//    cout << "Char number 1: " << chr1 << endl;
//    cout << "Char number 2: " << chr2 << endl;


//    cout << "String number 1: " << str1 << endl;
//    cout << "String number 2: " << str2 << endl;


//    cout << "Vector number 1: " << vector1 << endl;
//    cout << "Vector number 2: " << vector2 << endl;

//    str2 = MyString("world");

//    for (int i = 0; i < 5; i++) {
//        str1 = str1 + MyChar('o');
//    }

//    vector1 = vector1 + str2;

//    cout << "Char number 1: " << chr1 << endl;
//    cout << "Char number 2: " << chr2 << endl;


//    cout << "String number 1: " << str1 << endl;
//    cout << "String number 2: " << str2 << endl;


//    cout << "Vector number 1: " << vector1 << endl;
//    cout << "Vector number 2: " << vector2 << endl;


//    ifstream in("input.txt");

//    in >> vector2;

//    cout << vector2[0] << endl;

//    cout << "vector1 >= vector2 return " << bool(vector1 >= vector2) << endl;
}

lab1Disign::~lab1Disign()
{
    delete ui;
}

void lab1Disign::printDebug(MyString type, MyString textDebug)
{
    MyString debug = MyString("[") + type + MyString("]: ") + textDebug;
    //ui->debugScroll->
    //ui->verticalLayout->addWidget(new QPushButton());

}




