#pragma once

class Nozzle {
public:
    virtual Nozzle(int width);
    virtual ~Nozzle();
    virtual const std::vector<bool>& getRow();
protected:
    int width;
    std::vector<bool> row;
};
