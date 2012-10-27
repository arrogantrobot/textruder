#pragma once

#include <sys/time.h>
#include <iostream>
#include "Feeder/Feeder.h"
#include "Nozzle/Nozzle.h"
#include "Nozzle/CellularAutomaton.h"

class Textruder {
public:
    Textruder(std::istream *in, std::ostream *out, int width);
    ~Textruder();
    void run();
    void setDelayMSec(int delay);

private:
    std::istream *input;
    std::ostream *output;
    int usec_per_frame;
    bool endOfInput;
    Feeder *feeder;
    Nozzle *nozzle;
    char getChar();
    void printRow(const std::vector<int>& row);
    void initialize(int width);
};
