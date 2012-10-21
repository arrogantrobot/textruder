#include "Feeder.h"

Feeder::~Feeder() {}

void Feeder::load() {
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
        if (endOfInput) {
            return ' ';
        } else {
            load();
        }
    }
    char a = text.front();
    text.pop();
    return  a;
}

bool Feeder::isEndOfInput() {
    return endOfInput;
}

bool Feeder::isCharRemaining() {
    return !text.empty();
}
