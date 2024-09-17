cmake_minimum_required(VERSION 3.10)

# Set the project name
project(acronym VERSION 0.0.1 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(acronym acronym.c)

# Add compile options
target_compile_options(acronym PRIVATE -Wall -Wextra)