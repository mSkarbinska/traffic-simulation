#include "roadsmap.h"
#include "cell.h"
#include "direction.h"

RoadsMap::RoadsMap() {
    generateCells();
}

void RoadsMap::generateCells() {
    cells = std::vector<std::vector<std::shared_ptr<Cell>>>(this->getHeight(), std::vector<std::shared_ptr<Cell>>(this->getWidth()));

    for (int row = 0; row < this->getHeight(); ++row) {
        for (int col = 0; col < this->getWidth(); ++col) {
            std::shared_ptr<Cell> grassCell = std::make_shared<GrassCell>();
            cells[row][col] = grassCell;
        }
    }

    for (int col = 0; col < this->getHeight(); ++col) {
        std::shared_ptr<Cell> roadCellRow4 = std::make_shared<StraightRoadCell>();
        cells[col][4] = roadCellRow4;
    }

    for (int col = 0; col < this->getWidth(); ++col) {
        std::shared_ptr<Cell> roadCellRow7 = std::make_shared<StraightRoadCell>();
        cells[7][col] = roadCellRow7;
    }

    std::shared_ptr<IntersectionCell> intersection = std::make_shared<IntersectionCell>();
    intersection->addTrafficLight(NORTH);
    cells[7][4] = intersection;
};

std::shared_ptr<Cell> RoadsMap::getCellAt(int row, int col) const {
    return cells[row][col];
}

CellType RoadsMap::getCellTypeAt(Coords coords) const {
    if (coords.getRow() < 0 || coords.getRow() >= height || coords.getCol() < 0 || coords.getCol() >= width) {
        return UNKNOWN_CELL;
    }

    std::shared_ptr<Cell> cell = getCellAt(coords.getRow(), coords.getCol());

    if (cell) {
        return cell->getType();
    } else {
        return UNKNOWN_CELL;
    }
};

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
