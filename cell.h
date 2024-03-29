#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QPainter>

class Cell {
public:
    virtual ~Cell() {}
    virtual void draw(QPainter& painter, const QRect& rect) const = 0;
};

class GrassCell : public Cell {
public:
    void draw(QPainter& painter, const QRect& rect) const override;
};

class IntersectionCell : public Cell {
public:
    void draw(QPainter& painter, const QRect& rect) const override;
};

class StraightRoadCell : public Cell {
public:
    void draw(QPainter& painter, const QRect& rect) const override;
};

class TurnCell : public Cell {
public:
    void draw(QPainter& painter, const QRect& rect) const override;
};

#endif // CELL_H
