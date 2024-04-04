// simulation.cpp
#include "simulation.h"
#include <QDebug>
Simulation::Simulation(const SimulationConfig& config, QObject *parent)
    : QObject(parent), map(RoadsMap()), vehicleSwarm(VehicleSwarm(config.getNumberOfCars(), map)), config(config), running(false)
{
    timer = new QTimer(this); // Create QTimer object
    connect(timer, &QTimer::timeout, this, &Simulation::updateSimulation);
}

Simulation::~Simulation()
{
    stop();
    delete timer; // Delete QTimer object
}

void Simulation::start()
{
    if (!running) {
        timer->start(100); // Start the timer with a specified interval (100 milliseconds in this case)
        running = true;
    }
}

void Simulation::stop()
{
    if (running) {
        timer->stop(); // Stop the timer
        running = false;
    }
}

void Simulation::updateSimulation()
{
    if (!running)
        return;

    vehicleSwarm.move();
    qDebug() << "hi from the loop";
    // Check for collisions or other events
    // Update display or perform other actions
}
