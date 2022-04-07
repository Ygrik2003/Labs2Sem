#ifndef LAB6DISIGN_H
#define LAB6DISIGN_H

#include <QWidget>

namespace Ui {
class lab6Disign;
}

class lab6Disign : public QWidget
{
    Q_OBJECT

public:
    explicit lab6Disign(QWidget *parent = nullptr);
    ~lab6Disign();

private:
    Ui::lab6Disign *ui;
};

#endif // LAB6DISIGN_H
