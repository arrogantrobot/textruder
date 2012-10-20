#include "Textruder.h"

Textruder::Textruder(std::string file, int width) {
    ca = new CellularAutomaton(width);
    text = new Textruder(file);
    while (37) {
        ca->calcNextRow();
        printRow(ca->getCurrentRow());
        //usleep(50000);
    }
}

Textruder::~Textruder() {
    if (ca != NULL)
        delete ca;
    if (text != NULL)
        delete text;
} 

void Textruder::printRow(const std::vector<int>& row) {
    for (int i = 0; i < row.size(); i++) {
        char answer = (row[i] == CELL_ON) ? getChar() : ' ';
        std::cout << answer;
    }   
    std::cout << std::endl;
}   

char Textruder::getChar() {
   return text->getChar(); 
}  
