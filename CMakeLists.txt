cmake_minimum_required(VERSION 3.26)
project(petits_c C)

set(CMAKE_C_STANDARD 11)

add_executable(acronym
        acronym/acronym.c)

# Set the output directory for the executable
set_target_properties(acronym PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/acronym)
