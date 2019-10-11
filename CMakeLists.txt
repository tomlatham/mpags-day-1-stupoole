cmake_minimum_required(VERSION 3.15)
project(mpags-cipher.git)

set(CMAKE_CXX_STANDARD 11)

add_executable(mpags-cipher.o MPAGSCipher.h MPAGSCipher.cpp)