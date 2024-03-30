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

void StraightRoadCell::setRoadDirections(bool horizontal) {
    roadDirections.clear();  // Clear existing directions
    if (horizontal) {
        roadDirections.insert(Direction::EAST);
        roadDirections.insert(Direction::WEST);
    } else {
        roadDirections.insert(Direction::NORTH);
        roadDirections.insert(Direction::SOUTH);
    }
}

void TurnCell::draw(QPainter& painter, const QRect& rect) const {
    painter.fillRect(rect, Qt::darkGray);
}
