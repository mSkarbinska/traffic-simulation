#include "mainwindow.h"
#include "simulation.h"
#include "simulationconfig.h"
#include "simulation.h"

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimulationConfig config;
    Simulation simulation(config);
    MainWindow w(&simulation);

    w.show();

    return a.exec();
}
