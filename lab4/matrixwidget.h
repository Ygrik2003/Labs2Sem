#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QTableWidget>
#include <QWidget>

class MatrixWidget : public QTableWidget
{
    Q_OBJECT
public:
    MatrixWidget(QWidget *parent = nullptr);
    MatrixWidget(QSize, QWidget *parent = nullptr);

private:
    QSize sizeMatrix;
    QSize sizeWidget;
};

#endif // MATRIXWIDGET_H
