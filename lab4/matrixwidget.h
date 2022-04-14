#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QTableWidget>
#include <QWidget>
#include <QLabel>

#include "matrix.h"

class MatrixWidget : public QTableWidget
{
    Q_OBJECT
public:
    MatrixWidget(QWidget *parent = nullptr);
    MatrixWidget(QSize, QWidget *parent = nullptr);
    MatrixWidget(QPoint, QWidget *parent = nullptr);
    MatrixWidget(QPoint, QSize, QWidget *parent = nullptr);
    MatrixWidget(QRect, QWidget *parent = nullptr);

    MatrixWidget(const MatrixWidget &);

    void setPos(QPoint);
    void setSize(QSize);

    void setMatrix( Matrix & );
    void setDet( float det );

private:
    QLabel *detLabel = nullptr;

};

#endif // MATRIXWIDGET_H
