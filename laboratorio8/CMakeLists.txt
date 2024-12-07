cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(MazeRobot)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Indica le directory contenenti i file header
include_directories(includes)
add_executable(MazeRobot
    src/main.cpp
    src/Maze.cpp
    src/Robot.cpp
    src/RandomRobot.cpp
    src/RightHandRuleRobot.cpp
)

