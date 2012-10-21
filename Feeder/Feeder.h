#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <queue>

#define READ_AHEAD 100;

class Feeder {
public:
    Feeder(std::istream *in){ 
        endOfInput = false; 
        input = in;
    };
    ~Feeder();
    char getChar();
    bool isEndOfInput();
    bool isCharRemaining();

private:
    std::queue<char> text;
    std::istream *input;
    bool endOfInput;
    void load();
};
