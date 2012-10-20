cmake_minimum_required (VERSION 2.6)
project (textruder)
add_subdirectory(Feeder)
add_subdirectory(Nozzle)
add_library(txtruder
    Textruder.cpp
)
target_link_libraries(txtruder
    Feeder
    Nozzle
)
add_executable(textruder main.cpp)
target_link_libraries(textruder 
    txtruder
)
