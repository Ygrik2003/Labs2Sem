#include "matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget *parent) : QTableWidget(parent)
{
}

MatrixWidget::MatrixWidget(QSize size, QWidget *parent) : QTableWidget(parent)
{
    this->setSize(size);
}

MatrixWidget::MatrixWidget(QPoint pos, QSize size, QWidget *parent) : QTableWidget(parent)
{
    this->setGeometry(QRect(pos, size));
}

MatrixWidget::MatrixWidget(QRect geometry, QWidget *parent) : QTableWidget(parent)
{
    this->setGeometry(geometry);
}

void MatrixWidget::setPos(QPoint pos)
{
    this->setGeometry(QRect(pos, QSize(this->width(), this->height())));
}

void MatrixWidget::setSize(QSize size)
{
    this->setGeometry(QRect(QPoint(this->x(), this->y()), size));
}

void MatrixWidget::setMatrix(Matrix &matr)
{
    for (int i = 0; i < matr.getRows(); i++){
        for (int j = 0; j < matr.getColumns(); j++){
            this->setItem( i, j, new QTableWidgetItem(QString::number(matr[i][j])) );
        }
    }
}

void MatrixWidget::setDet(float det)
{
    if ( detLabel != nullptr )
        delete detLabel;
    detLabel = new QLabel( QString::number(det) );
    detLabel->setGeometry( this->cellWidget(0, 0)->size().width() * this->rowCount() / 2, this->cellWidget(0, 0)->size().height() * this->columnCount(), detLabel->size().width(), detLabel->size().height() );

void MatrixWidget::setSizeMatrix(QSize)
{

}


