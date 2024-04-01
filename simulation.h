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

protected:
    RoadsMap map;
    VehicleSwarm vehicleSwarm;

private:
    SimulationConfig config;
};

#endif // SIMULATION_H
