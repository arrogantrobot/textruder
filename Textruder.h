#pragma once

#include <iostream>
#include "CellularAutomaton/CellularAutomaton.h"
#include "textruder/Textruder.h"

class Textruder {
public:
    Textruder(std::string file, int width);
    ~Textruder();

private:
    Textruder *text;
    CellularAutomaton *ca;
    char getChar();
    void printRow(const std::vector<int>& row);
};
