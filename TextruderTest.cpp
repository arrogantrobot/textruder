#include <fstream>
#include "Textruder.h"
#include "gtest/gtest.h"
#include "Nozzle/CellularAutomaton.h"

#define DEFAULT_WIDTH 80
#define ABSURD_WIDTH 800
#define DEFAULT_RATE 30
#define ABSURD_RATE 1000
#define TEST_INPUT "license.txt"
#define FIRST_ROW_WIDTH 6
#define SECOND_ROW_WIDTH 0
#define THIRD_ROW_WIDTH 3
#define FIRST_ROW_ABSURD_WIDTH 0
#define SECOND_ROW_ABSURD_WIDTH 6
#define THIRD_ROW_ABSURD_WIDTH 0

TEST(TextruderTest, NozzleNormal) {
    Nozzle nozzle(DEFAULT_WIDTH);
    std::vector<int> row = nozzle.getRow();

    EXPECT_EQ(row.size(), DEFAULT_WIDTH);
    std::vector<int> row_two = nozzle.getRow();

    EXPECT_EQ(row.size(), row_two.size());
}

TEST(TextruderTest, NozzleAbsurd) {

    Nozzle nozzle(ABSURD_WIDTH);
    std::vector<int> row = nozzle.getRow();

    EXPECT_EQ(row.size(), ABSURD_WIDTH);
    std::vector<int> row_two = nozzle.getRow();

    EXPECT_EQ(row.size(), row_two.size());
}

TEST(TextruderTest, CellularAutomatonNormal) {
    ca::CellularAutomaton cellularAutomaton(DEFAULT_WIDTH);
    std::vector<int> row = cellularAutomaton.getRow();

    EXPECT_EQ(row.size(), DEFAULT_WIDTH);
    std::vector<int> row_two = cellularAutomaton.getRow();

    EXPECT_NE(row, row_two);

    EXPECT_EQ(row.size(), row_two.size());
} 

TEST(TextruderTest, CellularAutomatonAbsurd) {
    ca::CellularAutomaton cellularAutomaton(ABSURD_WIDTH);
    std::vector<int> row = cellularAutomaton.getRow();

    EXPECT_EQ(row.size(), ABSURD_WIDTH);
    std::vector<int> row_two = cellularAutomaton.getRow();

    EXPECT_NE(row, row_two);

    EXPECT_EQ(row.size(), row_two.size());
} 

TEST(TextruderTest, TextruderNormal) {

    std::ostream* output = &std::cout;
    std::ifstream inputFileStream;

    inputFileStream.open(TEST_INPUT, std::ifstream::in);
    std::istream* input = &inputFileStream;

    //http://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
    std::stringstream coutBuffer;
    std::streambuf *sbuf = output->rdbuf();
    std::cout.rdbuf(coutBuffer.rdbuf());
    textruder::Textruder textruder(input, output, DEFAULT_WIDTH, DEFAULT_RATE);
    textruder.setDelayUSec(0);
    textruder.run();

    //return cout to its natural habitat
    std::cout.rdbuf(sbuf);
}

TEST(TextruderTest, TextruderAbsurd) {

    std::ifstream inputFileStream;

    inputFileStream.open(TEST_INPUT, std::ifstream::in);
    std::istream* input = &inputFileStream;

    //http://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
    std::stringstream coutBuffer;
    std::ostream* output = &std::cout;
    std::streambuf *sbuf = output->rdbuf();
    std::cout.rdbuf(coutBuffer.rdbuf());
    textruder::Textruder textruder(input, output, ABSURD_WIDTH, ABSURD_RATE);
    textruder.setDelayUSec(0);
    textruder.run();

    //return cout to its natural habitat
    std::cout.rdbuf(sbuf);
}
