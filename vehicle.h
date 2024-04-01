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

protected:
    Coords currPosition;
    Direction direction;
};

#endif // VEHICLE_H
