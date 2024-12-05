#ifndef ROBOT_H
#define ROBOT_H
#include "Maze.h"


class Robot
{
private:
    int x;
    int y;
public:
    Robot(Maze& maze);
    virtual void move(int x,int y);
    void print();
};

#endif

