#pragma once

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Nozzle.h"

#define NUM_RULES 8
#define MIN_RULE_TIME 5
#define MAX_RULE_TIME 50
#define DEFAULT_RULE_TIME 30
#define DEFAULT_RULE 30

enum {
    CELL_OFF = 0,
    CELL_ON
};

class CellularAutomaton: public Nozzle {
public:
    CellularAutomaton(int wide) : Nozzle(wide) { initialize();};
    ~CellularAutomaton();
    void resetCells();
    void calcNextRow();
    const std::vector<int>& getRow();
    int getCell(int index);
    int getRule();

private:
    int rule, defaultRules, lineCount, ruleTime;
    std::vector<int> cells, newCells, mask, ruleBank;

    void initialize();
    void populateMask();
    void populateCells();
    void update();
    void changeRule(int rule);
    bool resetRequired();
    bool ruleChangeRequired();
    int getRandomRule();
};
