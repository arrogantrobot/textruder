#include "Feeder.h"

Feeder::~Feeder() {}

/*void Feeder::load() {
    std::string line;
    if (input.good()) {
        getline(input, line);
        addLine(line);
    } else {
        endOfInput = true;
    }
}*/

void Feeder::load() {//const std::string& line) {
    int read_ahead = READ_AHEAD;
    for (unsigned int i = 0; i < read_ahead; i++) {
        if (!input->eof()) {
            char a;
            input->get(a);
            switch(a) {
                case '\t':
                case '\n':
                            break;
                default:    text.push(a);
                            break;
            }
        } else {
            endOfInput = true;
        }
    }
}

char Feeder::getChar() {
    if (text.empty()) {
        load();
    }
    char a = text.front();
    text.pop();
    return  a;
}

bool Feeder::isEndOfInput() {
    return endOfInput;
}
