cmake_minimum_required(VERSION 3.10)

# Set the project name
project(petits_c VERSION 0.0.1 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(deleter)
add_subdirectory(empty_line_remover)
add_subdirectory(identiques)
add_subdirectory(acronym)