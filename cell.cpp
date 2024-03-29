#include "cell.h"

void GrassCell::draw(QPainter& painter, const QRect& rect) const {
    painter.fillRect(rect, Qt::green);
}

void IntersectionCell::draw(QPainter& painter, const QRect& rect) const {
    painter.fillRect(rect, Qt::gray);
}

void StraightRoadCell::draw(QPainter& painter, const QRect& rect) const {
    painter.fillRect(rect, Qt::lightGray);
}

void TurnCell::draw(QPainter& painter, const QRect& rect) const {
    painter.fillRect(rect, Qt::darkGray);
}
