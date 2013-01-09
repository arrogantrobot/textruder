#pragma once

#include <iostream>
#include "Nozzle/CellularAutomaton.h"

namespace textruder {

#define NANOSECONDS_PER_MICROSECOND 1000
#define MICROSECONDS_PER_SECOND 1000000

    /**
     * Textruder class, coordinate the feed
     * and nozzle, regulate flow rate
     */
    class Textruder {
    public:

        /**
         * @param in istream, source of text to extrude
         * @param out ostream, destination of the extruded result
         * @param width int, width in characters
         */
        Textruder(std::istream *in, std::ostream *out, int width, 
                int _row_per_second);

        /**
         * Destructor
         */
        ~Textruder();

        /**
         * Once the components are ready, launch the
         * output by calling run()
         */
        void run();

        /** 
         * Time between outputing rows, in milliseconds
         */
        void setDelayUSec(int delay);

    private:

        /**
         * Neither the input nor the output streams
         * will be closed or deallocated
         */
        std::istream *input;
        std::ostream *output;

        long usec_per_frame;
        bool endOfInput;

        /**
         * Nozzle deallocated by the destructor
         */
        Nozzle *nozzle;

        /**
         * Return a single character from the input
         * Will not be a tab or newline
         */
        char getChar();
        void printRow(const std::vector<int>& row);
        void initialize(int width);
    };
}// namespace textruder
