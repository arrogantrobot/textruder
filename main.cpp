#include <iostream>
#include <string.h>
#include "Textruder.h"

int main(int argc, char * argv[]) {
    int width = (argc == 1) ? 80 : atoi(argv[2]);
    std::string textFile;
    if (argc == 3) {
        textFile = argv[1];
    }
    Textruder(textFile, width);
    return 0;
}
