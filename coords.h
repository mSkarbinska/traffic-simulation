#ifndef COORDS_H
#define COORDS_H

class Coords {
private:
    int row;
    int col;

public:
    Coords();
    Coords(int row, int col) : row(row), col(col) {}

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool operator==(const Coords& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const Coords& other) const {
        return !(*this == other);
    }

    bool operator<(const Coords& other) const {
        return row < other.row || (row == other.row && col < other.col);
    }
};

#endif // COORDS_H
