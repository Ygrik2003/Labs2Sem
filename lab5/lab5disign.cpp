#include "lab5disign.h"
#include "ui_lab5disign.h"

lab5Disign::lab5Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab5Disign)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->setRenderHints(QPainter::Antialiasing);

    ui->graphicsView->centerOn(0, 0);
    ui->graphicsView->scene()->setSceneRect(QRectF(QPoint(0, 0), ui->graphicsView->size()));
    pen.setWidth(2);

    ui->plotButton->setShortcut(tr("CTRL+P"));
}


lab5Disign::~lab5Disign()
{
    delete ui;
}

float lab5Disign::firstFuncY(float y)
{
    return fabs(1 - y);
}

float lab5Disign::secondFuncX(float x)
{
    return 1 / fabs(2 - fabs(x));
}

void lab5Disign::refresh(float x1, float x2)
{
    left = x1;
    right = x2;
    center.setX((fabs(left) / fabs(left - right)) * ui->graphicsView->width());
    if (x2 < 0) {
        top = x2 - x1;
        bot = 0;
        center.setY(ui->graphicsView->height() - 20 + 1);
    } else {
        top = (x2 - x1) / 2;
        bot = -(x2 - x1) / 2;
        center.setY(ui->graphicsView->height() / 2 + 1);
    }
    scale = abs(x2 - x1) * step / ui->graphicsView->width();
}

void lab5Disign::paint()
{
    float shiftX = step -(int)center.x() % step;
    float shiftY = step - (int)center.y() % step;



    ui->graphicsView->scene()->clear();

    ui->graphicsView->scene()->addLine(QLineF(0, center.y(), ui->graphicsView->width(), center.y()));
    for (int i = left * ui->graphicsView->width() - shiftX; i < right * ui->graphicsView->width(); i+= step)
        ui->graphicsView->scene()->addLine(QLineF(i - left * ui->graphicsView->width(), center.y() + 5, i - left * ui->graphicsView->width(), center.y() - 5));


    ui->graphicsView->scene()->addLine(QLineF(center.x(), 0, center.x(), ui->graphicsView->height()));
    for (int i = bot * ui->graphicsView->height() - shiftY; i < top * ui->graphicsView->height(); i+= step)
        ui->graphicsView->scene()->addLine(QLineF((fabs(left) / fabs(left - right)) * ui->graphicsView->width() - 5, i - bot * ui->graphicsView->height(), (fabs(left) / fabs(left - right)) * ui->graphicsView->width() + 5, i - bot * ui->graphicsView->height()));



    for (float x = left; x < right; x += 0.001) {
        ui->graphicsView->scene()->addLine((x - left) * step / scale, ui->graphicsView->height() - (secondFuncX(x) * step / scale + center.y()), (x - left + 0.001)  * step / scale, ui->graphicsView->height() - (secondFuncX(x + 0.001) * step / scale + center.y()), pen);
    }

    for (float y = bot; y < top; y += 0.001) {
        ui->graphicsView->scene()->addLine(
                    (firstFuncY(y) * step / scale + center.x()),
                    center.y() - (y ) * step / scale,
                    (firstFuncY(y + 0.001) * step / scale + center.x()),
                    center.y() - (y  + 0.001)  * step / scale,
                    pen);
    }

    ui->graphicsView->repaint();
}

void lab5Disign::on_plotButton_clicked()
{
    float min_x, max_x;
    min_x = ui->XMinlineEdit->text().toFloat();
    max_x = ui->XMaxlineEdit->text().toFloat();
    refresh(min_x, max_x);
    paint();
}

