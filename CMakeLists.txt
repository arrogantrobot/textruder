cmake_minimum_required (VERSION 2.6)
project (clodca)
add_subdirectory(CellularAutomaton)
add_subdirectory(textruder)
add_executable(clodca clodca.cpp ClodcaOutput.cpp)
target_link_libraries(clodca 
    cellular_automaton
    textruder
    ncurses    
)
