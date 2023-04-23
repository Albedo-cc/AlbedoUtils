# include <AlbedoPattern.hpp>

# Create library
set(ALBEDO_UTILS_HEADERS 
    AlbedoTime.hpp
    AlbedoPattern.hpp)

add_library(${PROJECT_NAME} INTERFACE ${ALBEDO_UTILS_HEADERS})

source_group("" FILES ${ALBEDO_UTILS_HEADERS})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})