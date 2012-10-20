cmake_minimum_required (VERSION 2.6)
project (textruder)
add_subdirectory(CellularAutomaton)
add_subdirectory(Feeder)
add_subdirectory(Nozzle)
add_executable(textruder main.cpp Textruder.cpp)
target_link_libraries(textruder 
    cellular_automaton
    Feeder
    Nozzle
)
