#ifndef VEHICLE_H
#define VEHICLE_H

#include "coords.h"
#include "direction.h"

class Vehicle {
public:
    virtual ~Vehicle() {}
    Vehicle();
    Vehicle(Coords coords);
    virtual void move() = 0;
    Coords getCoords() const { return currPosition; }
    Direction getDirection() const { return direction; }
    void setCoords(const Coords& coords) { currPosition = coords; }
    void setDirection(Direction dir) { direction = dir; }
private:
    Coords currPosition;
    Direction direction;
};


#endif // VEHICLE_H
