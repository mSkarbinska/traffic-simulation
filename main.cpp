#include "mainwindow.h"
#include "simulation.h"
#include "simulationconfig.h"
#include "simulation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    SimulationConfig config;
    Simulation simulation(config);

    w.setSimulation(&simulation);

    w.show();
    return a.exec();
}
