cmake_minimum_required(VERSION 3.21.0)

project("AlbedoUtils" 
    LANGUAGES CXX
    VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Explicitly require the standard
set(CMAKE_CXX_EXTENSIONS OFF) # Vendor-specific Extensions

add_subdirectory(include)
add_library(Albedo::utils ALIAS ${PROJECT_NAME})