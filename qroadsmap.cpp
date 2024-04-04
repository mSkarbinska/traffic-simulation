#include "qroadsmap.h"
#include "cell.h"
#include "vehicle.h"
#include "vehicleswarm.h"

#include <QPainter>

QRoadsMap::QRoadsMap(Simulation& sim, QWidget *parent) : QWidget(parent), map(sim.getMap()), vSwarm(sim.getVehicleSwam())
{
    mapGrid.resize(map.getHeight(), std::vector<CellType>(map.getWidth(), GRASS));

    for (int row = 0; row < map.getHeight(); ++row) {
        for (int col = 0; col < map.getWidth(); ++col) {
            Coords coords = Coords(row, col);
            CellType type = map.getCellTypeAt(coords);

            setCellType(row, col, type);
        }
    }
}

void QRoadsMap::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Iterate over the map grid and draw rectangles based on the cell type
    for (int row = 0; row < map.getHeight(); ++row) {
        for (int col = 0; col < map.getWidth(); ++col) {
            QRect cellRect(col * cellSize, row * cellSize, cellSize, cellSize);
            switch (mapGrid[row][col]) {
            case INTERSECTION:
                painter.fillRect(cellRect, Qt::gray);
                break;
            case STRAIGHT_ROAD:
                painter.fillRect(cellRect, Qt::darkGray);
                break;
            case TURN:
                painter.fillRect(cellRect, Qt::lightGray);
                break;
            default:
                painter.fillRect(cellRect, Qt::green);
                break;
            }
            painter.drawRect(cellRect); // Draw border around each cell
        }
    }

    for (Vehicle* vehicle : vSwarm.getVehicles()) {
        Coords vehicleCoords = vehicle->getPosition();

        int carWidth, carHeight;
        switch (vehicle->getDirection()) {
        case WEST:
        case EAST:
            carWidth = cellSize / 2;
            carHeight = cellSize / 3;
            break;
        case NORTH:
        case SOUTH:
            carWidth = cellSize / 3;
            carHeight = cellSize / 2;
            break;
        }

        int carX = vehicleCoords.getCol() * cellSize + (cellSize - carWidth) / 2;
        int carY = vehicleCoords.getRow() * cellSize + (cellSize - carHeight) / 2;

        QRect carRect(carX, carY, carWidth, carHeight);
        painter.fillRect(carRect, Qt::blue);
    }
}

void QRoadsMap::setCellType(int row, int col, CellType type)
{
    if (row >= 0 && row < map.getHeight() && col >= 0 && col < map.getWidth()) {
        mapGrid[row][col] = type;
        update();
    }
}
