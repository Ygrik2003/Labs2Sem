#ifndef PAINTFIELD_H
#define PAINTFIELD_H

#include <QObject>
#include <QGraphicsItem>
#include <qpainter.h>
#include <QLabel>
#include <cmath>

#include <cmath>

struct point {
    int x, y;
    int n;
};

class PaintField : public QWidget, public QPainter
{
    Q_OBJECT
public:
    PaintField(QWidget *ptr=nullptr);

    QVector<point> points;
    QPair<point, point> line;
    QLabel textOut;
    QLabel *textInfo = new QLabel(this);



    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // PAINTFIELD_H
