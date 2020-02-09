cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)

project(perceus)

link_directories(${CMAKE_SOURCE_DIR}/extern/glfw-3.3.2/lib)
include_directories(include extern/glfw-3.3.2/include extern/glew-2.1.0/include)

add_definitions(-D_P_BUILD)

file(GLOB SOURCES "src/*.cpp")

add_library(perceus SHARED ${SOURCES})

target_link_libraries(perceus glfw3 opengl32)