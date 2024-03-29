#ifndef QROADSMAP_H
#define QROADSMAP_H

#include <QWidget>
#include <vector>

enum CellType {
    Empty,
    Intersection,
    StraightRoad,
    Turn
};

class QRoadsMap : public QWidget
{
    Q_OBJECT
public:
    explicit QRoadsMap(QWidget *parent = nullptr);

    void setCellType(int row, int col, CellType type);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int rows;
    int cols;
    int cellSize; // Size of each cell in pixels
    std::vector<std::vector<CellType>> mapGrid;
};

#endif // QROADSMAP_H
