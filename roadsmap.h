#ifndef ROADSMAP_H
#define ROADSMAP_H

#include "cell.h"
#include "coords.h"

class RoadsMap {
public:
    RoadsMap();
    std::shared_ptr<Cell> getCellAt(int row, int col) const;
    std::vector<std::shared_ptr<Cell>> getAdjacentCells(int row, int col) const;

    int getWidth() { return width; }
    int getHeight() { return height; }
    CellType getCellTypeAt(Coords coords) const;
    void generateCells();
    auto getCells() const { return cells; }

private:
    int width {20};
    int height {10};
    std::vector<std::vector<std::shared_ptr<Cell>>> cells;
};


#endif // ROADSMAP_H
