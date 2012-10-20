#include "Textruder.h"

Textruder::Textruder(std::string file, int width) {
    nozzle = new Nozzle(width);
    feeder = new Feeder(file);
    while (37) {
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
        std::cout << answer;
    }   
    std::cout << std::endl;
}   

char Textruder::getChar() {
   return feeder->getChar(); 
}  
