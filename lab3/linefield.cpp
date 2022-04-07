#include "linefield.h"

LineField::LineField()
{

}

QPoint LineField::getArr(QVector<QPair<QChar, int> > a)
{
    commandList = a;
    this->repaint();
    return lastPoint;
}


void LineField::paintEvent(QPaintEvent *event)
{

    this->begin(this);
    lastPoint = QPoint(0, 0);
    for (int i = 0; i < commandList.length(); i++) {
        if (commandList[i].first == 'W') {
            this->drawLine(lastPoint, lastPoint + QPoint(0, -commandList[i].second));
            lastPoint = lastPoint + QPoint(0, -commandList[i].second);
        } else if (commandList[i].first == 'S') {
            this->drawLine(lastPoint, lastPoint + QPoint(0, commandList[i].second));
            lastPoint = lastPoint + QPoint(0, commandList[i].second);

        } else if (commandList[i].first == 'A') {
            this->drawLine(lastPoint, lastPoint + QPoint(-commandList[i].second, 0));
            lastPoint = lastPoint + QPoint(-commandList[i].second, 0);

        } else if (commandList[i].first == 'D') {
            this->drawLine(lastPoint, lastPoint + QPoint(commandList[i].second, 0));
            lastPoint = lastPoint + QPoint(commandList[i].second, 0);

        }
    }
    this->end();
}
