#ifndef LAB4DISIGN_H
#define LAB4DISIGN_H

#include <QWidget>

namespace Ui {
class lab4Disign;
}

class lab4Disign : public QWidget
{
    Q_OBJECT

public:
    explicit lab4Disign(QWidget *parent = nullptr);
    ~lab4Disign();

private:
    Ui::lab4Disign *ui;
};

#endif // LAB4DISIGN_H
