#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/RandomRobot.h"


RandomRobot::RandomRobot() : Robot(){
    srand(static_cast<unsigned>(time(0)));
}


int RandomRobot::generaRandomPiastrella(){
    return rand() % 8; 
}

void RandomRobot::move(Maze& maze){
    //genero numero random e in base da 1 a 8 mi muovo nord ovest/nord/ nord est ...
    
    int xIniziale = maze.getPosSX();
    int yIniziale = maze.getPosSY();
    setY(yIniziale);
    setX(xIniziale);
    mosse.push_back({yIniziale,xIniziale});


    
    mosse.clear();
    while(true){
        int piastrella = generaRandomPiastrella();
        int xPiastrella = getX();
        int yPiastrella = getY();
        switch (piastrella)
        {
            case 0: //piastrella nord-ovest
                xPiastrella-=1;
                yPiastrella-=1;
                break;

            case 1: //piastrella nord
                yPiastrella-=1;
                break;

            case 2: //piastrella nord-est
                xPiastrella+=1;
                yPiastrella-=1;
                break;

            case 3: //piastrella est
                xPiastrella+=1;
                break;

            case 4: //piastrella sud-est
                xPiastrella+=1;
                yPiastrella+=1;
                break;

            case 5: //piastrella sud
                yPiastrella+=1;
                break;

            case 6: //piastrella sud-ovest
                xPiastrella-=1;
                yPiastrella+=1;
                break;

            case 7: //piastrella ovest
                xPiastrella-=1;
                break;
            
            default:
                break;
        }

        try{
            char simboloMaze = maze.getCellMaze(yPiastrella,xPiastrella);
            
            std::vector<int> row = {yPiastrella, xPiastrella};

            if(simboloMaze == ' '){
                setX(xPiastrella);
                setY(yPiastrella);

                mosse.push_back(row);
            }
            else if(simboloMaze == 'E'){
                std::cout<<"trovato!!"<<std::endl;
                setX(xPiastrella);
                setY(yPiastrella);
                mosse.push_back(row);
                break;
            }
        }
        catch(Maze::Invalid){
            continue;
        }
    }

    
}

