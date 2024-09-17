cmake_minimum_required(VERSION 3.10)

# Set the project name
project(identiques VERSION 0.0.1 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(identiques identiques.c)

# Add compile options
target_compile_options(identiques PRIVATE -Wall -Wextra)