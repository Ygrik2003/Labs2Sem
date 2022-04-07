#ifndef LAB2DISIGN_H
#define LAB2DISIGN_H

#include "paintfield.h"

#include <QWidget>

namespace Ui {
class lab2Disign;
}

class lab2Disign : public QWidget
{
    Q_OBJECT

public:
    explicit lab2Disign(QWidget *parent = nullptr);
    ~lab2Disign();

private:
    Ui::lab2Disign *ui;
};

#endif // LAB2DISIGN_H
