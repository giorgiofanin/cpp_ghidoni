#include <iostream>
#include <fstream>
#include <string>
#include "../includes/Maze.h"

Maze::Maze(){
    std::ifstream MyReadFile("maze.txt");
    std::string myText;

    int row = 0;
    while (getline(MyReadFile, myText) && row < ROW) {
        
        for(int i = 0; i < myText.length() && i < COLUMN;i++){ 
            arr[row][i] = myText[i];
        }
        for (int i = myText.length(); i < COLUMN; i++) {
            arr[row][i] = ' ';
        }
        row++;
    }

    MyReadFile.close();
}


void Maze::print(){
    for(int row = 0; row < ROW; row++){
        for(int column = 0; column < COLUMN; column++){
            std::cout<< arr[row][column];
        }
        std::cout<<std::endl;
    }
}

char Maze::getCellMaze(int y,int x){
    if(y>= 9 || y<0 || x<0 || x>=9){
        Maze::Invalid{};
    }
    return arr[y][x];
}



int main(){
    Maze maze;
    maze.print();
    return 0;
}
    



