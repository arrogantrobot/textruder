#include "Nozzle.h"

Nozzle::Nozzle(int w) {
    width = (w > 0) ? w : 1;
    for (int i = 0; i < width; i++)
        row.push_back(true);
}

const std::vector<bool>& Nozzle::getRow() {
    return row;
}
