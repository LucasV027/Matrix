project(Solver)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "Sources/*.cpp")
file(GLOB_RECURSE HEADERS "Sources/*.h")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})