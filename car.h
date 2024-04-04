#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
public:
    Car(): Vehicle() {};
    virtual ~Car() {};
    Car(Coords coords, Direction dir): Vehicle(coords, dir) {};
    virtual void move() override {
        // Implement car movement here
    }
};

#endif // CAR_H
