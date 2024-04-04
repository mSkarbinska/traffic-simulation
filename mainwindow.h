#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "simulation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Simulation& simulation, QWidget *parent = nullptr);
    ~MainWindow();

    // void setSimulation(Simulation &newSimulation) {
    //     simulation = newSimulation;
    // };
private:
    Ui::MainWindow *ui;
    Simulation *simulation;
};
#endif // MAINWINDOW_H
