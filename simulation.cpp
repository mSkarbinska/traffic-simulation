#include "simulation.h"
#include "roadsmap.h"
#include "vehicleswarm.h"

Simulation::Simulation(const SimulationConfig& config): map(RoadsMap()), vehicleSwarm(VehicleSwarm(config.getNumberOfCars(), map)) {
    // QObject::connect(&timer, &QTimer::timeout, this, &Simulation::updateSimulation);
};

// void Simulation::start() {
//     timer.start(100);
// }

// void Simulation::stop() {
//     timer.stop();
// }

// Simulation::~Simulation() {
//     stop();
// }

void Simulation::updateSimulation() {
    vehicleSwarm.move();

    // Check for collisions or other events

    // Update display or perform other actions
}
