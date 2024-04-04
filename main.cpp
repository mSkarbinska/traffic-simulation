#include "mainwindow.h"
#include "simulation.h"
#include "simulationconfig.h"

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimulationConfig config;
    Simulation simulation(config);
    MainWindow w(simulation);
    QThread simulationThread;

    simulation.moveToThread(&simulationThread);

    // Connect signals to start and stop the simulation

    QObject::connect(&simulationThread, &QThread::started, &simulation, &Simulation::start);
    QObject::connect(&simulationThread, &QThread::finished, &simulationThread, &QObject::deleteLater);

    // Start the simulation thread
    simulationThread.start();
    w.show();

    return a.exec();
}
