#pragma once

#include <string>
#include <fstream>

class Feeder {
public:
    Feeder(std::string file);
    ~Feeder();
    char getChar();
    void addLine(const std::string& line);
    bool isLoaded();
    void load();

private:
    std::vector<char> text;
    int idx;
    std::string textFile;
};
