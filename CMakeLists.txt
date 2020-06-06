cmake_minimum_required(VERSION 3.0)
project(pong_raylib C)

set(CMAKE_C_STANDARD 99)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

set(SRC_FILES src/main.c src/objects/paddle.c)
set(SRC_HEADERS src/objects/paddle.h src/globals.h)

add_executable(pong_raylib ${SRC_HEADERS} ${SRC_FILES})
target_link_libraries(pong_raylib PRIVATE raylib)