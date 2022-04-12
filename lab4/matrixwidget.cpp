#include "matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget *parent) : QTableWidget(parent)
{
    sizeMatrix = {1, 1};
    sizeWidget = {100, 100};
}

MatrixWidget::MatrixWidget(QSize, QWidget *parent)
{

}
