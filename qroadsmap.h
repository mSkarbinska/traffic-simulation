#ifndef QROADSMAP_H
#define QROADSMAP_H

#include <QWidget>
#include <vector>

#include "cell.h"
#include "roadsmap.h"
#include "simulation.h"
#include "vehicleswarm.h"

class QRoadsMap : public QWidget
{
    Q_OBJECT
public:
    explicit QRoadsMap(Simulation& sim, QWidget *parent = nullptr);

    void setCellType(int row, int col, CellType type);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int cellSize {50};
    RoadsMap &map;
    VehicleSwarm vSwarm;
    std::vector<std::vector<CellType>> mapGrid;
};

#endif // QROADSMAP_H
