#include "lab6disign.h"
#include "ui_lab6disign.h"

lab6Disign::lab6Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab6Disign)
{
    ui->setupUi(this);
}

lab6Disign::~lab6Disign()
{
    delete ui;
}
