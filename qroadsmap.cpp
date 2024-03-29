#include "qroadsmap.h"
#include <QPainter>

QRoadsMap::QRoadsMap(QWidget *parent) : QWidget(parent)
{
    rows = 20;
    cols = 10;
    cellSize = 50;

    // Initialize the map grid with empty cells
    mapGrid.resize(rows, std::vector<CellType>(cols, Empty));
}

void QRoadsMap::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Iterate over the map grid and draw rectangles based on the cell type
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QRect cellRect(col * cellSize, row * cellSize, cellSize, cellSize);
            switch (mapGrid[row][col]) {
            case Intersection:
                painter.fillRect(cellRect, Qt::gray);
                break;
            case StraightRoad:
                painter.fillRect(cellRect, Qt::darkGray);
                break;
            case Turn:
                painter.fillRect(cellRect, Qt::lightGray);
                break;
            default:
                painter.fillRect(cellRect, Qt::green);
                break;
            }
            painter.drawRect(cellRect); // Draw border around each cell
        }
    }
}

void QRoadsMap::setCellType(int row, int col, CellType type)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        mapGrid[row][col] = type;
        update();
    }
}
