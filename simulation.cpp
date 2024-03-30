#include "simulation.h"

#include <thread>

void Simulation::start() {
    while (true) {
        // Move vehicles in the swarm
        vehicleSwarm.move();

        // Check for collisions or other events

        // Update display or perform other actions

        // Sleep for a short duration to control simulation speed
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust time interval as needed
    }
}

void Simulation::stop() {
    // Stop the simulation
}
