cmake_minimum_required(VERSION 3.17)
project(grafo_secuencial)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafo_secuencial src/ui/main.cpp src/bl/GrafoMatriz.cpp src/bl/GrafoMatriz.h)