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
    Cell(CellType cellType) : type(cellType) {}
    std::set<Direction> roadDirections;
    void setRoadDirections(const std::set<Direction>& newDirections) {
        roadDirections = newDirections;
    };
private:
    CellType type;
};

class GrassCell : public Cell {
public:
    GrassCell() : Cell(GRASS) {};
    void draw(QPainter& painter, const QRect& rect) const override;
};

class IntersectionCell : public Cell {
public:
    IntersectionCell() : Cell(INTERSECTION) {};
    void draw(QPainter& painter, const QRect& rect) const override;
    void addTrafficLight(Direction direction, const TrafficLight& trafficLight) {
        trafficLights[direction] = trafficLight;
    }
private:
    std::map<Direction, TrafficLight> trafficLights;
};

class StraightRoadCell : public Cell {
public:
    StraightRoadCell() : Cell(STRAIGHT_ROAD) {};
    void draw(QPainter& painter, const QRect& rect) const override;
    void setCrossing(const PedestrianCrossing& newCrossing) {
        crossing = newCrossing;
    }
    void setRoadDirections(bool horizontal);
private:
    std::optional<PedestrianCrossing> crossing;
};

class TurnCell : public Cell {
public:
    TurnCell() : Cell(TURN) {};
    void draw(QPainter& painter, const QRect& rect) const override;
};

#endif // CELL_H
