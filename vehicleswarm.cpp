#include "vehicleswarm.h"
#include "vehicle.h"
#include "car.h"

VehicleSwarm::VehicleSwarm(int numberOfCars, const RoadsMap& map) : map(map) {
    srand(time(nullptr));

    for (int i = 0; i < numberOfCars; ++i) {
        Coords coords;
        do {
            coords = getRandomStraightRoadCoords();
        } while (vehiclesPositions.find(coords) != vehiclesPositions.end());

        Vehicle* newCar = new Car(coords);
        vehicles.push_back(newCar);

        vehiclesPositions[coords] = newCar;
    }
}

Coords VehicleSwarm::getRandomStraightRoadCoords() const {
    int mapHeight = map.getHeight();
    int mapWidth = map.getWidth();
    while (true) {
        Coords randCoords = Coords(rand() % mapHeight, rand() % mapWidth);
        if (map.getCellTypeAt(randCoords) == STRAIGHT_ROAD) {
            return randCoords;
        }
    }
}

void VehicleSwarm::move() {};
