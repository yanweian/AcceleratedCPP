# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(Project)

aux_source_directory(src/ DIR_SRCS)

# Add all the source files needed to build the executable
add_executable(main ${DIR_SRCS})
