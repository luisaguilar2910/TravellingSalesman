project(TravellingSalesman)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)
include_directories(src)


file(GLOB SOURCES
        include/*.h
        src/*.cpp
    )

add_subdirectory(lib)
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} CityLib)
target_link_libraries(${PROJECT_NAME} CityUtilsLib)
target_link_libraries(${PROJECT_NAME} IndividualLib)
