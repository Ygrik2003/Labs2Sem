#ifndef LAB1DISIGN_H
#define LAB1DISIGN_H

#include "myvector.h"
#include <QWidget>
#include <qmainwindow.h>

#include <fstream>

namespace Ui {
class lab1Disign;
}

class lab1Disign : public QWidget
{
    Q_OBJECT

public:
    explicit lab1Disign(QWidget *parent = nullptr);
    ~lab1Disign();

    void printDebug(MyString type, MyString textDebug);

private:
    Ui::lab1Disign *ui;
};

#endif // LAB1DISIGN_H
