#ifndef SIMULATION_H
#define SIMULATION_H

#include "roadsmap.h"
#include "simulationconfig.h"
#include "vehicleswarm.h"

class Simulation {
public:
    Simulation(const SimulationConfig& config);

    void start();
    void stop();
    void updateSimulation();

    RoadsMap& getMap() { return map; }

private:
    RoadsMap map;
    VehicleSwarm vehicleSwarm;
    SimulationConfig config;
};

#endif // SIMULATION_H
