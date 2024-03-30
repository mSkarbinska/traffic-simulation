#include "roadsmap.h"
#include "cell.h"


RoadsMap::RoadsMap(int width, int height, const std::vector<std::vector<CellType>>& cellTypes)
    : width(width), height(height), cells(height, std::vector<std::shared_ptr<Cell>>(width)) {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            switch (cellTypes[row][col]) {
            case INTERSECTION:
                cells[row][col] = std::make_shared<IntersectionCell>();
                break;
            case STRAIGHT_ROAD:
                cells[row][col] = std::make_shared<StraightRoadCell>();
                break;
            case TURN:
                cells[row][col] = std::make_shared<TurnCell>();
                break;
            case GRASS:
                cells[row][col] = std::make_shared<GrassCell>();
                break;
            }
        }
    }
}

std::shared_ptr<Cell> RoadsMap::getCellAt(int row, int col) const {
    return cells[row][col];
}

std::vector<std::shared_ptr<Cell>> RoadsMap::getAdjacentCells(int row, int col) const {
    std::vector<std::shared_ptr<Cell>> adjacentCells;

    if (col > 0) {
        adjacentCells.push_back(cells[row][col - 1]);
    }

    if (col < width - 1) {
        adjacentCells.push_back(cells[row][col + 1]);
    }

    if (row > 0) {
        adjacentCells.push_back(cells[row - 1][col]);
    }

    if (row < height - 1) {
        adjacentCells.push_back(cells[row + 1][col]);
    }

    return adjacentCells;
}
