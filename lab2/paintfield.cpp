#include "paintfield.h"

#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

PaintField::PaintField(QWidget *parent) : QWidget(parent)
{


    textInfo->setGeometry(755, 500, 140, 70);

}

void PaintField::mousePressEvent(QMouseEvent *event)
{
    point temp;
    float temp_distance = INFINITY;
    if (points.length() == 0)
        temp.n = 1;
    else
        temp.n = points.last().n + 1;
    if (event->type()) {

        switch (event->button()) {
            case Qt::LeftButton:
            {
                temp.x = event->pos().x();
                temp.y = event->pos().y();
                points.append(temp);
                this->update();
                break;
            }
            case Qt::RightButton:
            {
                for (int i = 0; i < points.length() - 1; i++) {
                    if (temp_distance > sqrt(pow(points[i].x - points.last().x, 2) + pow(points[i].y - points.last().y, 2)))
                    {
                        temp_distance = sqrt(pow(points[i].x - points.last().x, 2) + pow(points[i].y - points.last().y, 2));
                        line.first = points[i];
                        line.second = points.last();
                        this->update();

                    }
                    textInfo->setText(QString("Distance: ") + QString::number(temp_distance));
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
}


void PaintField::paintEvent(QPaintEvent *)
{
    this->begin(this);
    this->setBrush(Qt::black);
    for (int i = 0; i < points.length(); i++)
    {
        this->drawEllipse(QPoint(points[i].x, points[i].y), 2, 2);
        this->drawText(QPoint(points[i].x + 5, points[i].y + 8), QString::number(points[i].n));
    }

    this->drawLine(line.first.x, line.first.y, line.second.x, line.second.y);
    this->drawText((line.first.x + line.second.x) / 2, (line.first.y + line.second.y) / 2, textInfo->text());
    this->end();
}
