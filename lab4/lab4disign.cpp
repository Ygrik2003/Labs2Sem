#include "lab4disign.h"
#include "ui_lab4disign.h"

lab4Disign::lab4Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab4Disign)
{
    ui->setupUi(this);
}

lab4Disign::~lab4Disign()
{
    delete ui;
}
