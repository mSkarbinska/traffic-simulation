#include "qroadsmap.h"
#include "cell.h"

#include <QPainter>

QRoadsMap::QRoadsMap(RoadsMap &map, QWidget *parent) : QWidget(parent), map(map)
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

    // paint cars
}

void QRoadsMap::setCellType(int row, int col, CellType type)
{
    if (row >= 0 && row < map.getHeight() && col >= 0 && col < map.getWidth()) {
        mapGrid[row][col] = type;
        update();
    }
}
