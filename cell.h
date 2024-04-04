#ifndef CELL_H
#define CELL_H

#include <set>
#include <optional>
#include <map>

#include <QWidget>
#include <QPainter>

#include "direction.h"
#include "pedestriancrossing.h"
#include "trafficlight.h"

enum CellType {
    STRAIGHT_ROAD,
    INTERSECTION,
    TURN,
    GRASS,
    UNKNOWN_CELL,
};

class Cell {
public:
    virtual ~Cell() {}

    CellType getType() const {
        return type;
    };

    std::set<Direction> getRoadDirections() const {
        return roadDirections;
    };

    void setType(CellType newType) {
        type = newType;
    };

    virtual void draw(QPainter& painter, const QRect& rect) const = 0;

protected:
    Cell(CellType cellType, std::set<Direction> roadDirs) : type(cellType), roadDirections(roadDirs) {}
    Cell(CellType cellType) : type(cellType) {}

private:
    CellType type;
    std::set<Direction> roadDirections;
};

class GrassCell : public Cell {
public:
    GrassCell() : Cell(GRASS) {};
    void draw(QPainter& painter, const QRect& rect) const override;
};

class IntersectionCell : public Cell {
public:
    IntersectionCell(std::set<Direction> roadDirs) : Cell(INTERSECTION, roadDirs) {};
    void draw(QPainter& painter, const QRect& rect) const override;
    void addTrafficLight(Direction direction) {
        trafficLights[direction] = TrafficLight();
    }
private:
    std::map<Direction, TrafficLight> trafficLights;
};

class StraightRoadCell : public Cell {
public:
    StraightRoadCell(std::set<Direction> roadDirs) : Cell(STRAIGHT_ROAD, roadDirs) {};
    void draw(QPainter& painter, const QRect& rect) const override;
    void setCrossing(const PedestrianCrossing& newCrossing) {
        crossing = newCrossing;
    }
    // void setRoadDirections(bool horizontal);
private:
    std::optional<PedestrianCrossing> crossing;
};

class TurnCell : public Cell {
public:
    TurnCell(std::set<Direction> roadDirs) : Cell(TURN, roadDirs) {};
    void draw(QPainter& painter, const QRect& rect) const override;
};

#endif // CELL_H
