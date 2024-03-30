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

private:
    RoadsMap map;
    VehicleSwarm vehicleSwarm;
    SimulationConfig config;
};

#endif // SIMULATION_H
