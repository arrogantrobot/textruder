#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/ioctl.h>

#include "Textruder.h"

#define DEFAULT_ROWS_PER_SECOND 30

int getTermWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void usage() {
    printf("usage:\t./textruder [options]\n");
    printf("\t-i\tinput ascii file (default stdin)\n");
    printf("\t-o\toutput file (default stdout)\n");
    printf("\t-w\twidth (default terminal width, %d)\n", getTermWidth());
    printf("\t-r\trows per second (default %d)\n\n", DEFAULT_ROWS_PER_SECOND);

    exit(-1);
}

int main(int argc, char * argv[]) {
    int optionChar;
    int rows_per_second = DEFAULT_ROWS_PER_SECOND;
    std::string inputFile = "", outputFile = "", wide;
    while ((optionChar = getopt(argc,argv,"i:o:w:r:h")) != -1) {
        switch(optionChar) {
            case 'i':   inputFile = optarg; //input
                        break;
            case 'o':   outputFile = optarg; //output
                        break;
            case 'w':   wide = optarg; //width
                        break;
            case 'r':   rows_per_second = atoi(optarg); //rate
                        break;

            case '?':   printf("unknown argument: %c\n", optopt);
            case 'h':   usage();
        }
    }
    
    //set width of output
    int width;
    if (wide == "") {
        width = getTermWidth();
    } else {
        width = atoi(wide.c_str());
    }

    //initialize input and output streams
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

    //create a textruder and remove delay if outputting to a file
    textruder::Textruder textruder(input, output, width, rows_per_second);
    if (outputFile != "") {
        textruder.setDelayUSec(0);
    }
    textruder.run();

    //close down streams
    if (inputFile != "") {
        inputFileStream.close();
    }
    if (outputFile != "") {
        outputFileStream.close();
    }
    return 0;
}
