#include "lab5disign.h"
#include "ui_lab5disign.h"

lab5Disign::lab5Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab5Disign)
{
    ui->setupUi(this);
}

lab5Disign::~lab5Disign()
{
    delete ui;
}
