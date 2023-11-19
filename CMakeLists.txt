cmake_minimum_required(VERSION 3.26)
project(untitled)
set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        SIAOD/A/S2/n1/File.cpp
        SIAOD/A/S2/n1/File.h
        SIAOD/A/S2/n1/main.cpp
)
add_executable(untitled2
        TESTING_GROUND/n2/vuz.h
        TESTING_GROUND/n2/vuz.cpp
        TESTING_GROUND/n2/main2.cpp
)
add_executable(untitled3 SIAOD/B/S2/n1/main.cpp)
add_executable(SIAOD_2B_e2 SIAOD/B/S2/n2/main.cpp
        SIAOD/B/S2/n2/car.cpp
        SIAOD/B/S2/n2/car.h)
add_executable(TESTER TESTING_GROUND/S2/main.cpp)
add_executable(newn2 SIAOD/A/S2/newn2/vuz.cpp SIAOD/A/S2/newn2/vuz.h
        SIAOD/A/S2/newn2/main.cpp)
