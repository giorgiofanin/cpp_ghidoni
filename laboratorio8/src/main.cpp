#include <iostream>
#include "../includes/Maze.h"
#include "../includes/RandomRobot.h"
#include "../includes/RightHandRuleRobot.h"



int main(){
    Maze maze;
    //maze.print();

    // RandomRobot robot(maze);
    // robot.move();
    // robot.print();

    RightHandRuleRobot robotRight(maze);
    robotRight.move();
    robotRight.print();


    // Robot robot(maze);
    // robot.print();
}