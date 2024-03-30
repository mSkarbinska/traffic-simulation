#ifndef ROADSMAP_H
#define ROADSMAP_H

#include "cell.h"

class RoadsMap {
public:
    RoadsMap(int width, int height, const std::vector<std::vector<CellType>>& cellTypes);
    std::shared_ptr<Cell> getCellAt(int row, int col) const;
    std::vector<std::shared_ptr<Cell>> getAdjacentCells(int row, int col) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Cell>>> cells;
};


#endif // ROADSMAP_H
