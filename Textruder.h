#pragma once

#include <iostream>
#include "Feeder/Feeder.h"
#include "Nozzle/Nozzle.h"

class Textruder {
public:
    Textruder(std::string file, int width);
    ~Textruder();

private:
    Feeder *feeder;
    Nozzle *nozzle;
    char getChar();
    void printRow(const std::vector<int>& row);
};
