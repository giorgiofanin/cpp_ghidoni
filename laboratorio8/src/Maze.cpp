#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../includes/Maze.h"

Maze::Maze() {
    std::ifstream MyReadFile("../build/maze.txt");
    if (!MyReadFile.is_open()) {
        throw std::runtime_error("Impossibile aprire il file maze.txt");
    }

    std::string myText;
    int row = 0;
    while (getline(MyReadFile, myText) && row < ROW) {
        std::vector<char> rowMap;
        for (int i = 0; i < myText.length() && i < COLUMN; i++) {
            rowMap.push_back(myText[i]);
            if (myText[i] == 'S') {
                posSX = i;
                posSY = row;
            }
        }
        for (int i = myText.length(); i < COLUMN; i++) {
            rowMap.push_back(' ');  // Completa la riga
        }
        mazeMap.push_back(rowMap);
        row++;
    }
    MyReadFile.close();
}



void Maze::print(){
    
    for(int row = 0; row < ROW && mazeMap.size(); row++){
        for(int column = 0; column < COLUMN && column < mazeMap[row].size(); column++){
            std::cout<< mazeMap[row][column];
        }
        std::cout<<std::endl;
    }
}



char Maze::getCellMaze(int y,int x){
    if(y>= 9 || y<0 || x<0 || x>=9){
        throw Maze::Invalid{};
    }
    return (char)mazeMap[y][x];
}



// int main(){
//     Maze maze;
//     maze.print();
//     return 0;
// }
    



