#include "Textruder.h"

Textruder::Textruder(std::istream *in, std::ostream *out, int width) {
    input = in;
    output = out;
    nozzle = new Nozzle(width);
    feeder = new Feeder(input);
}

void Textruder::run() {
    while (!feeder->isEndOfInput()) {
        printRow(nozzle->getRow());
        //usleep(50000);
    }
}

Textruder::~Textruder() {
    if (feeder != NULL)
        delete feeder;
    if (nozzle != NULL)
        delete nozzle;
} 

void Textruder::printRow(const std::vector<int>& row) {
    for (int i = 0; i < row.size(); i++) {
        char answer = (row[i]) ? getChar() : ' ';
        *output << answer;
    }   
    *output << std::endl;
}   

char Textruder::getChar() {
   return feeder->getChar(); 
}  
