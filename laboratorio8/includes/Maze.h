#ifndef MAZE_H
#define MAZE_H

class Maze
{
private:
    static const int ROW = 9;
    static const int COLUMN = 9;
    char arr[ROW][COLUMN];
public:
    class Invalid{};
    Maze();
    void print();
    char getCellMaze();
};




#endif