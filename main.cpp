#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <lab1/myvector.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.size());
    w.setWindowTitle("Лабараторные работы");
    w.show();
    return a.exec();
}
