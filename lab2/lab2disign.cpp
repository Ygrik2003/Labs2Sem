#include "lab2disign.h"
#include "ui_lab2disign.h"

lab2Disign::lab2Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab2Disign)
{
    ui->setupUi(this);
    PaintField *pf = new PaintField(this);
    pf->setGeometry(0, 0, 895, 570);

}

lab2Disign::~lab2Disign()
{
    delete ui;
}
