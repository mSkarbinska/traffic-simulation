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
    VehicleSwarm(const RoadsMap& map) : map(map) {}

    Vehicle* getVehicleAtCoords(const Coords& coords);
    void move();
};

#endif // VEHICLESWARM_H
