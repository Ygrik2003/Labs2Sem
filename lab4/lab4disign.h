#ifndef LAB4DISIGN_H
#define LAB4DISIGN_H

#include <QWidget>
#include <QFileDialog>
#include <fstream>

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
    QString path;


private slots:
    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_calcButton_clicked();

    void on_saveAsButton_clicked();

private:
    Ui::lab4Disign *ui;
};

#endif // LAB4DISIGN_H
