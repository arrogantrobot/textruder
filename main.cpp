#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "Textruder.h"
#include <getopt.h>
#include <ncurses.h>
#include <sys/ioctl.h>

int getTerminalWidth() {
    /*
    int x,y;
    initscr();
    getmaxyx(stdscr,x,y);
    return x;*/
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int main(int argc, char * argv[]) {
    int optionChar;
    std::string inputFile = "", outputFile = "", wide;
    while ((optionChar = getopt(argc,argv,"i:o:w:")) != -1) {
        switch(optionChar) {
            case 'i':   inputFile = optarg;
                        break;
            case 'o':   outputFile = optarg;
                        break;
            case 'w':   wide = optarg;
                        break;
            case '?':   
                        std::cout << "unknown argument: " << optopt << std::endl;

        }
    }
    
    int width;
    if (wide == "") {
        width = getTerminalWidth();
    } else {
        width = atoi(wide.c_str());
    }
    std::istream* input = &std::cin;
    std::ostream* output = &std::cout;

    std::ofstream outputFileStream;
    if (outputFile != "") {
        outputFileStream.open(outputFile.c_str(), std::ofstream::out);
        output = &outputFileStream;
    }
    std::ifstream inputFileStream;
    if (inputFile != "") {
        inputFileStream.open(inputFile.c_str(), std::ifstream::in);
        input = &inputFileStream;
    }

    Textruder textruder(input, output, width);
    textruder.run();

    if (inputFile != "") {
        inputFileStream.close();
    }
    if (outputFile != "") {
        outputFileStream.close();
    }
    return 0;
}
