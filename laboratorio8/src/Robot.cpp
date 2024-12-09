#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/Robot.h"

Robot::Robot(){}



void Robot::print()
{

    std::vector<std::vector<char>> mazeMap = maze.getMazeMap();

    
    
    

    for (int i = 0; i < mosse.size(); i++)
    {
        
        std::cout << "mosse fatte :" << mosse.size()<< std::endl;

        for (int row = 0; row < maze.getRow(); row++)
        {
            for (int column = 0; column < maze.getColumn(); column++)
            {
                if(column == mosse[i][1] && row == mosse[i][0]){
                    std::cout << 'R';
                }
                else{
                    std::cout << mazeMap[row][column];
                }
                
            }
            std::cout << std::endl;
        }
        usleep(100000);
        system("clear");
        
    }


    std::cout << "mosse fatte :" << mosse.size()<< std::endl;

    for (int row = 0; row < maze.getRow(); row++)
    {
        for (int column = 0; column < maze.getColumn(); column++)
        {
            if(column == mosse[mosse.size()-1][1] && row == mosse[mosse.size()-1][0]){
                std::cout << 'R';
            }
            else{
                std::cout << mazeMap[row][column];
            }
            
        }
        std::cout << std::endl;
    }
}
