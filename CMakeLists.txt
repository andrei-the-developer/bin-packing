cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp bin.h next_fit.h first_fit.h IBinPack.h best_fit.h first_fit_decreasing.h best_fit_decreasing.h helper.h supervisor.h)
