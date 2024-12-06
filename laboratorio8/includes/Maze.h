#ifndef MAZE_H
#define MAZE_H

#include "vector"

class Maze
{
private:
    static const int ROW = 9;
    static const int COLUMN = 9;
    std::vector<std::vector<char>> mazeMap;
    int posSX;
    int posSY;
public:

    class Invalid{};
    Maze();
    int getPosSX(){return posSX;};
    int getPosSY(){return posSY;};
    void print();
    char getCellMaze(int x,int y);
    int getRow(){return ROW;};
    int getColumn(){return COLUMN;};
    std::vector<std::vector<char>> getMazeMap(){return mazeMap;};
};




#endif