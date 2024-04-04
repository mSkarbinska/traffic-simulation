#include "vehicleswarm.h"
#include "vehicle.h"
#include "car.h"
#include <QDebug>

VehicleSwarm::VehicleSwarm(int numberOfCars, RoadsMap& map) : map(map) {
    srand(time(nullptr));

    for (int i = 0; i < numberOfCars; ++i) {
        Coords coords;
        do {
            coords = getRandomStraightRoadCoords();
        } while (vehiclesPositions.find(coords) != vehiclesPositions.end());
        std::set<Direction> roadDirections = map.getCellAt(coords.getRow(), coords.getCol())->getRoadDirections();

        // Choose a random direction from the available road directions
        std::vector<Direction> directions(roadDirections.begin(), roadDirections.end());
        Direction carDirection = directions[rand() % directions.size()];

        // Create a new car with the chosen direction
        Vehicle* newCar = new Car(coords, carDirection);
        vehicles.push_back(newCar);

        vehiclesPositions[coords] = newCar;
    }
    qDebug() << "Cars and their coordinates:";
    for (const auto& vehicle : vehicles) {
        qDebug() << "Car at (" << vehicle->getPosition().getRow() << ", " << vehicle->getPosition().getCol() << ")";
    }
}

Coords VehicleSwarm::getRandomStraightRoadCoords() {
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
