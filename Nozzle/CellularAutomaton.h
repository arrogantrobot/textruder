#pragma once

#include <vector>
#include "Nozzle.h"

namespace ca {

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

    private:
        const std::vector<int>& getRow();
        int getCell(int index);
        int getRule();
        int rule, defaultRules, lineCount, ruleTime;
        int middleCell, lastCell;
        int totalLiveCells;
        std::vector<int> cells, newCells, mask, ruleBank;

        void resetCells();
        void calcNextRow();
        void initialize();
        void populateMask();
        void populateCells();
        void update();
        void changeRule(int rule);
        bool resetRequired();
        bool ruleChangeRequired();
        int getRandomRule();
    };

} // ca namespace
