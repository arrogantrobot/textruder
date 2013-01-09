#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "CellularAutomaton.h"

using namespace ca;

void CellularAutomaton::initialize() {
    ruleTime = DEFAULT_RULE_TIME;
    lineCount = 0;
    middleCell = width / 2;
    lastCell = width - 1;

    //initialize rule list with aestheticlly pleasing rules
    int rules [] = { 30,57,18,90,129,130,131,132,133 };
    for (int i = 0; i < NUM_RULES; i++)
        ruleBank.push_back(rules[i]);
    rule = DEFAULT_RULE;

    populateMask();
    populateCells();
    resetCells();
}

CellularAutomaton::~CellularAutomaton() { }

void CellularAutomaton::populateMask() {
    for (int i = 0; i < 8; i++)
        mask.push_back((int) pow(2,i));
}

void CellularAutomaton::populateCells() {
    for (int i = 0; i < width; i++) {
        cells.push_back(CELL_OFF);
        newCells.push_back(CELL_OFF);
    }
}

void CellularAutomaton::resetCells() {
    srand((unsigned)time(0) + (unsigned)getpid());
    if (rand() % 2) {
        cells[middleCell] = CELL_ON;
    } else {
        for (int i = 0; i < width; i++)
            if (rand() % 2) cells[i] = CELL_ON;
    }
}

int CellularAutomaton::getCell(int i) {
    int idx = 0;

    //lower cell
    if (i == 0) {
        if (cells[lastCell] == CELL_ON)
            idx |= 1;
    } else {
        if (cells[(i - 1) % width] == CELL_ON) {
            idx |= 1;
        }
    }

    //same cell
    if (cells[i % width] == CELL_ON) {
        idx |= 2;
    }

    //higher cell
    if (i == (lastCell)) {
        if (cells[0] == CELL_ON) {
            idx |= 4;
        }
    } else {
        if (cells[(i + 1) % width] == CELL_ON) {
            idx |= 4;
        }
    }
    return idx;
}

bool CellularAutomaton::resetRequired() {
    return totalLiveCells == width || totalLiveCells == 0;
}

bool CellularAutomaton::ruleChangeRequired() {
    if (lineCount >= ruleTime) {
        lineCount = 0;
        ruleTime = rand() % MAX_RULE_TIME + MIN_RULE_TIME;
        return true;
    }
    return false;
}

void CellularAutomaton::changeRule(int r) {
    rule = r;
}

int CellularAutomaton::getRandomRule() {
    return ruleBank[rand() % NUM_RULES];
}

void CellularAutomaton::update() {
    calcNextRow();
    if (resetRequired()) {
        resetCells();
        changeRule(getRandomRule());
        calcNextRow();
    }

    if (ruleChangeRequired()) {
        changeRule(getRandomRule());
    }
}

void CellularAutomaton::calcNextRow() {
    for (int i = 0; i < width; i++) {
        newCells[i] = ((rule & mask[getCell(i)]) >= 1) ? CELL_ON : CELL_OFF;
    }
    totalLiveCells = 0;
    for (int i = 0; i < width; i++) {
        //assign new cell value AND count living cells
        if((cells[i] = newCells[i]) == CELL_ON)
            totalLiveCells++;
    }
    lineCount++;
}

const std::vector<int>& CellularAutomaton::getRow() {
    update();
    return cells;
}

int CellularAutomaton::getRule() {
    return rule;
}
