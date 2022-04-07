#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVector>
#include <lab1/lab1disign.h>
#include <lab2/lab2disign.h>
#include <lab3/lab3disign.h>
#include <lab4/lab4disign.h>
#include <lab5/lab5disign.h>
#include <lab6/lab6disign.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class QWidget; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    Ui::lab1Disign *ui_l1;
    Ui::lab2Disign *ui_l2;
    Ui::lab3Disign *ui_l3;
    Ui::lab4Disign *ui_l4;
    Ui::lab5Disign *ui_l5;
    Ui::lab6Disign *ui_l6;
    QVector<QWidget *> labWidgets;
};
#endif // MAINWINDOW_H
