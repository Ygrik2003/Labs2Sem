#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <lab1/lab1disign.h>
#include <lab2/lab2disign.h>
#include <lab3/lab3disign.h>
#include <lab4/lab4disign.h>
#include <lab5/lab5disign.h>
#include <lab6/lab6disign.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->tabLabsWidget->addTab(new lab1Disign(this), "Лаб. работа №1");
    ui->tabLabsWidget->addTab(new lab2Disign(this), "Лаб. работа №2");
    ui->tabLabsWidget->addTab(new lab3Disign(this), "Лаб. работа №3");
    ui->tabLabsWidget->addTab(new lab4Disign(this), "Лаб. работа №4");
    ui->tabLabsWidget->addTab(new lab5Disign(this), "Лаб. работа №5");
    ui->tabLabsWidget->addTab(new lab6Disign(this), "Лаб. работа №6");

}

MainWindow::~MainWindow()
{
    delete ui;


}


