#ifndef ROBOT_H
#define ROBOT_H
#include "Maze.h"
#include <vector>
#include <string>

class Robot
{
private:
    int x;
    int y;

protected:
    std::vector<std::vector<int>> mosse;
    Maze maze;
public:
    Robot();
    virtual void move(Maze& maze) = 0;
    void print();
    int getX(){return x;};
    int getY(){return y;};
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}

};

#endif

