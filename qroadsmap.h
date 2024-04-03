#ifndef QROADSMAP_H
#define QROADSMAP_H

#include <QWidget>
#include <vector>

#include "cell.h"
#include "roadsmap.h"

class QRoadsMap : public QWidget
{
    Q_OBJECT
public:
    explicit QRoadsMap(RoadsMap &map, QWidget *parent = nullptr);

    void setCellType(int row, int col, CellType type);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int cellSize {50};
    RoadsMap &map;
    std::vector<std::vector<CellType>> mapGrid;
};

#endif // QROADSMAP_H
