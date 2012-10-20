#pragma once

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_RULES 8
#define MIN_RULE_TIME 5
#define MAX_RULE_TIME 50
#define DEFAULT_RULE_TIME 20
#define DEFAULT_RULE 30

enum {
    CELL_OFF = 0,
    CELL_ON
};

class CellularAutomaton {
public:
    CellularAutomaton(int width);
    ~CellularAutomaton();
    void resetCells();
    void calcNextRow();
    const std::vector<int>& getCurrentRow() const;
    int getCell(int index);
    int getRule();

private:
    int width, rule, defaultRules, lineCount, ruleTime;
    std::vector<int> cells, newCells, mask, ruleBank;

    void populateMask();
    void populateCells();
    void changeRule(int rule);
    bool resetRequired();
    bool ruleChangeRequired();
    int getRandomRule();
};