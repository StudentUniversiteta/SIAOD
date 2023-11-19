cmake_minimum_required(VERSION 3.26)
project(untitled)
set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        SIAOD/v7/S2/n1/File.cpp
        SIAOD/v7/S2/n1/File.h
        SIAOD/v7/S2/n1/main.cpp
)
add_executable(untitled2
        TESTING_GROUND/n2/vuz.h
        TESTING_GROUND/n2/vuz.cpp
        TESTING_GROUND/n2/main2.cpp
)
add_executable(untitled3 SIAOD/v4/S2/n1/main.cpp)
add_executable(SIAOD_2B_e2 SIAOD/v4/S2/n2/main.cpp
        SIAOD/v4/S2/n2/car.cpp
        SIAOD/v4/S2/n2/car.h)
add_executable(TESTER TESTING_GROUND/S2/main.cpp)
add_executable(newn2 SIAOD/v7/S2/newn2/vuz.cpp SIAOD/v7/S2/newn2/vuz.h
        SIAOD/v7/S2/newn2/main.cpp)
add_executable(S-A_3-1 SIAOD/v7/S3/n1/main.cpp
        SIAOD/v7/S3/n1/File.cpp
        SIAOD/v7/S3/n1/File.h
        SIAOD/v7/S3/n1/HashTable.cpp
        SIAOD/v7/S3/n1/HashTable.h
        SIAOD/v7/S3/n1/HashFile.cpp
        SIAOD/v7/S3/n1/HashFile.h)
add_executable(S-B_3-1 SIAOD/v4/S3/n1/File.cpp
        SIAOD/v4/S3/n1/File.h
        SIAOD/v4/S3/n1/HashFile.cpp
        SIAOD/v4/S3/n1/HashFile.h
        SIAOD/v4/S3/n1/HashTable.cpp
        SIAOD/v4/S3/n1/HashTable.h
        SIAOD/v4/S3/n1/main.cpp)
