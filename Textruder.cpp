#include "Textruder.h"

Textruder::Textruder(std::istream *in, std::ostream *out, int width) {
    input = in;
    output = out;
    endOfInput = false;
    usec_per_frame = 35000;
    nozzle = new CellularAutomaton(width);
}

void Textruder::run() {
    struct timespec ts1, ts2;
    long usec = 0;
    while (!endOfInput) {
        clock_gettime(CLOCK_REALTIME, &ts1);
        printRow(nozzle->getRow());
        clock_gettime(CLOCK_REALTIME, &ts2);
        usec = (ts2.tv_nsec - ts1.tv_nsec)/1000;
        if (usec < 0 || usec > usec_per_frame) {
            usec = 0;
        }
        usleep(usec_per_frame - usec);
    }
}

void Textruder::setDelayMSec(int delay) {
    usec_per_frame = delay;
}

Textruder::~Textruder() {
    if (feeder != NULL)
        delete feeder;
    if (nozzle != NULL)
        delete nozzle;
} 

void Textruder::printRow(const std::vector<int>& row) {
    int size = row.size();
    for (int i = 0; i < size; i++) {
        char answer = (row[i]) ? getChar() : ' ';
        *output << answer;
    }   
    *output << std::endl;
}   

char Textruder::getChar() {
    char answer;
    bool found = false;
    do {
        if (!input->eof()) {
            input->get(answer);
            switch(answer) {
                case '\t':
                case '\n':
                            break;
                default:    found = true;
                            break;
            }
        } else {

        }
    } while (!found);
    return answer; 
}  
