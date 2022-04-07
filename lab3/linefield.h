#ifndef LINEFIELD_H
#define LINEFIELD_H

#include <QWidget>
#include <qpainter.h>

class LineField : public QWidget, public QPainter
{
public:
    LineField();
    QVector<QPair<QChar, int>> commandList;
    QPoint lastPoint = QPoint(0, 0);
    QPoint getArr(QVector<QPair<QChar, int>>);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // LINEFIELD_H
