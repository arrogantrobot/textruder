#include "Nozzle.h"

Nozzle::Nozzle(int w) {
    width = (w > 0) ? w : 1;
    for (int i = 0; i < width; i++)
        row.push_back(1);
}

Nozzle::~Nozzle() {}

const std::vector<int>& Nozzle::getRow() {
    return row;
}
