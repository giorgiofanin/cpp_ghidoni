#include <iostream>
#include "../includes/Maze.h"
#include "../includes/RandomRobot.h"
#include "../includes/RightHandRuleRobot.h"



int main(){
    Maze maze;
    maze.print();

    RandomRobot robot;
    robot.move(maze);
    robot.print();

    RightHandRuleRobot robotRight;
    robotRight.move(maze);
    robotRight.print();


    // Robot robot(maze);
    // robot.print();
}