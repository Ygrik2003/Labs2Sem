#ifndef LAB3DISIGN_H
#define LAB3DISIGN_H

#include "linefield.h"
#include "parcecommand.h"

#include <QWidget>
#include <QTextStream>
#include <qfile.h>
#include <QVector>
#include <qpainter.h>

namespace Ui {
class lab3Disign;
}

class lab3Disign : public QWidget
{
    Q_OBJECT

public:
    explicit lab3Disign(QWidget *parent = nullptr);
    ~lab3Disign();

private slots:
    void on_openButton_clicked();

    void on_saveButton_clicked();

    void on_calcButton_clicked();

    void on_drawButton_clicked();

private:
    Ui::lab3Disign *ui;

    QPoint lastPoint = QPoint(0, 0);
    QVector<QPair<QChar, int>> commandList;
    QString pathToFile;
    QString fileText;
    ParceCommand pc;
    QPainter painter;
    LineField lf;



    // QWidget interface
//protected:
//    void paintEvent(QPaintEvent *event) override;
};

#endif // LAB3DISIGN_H
