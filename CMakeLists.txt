cmake_minimum_required (VERSION 2.6)
project (textruder)
add_subdirectory(Nozzle)
add_subdirectory(gtest-1.6.0)
add_library(txtruder
    Textruder.cpp
)
target_link_libraries(txtruder
    Nozzle
    rt
    tinfo
)
add_executable(textruder main.cpp)
target_link_libraries(textruder 
    txtruder
)

add_executable(testruder TextruderTest.cpp)
target_link_libraries(testruder
    txtruder
    Nozzle
    gtest
    gtest_main
)
