#include "lab4disign.h"
#include "ui_lab4disign.h"

lab4Disign::lab4Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab4Disign)
{
    ui->setupUi(this);
    //ui->MatrixGrid->;
}

lab4Disign::~lab4Disign()
{
    delete ui;
}

void lab4Disign::on_saveButton_clicked()
{

}


void lab4Disign::on_openButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "", QDir::homePath(), tr("Text files (*.txt)"));
    std::fstream file(path.toStdString());

}


void lab4Disign::on_calcButton_clicked()
{

}


void lab4Disign::on_saveAsButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "", QDir::homePath(), tr("Text files (*.txt)"));
    std::fstream file(path.toStdString());


}

