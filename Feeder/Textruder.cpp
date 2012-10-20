#include "Feeder.h"

Feeder::Feeder(std::string file) {
    textFile = file;
    load();
}

Feeder::~Feeder() {}

void Feeder::load() {
    std::ifstream incoming(textFile.c_str());
    if (incoming.is_open()) {
        std::string line;
        while (incoming.good()) {
            getline(incoming, line);
            addLine(line);
        }
        incoming.close();
    } else {
        throw 1;
    }

}

void Feeder::addLine(const std::string& line) {
    unsigned int length = line.length();
    for (unsigned int i = 0; i < length; i++) {
        char a = line[i];
        switch(a) {
            case '\t':
            case '\n':
                        break;
            default:    text.push_back(a);
                        break;
        }
    }
}

char Feeder::getChar() {
    if (idx >= text.size()) {
        idx = 0;
    }
    return text[idx++];
}
