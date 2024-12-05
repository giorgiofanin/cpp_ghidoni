#include <iostream>
#include "../includes/Robot.h"


Robot::Robot(Maze& maze){
    move(maze.getPosSX(),maze.getPosSY());
}

void Robot::move(int x,int y){
    this->x = x;
    this->y = y;
}

void Robot::print(){
    std::cout<<"posizione "<<x<< " "<<y;
}


int main(){
    Maze maze;
    maze.print();
    Robot robot(maze);
    robot.print();
}