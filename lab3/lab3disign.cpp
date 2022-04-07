#include "lab3disign.h"
#include "ui_lab3disign.h"

#include <myexception.h>
#include <QIODevice>
#include <QPainter>


lab3Disign::lab3Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab3Disign)
{
    ui->setupUi(this);
    lf.setParent(this);
    lf.setGeometry(20, 180, 861, 371);
}

lab3Disign::~lab3Disign()
{
    delete ui;
}

void lab3Disign::on_openButton_clicked()
{
    commandList.clear();
    pathToFile = ui->pathFile->text();
    QFile file(pathToFile);
    QTextStream out(&file);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw MyException("FileOpenError", "You cannot open the file with path " + pathToFile);
    } else {
        fileText = out.readAll();
        ui->commandText->clear();
        ui->commandText->setText(fileText);
    }
    file.close();
}


void lab3Disign::on_saveButton_clicked()
{
    pathToFile = ui->pathFile->text();
    QFile file(pathToFile);
    QTextStream in(&file);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        throw MyException("FileOpenError", "You cannot open the file with path " + pathToFile);
    } else {
        in << ui->commandText->toPlainText();
        qDebug() << ui->commandText->toPlainText();

    }
    file.close();
}


void lab3Disign::on_calcButton_clicked()
{
    float length;
    length = sqrt(pow(lastPoint.x(), 2) + pow(lastPoint.y(), 2));
    ui->info->setText("Length: " + QString::number(length) + " lastPoint: (" + QString::number(lastPoint.x()) + ", " + QString::number(lastPoint.y()) + ")");
}


void lab3Disign::on_drawButton_clicked()
{
    commandList.clear();
    fileText = ui->commandText->toPlainText();
    while(fileText != "") {
       commandList.append(pc.getCommand(fileText));
    }
    qDebug() << commandList;
    lastPoint = lf.getArr(commandList);
}



//void lab3Disign::paintEvent(QPaintEvent *)
//{

//}
