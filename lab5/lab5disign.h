#ifndef LAB5DISIGN_H
#define LAB5DISIGN_H

#include <QPen>
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
    float firstFuncY(float);
    float secondFuncX(float);
    int step = 40;
    float scale;
    QPointF center;
    QPen pen;
    float top, bot, left, right;
    void refresh(float, float);
    void paint();


private slots:
    void on_plotButton_clicked();
private:
    Ui::lab5Disign *ui;
};

#endif // LAB5DISIGN_H
