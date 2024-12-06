#include <iostream>
#include "../includes/Maze.h"
#include "../includes/RandomRobot.h"



int main(){
    Maze maze;
    //maze.print();

    RandomRobot robot(maze);
    robot.move();
    robot.print();


    // Robot robot(maze);
    // robot.print();
}