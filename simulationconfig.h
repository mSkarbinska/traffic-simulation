#ifndef SIMULATIONCONFIG_H
#define SIMULATIONCONFIG_H


class SimulationConfig {
public:
    SimulationConfig();
    SimulationConfig(bool pedestrians, int numberOfCars, bool trafficLights);
    bool hasPedestrians() const { return pedestrians; }
    int getNumberOfCars() const { return numberOfCars; }
    bool hasTrafficLights() const { return trafficLights; }
private:
    bool pedestrians = false;
    int numberOfCars = 5;
    bool trafficLights = true;
};


#endif // SIMULATIONCONFIG_H
