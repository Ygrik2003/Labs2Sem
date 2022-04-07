#ifndef LAB5DISIGN_H
#define LAB5DISIGN_H

#include <QWidget>

namespace Ui {
class lab5Disign;
}

class lab5Disign : public QWidget
{
    Q_OBJECT

public:
    explicit lab5Disign(QWidget *parent = nullptr);
    ~lab5Disign();

private:
    Ui::lab5Disign *ui;
};

#endif // LAB5DISIGN_H
