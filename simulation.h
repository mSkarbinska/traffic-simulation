#ifndef SIMULATION_H
#define SIMULATION_H

#include "roadsmap.h"
#include "simulationconfig.h"
#include "vehicleswarm.h"

#include <QTimer>
#include <QObject>

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(const SimulationConfig& config, QObject *parent = nullptr);
    ~Simulation();

public slots:
    void start();
    void stop();

private slots:
    void updateSimulation();

private:
    RoadsMap map;
    VehicleSwarm vehicleSwarm;
    SimulationConfig config;
    QTimer* timer;
    bool running;
};

#endif // SIMULATION_H
