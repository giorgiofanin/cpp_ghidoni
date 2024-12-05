#ifndef MAZE_H
#define MAZE_H

class Maze
{
private:
    static const int ROW = 9;
    static const int COLUMN = 9;
    char arr[ROW][COLUMN];
    int posSX;
    int posSY;
public:
    class Invalid{};
    Maze();
    int getPosSX(){return posSX;};
    int getPosSY(){return posSY;};
    void print();
    char getCellMaze(int x,int y);
};




#endif