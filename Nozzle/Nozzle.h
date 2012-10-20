#pragma once

#include <vector>

class Nozzle {
public:
    Nozzle(int w);
    virtual ~Nozzle();
    virtual const std::vector<int>& getRow();
protected:
    int width;
    std::vector<int> row;
};
