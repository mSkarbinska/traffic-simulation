#ifndef VEHICLESWARM_H
#define VEHICLESWARM_H

#include <list>
#include <map>
#include "vehicle.h"
#include "roadsmap.h"
#include "coords.h"

class VehicleSwarm {
private:
    std::list<Vehicle*> vehicles;
    std::map<Coords, Vehicle*> vehiclesPositions;
    RoadsMap map;

public:
    VehicleSwarm(int numberOfCars, RoadsMap& map);

    Vehicle* getVehicleAtCoords(const Coords& coords);
    Coords getRandomStraightRoadCoords();
    void move();
    std::list<Vehicle*> getVehicles() { return vehicles; }
};

#endif // VEHICLESWARM_H
