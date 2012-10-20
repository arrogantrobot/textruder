#pragma once

#include <iostream>
#include "Feeder/Feeder.h"
#include "Nozzle/Nozzle.h"

class Textruder {
public:
    Textruder(std::istream *in, std::ostream *out, int width);
    ~Textruder();
    void run();

private:
    std::istream *input;
    std::ostream *output;
    Feeder *feeder;
    Nozzle *nozzle;
    char getChar();
    void printRow(const std::vector<int>& row);
    void initialize(int width);
};
