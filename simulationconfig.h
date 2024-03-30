#ifndef SIMULATIONCONFIG_H
#define SIMULATIONCONFIG_H


class SimulationConfig {
public:
    SimulationConfig(bool pedestrians = false, int numberOfCars = 5, bool trafficLights = false, int mapWidth = 20, int mapHeight = 10);

    bool hasPedestrians() const { return pedestrians; }
    int getNumberOfCars() const { return numberOfCars; }
    bool hasTrafficLights() const { return trafficLights; }

private:
    bool pedestrians;
    int numberOfCars;
    bool trafficLights;
};


#endif // SIMULATIONCONFIG_H
