#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Textruder.h"

using namespace textruder;

Textruder::Textruder(std::istream *in, std::ostream *out, int width,
        int rows_per_second, int _lines) {
    input = in;
    output = out;
    endOfInput = false;
    lines = _lines;
    usec_per_frame = MICROSECONDS_PER_SECOND / rows_per_second;
    nozzle = new ca::CellularAutomaton(width);
}

Textruder::~Textruder() {
    if (nozzle != NULL)
        delete nozzle;
} 

void Textruder::run() {
    struct timespec ts1, ts2, sleepTime, remainingSleep;
    sleepTime.tv_sec = remainingSleep.tv_nsec = 0;
    remainingSleep.tv_sec = 0;
    long usec = 0;
    long linecount = 0;
    bool hit_limit = false;
    //loop until EOF is read from input
    while (!endOfInput) {

        //get time before print row
        clock_gettime(CLOCK_REALTIME, &ts1);
        printRow(nozzle->getRow());
        //get time after print row
        clock_gettime(CLOCK_REALTIME, &ts2);

        //wait for usec_per_frame - time spent in printRow
        usec = (ts2.tv_nsec - ts1.tv_nsec) / NANOSECONDS_PER_MICROSECOND;
        if (usec < 0 || usec > usec_per_frame) {
            usec = 0;
            if (usec_per_frame > 0)
                printf("Time to print the last row was greater than time per frame.\n");
        }
        long waitTime = (usec_per_frame - usec) * 1000;
        sleepTime.tv_nsec = waitTime;
        while(nanosleep(&sleepTime, &sleepTime) == -1) {}
        if (linecount != -1 && linecount++ > lines) {
            hit_limit = true;
            break;
        }
    }
    //send an EOF down the pipe when done
    if(!hit_limit) *output << EOF;
}

void Textruder::setDelayUSec(int delay) {
    usec_per_frame = delay;
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
    char answer = ' ';
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
            found = endOfInput = true;
        }
    } while (!found);

    return answer; 
}  
