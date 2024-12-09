#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../includes/RightHandRuleRobot.h"


RightHandRuleRobot::RightHandRuleRobot() : Robot(){
    srand(static_cast<unsigned>(time(0)));
}

int RightHandRuleRobot::generaRandomPiastrella(){
    return rand() % 8;
}



void RightHandRuleRobot::move(Maze& maze) {
    
    //imposto la prima mossa che è la piastrella dove si trova R

    int xIniziale = maze.getPosSX();
    int yIniziale = maze.getPosSY();
    setY(yIniziale);
    setX(xIniziale);
    mosse.push_back({yIniziale,xIniziale});
    
    int xPiastrella = getX();
    int yPiastrella = getY();
    
    mosse.clear();

    bool muro = false;
    bool loop = false;

    while (!muro) {
        for (int i = 1; i < 8; i += 2) {
            try {
                if (maze.getCellMaze(getCoordinatePiastrellaVicina(i)[0], getCoordinatePiastrellaVicina(i)[1]) == '*') {
                    muro = true;
                    destra = i;
                    break;
                }
            } catch (Maze::Invalid&) {
                continue;  // Se le coordinate sono invalid, salta al prossimo controllo
            }
        }

        if (!muro) {
            bool check = false;
            while (!check) {
                try {
                    int piastrella = generaRandomPiastrella();

                    if (maze.getCellMaze(getCoordinatePiastrellaVicina(piastrella)[0], getCoordinatePiastrellaVicina(piastrella)[1]) == 'E') {
                        check = true;
                        setY(getCoordinatePiastrellaVicina(piastrella)[0]);
                        setX(getCoordinatePiastrellaVicina(piastrella)[1]);
                        mosse.push_back(getCoordinatePiastrellaVicina(piastrella));
                        loop = true;
                        break;
                    } else if (maze.getCellMaze(getCoordinatePiastrellaVicina(piastrella)[0], getCoordinatePiastrellaVicina(piastrella)[1]) == ' ') {
                        check = true;
                        setY(getCoordinatePiastrellaVicina(piastrella)[0]);
                        setX(getCoordinatePiastrellaVicina(piastrella)[1]);
                        mosse.push_back(getCoordinatePiastrellaVicina(piastrella));
                        break;
                    }
                } catch (Maze::Invalid&) {
                    continue;  // Se le coordinate sono invalid, riprova
                }
            }
        }
    }

    while (!loop) {
        try {
            int direzione = getDirezione(yPiastrella, xPiastrella);

            if (direzione == 100) {
                mosse.push_back(getCoordinatePiastrellaVicina(destra));
                yPiastrella = getCoordinatePiastrellaVicina(destra)[0];
                xPiastrella = getCoordinatePiastrellaVicina(destra)[1];
                setX(xPiastrella);
                setY(yPiastrella);
                loop = true;
            } else if (direzione != -1 && maze.getCellMaze(getCoordinatePiastrellaVicina(direzione)[0], getCoordinatePiastrellaVicina(direzione)[1]) == ' ') {
                mosse.push_back(getCoordinatePiastrellaVicina(direzione));
                yPiastrella = getCoordinatePiastrellaVicina(direzione)[0];
                xPiastrella = getCoordinatePiastrellaVicina(direzione)[1];
                setX(xPiastrella);
                setY(yPiastrella);
            }
        } catch (Maze::Invalid&) {
            continue;  // Se le coordinate sono invalid, riprova
        }
    }
}


int RightHandRuleRobot::getDirezione(int y,int x){

    try{

        
        //caso destra uscita

        if(maze.getCellMaze(getCoordinatePiastrellaVicina(destra)[0],getCoordinatePiastrellaVicina(destra)[1]) == 'E'){
            return 100;
        }    

        //angoli interni

        
        if(maze.getCellMaze(getCoordinatePiastrellaVicina(destra)[0],getCoordinatePiastrellaVicina(destra)[1]) == '*' && maze.getCellMaze(getCoordinatePiastrellaVicina(((destra-2+8)%8))[0],getCoordinatePiastrellaVicina(((destra-2+8)%8))[1]) == '*' ){
            int destraCopy = destra;
            destra = ((destra - 2 + 8) % 8);

            return ((destraCopy - 4 + 8) % 8);
        }


        //nei casi dove non ci sono angoli

        else if(maze.getCellMaze(getCoordinatePiastrellaVicina(destra)[0],getCoordinatePiastrellaVicina(destra)[1]) == '*'){
            return (destra - 2 + 8) % 8;
        }

       
        // nei casi angolo esterno

        //se sud-est(4) = '*' va a est(3)
        else if(maze.getCellMaze(getCoordinatePiastrellaVicina(((destra+1+8)%8))[0],getCoordinatePiastrellaVicina(((destra+1+8)%8))[1]) == '*'){
            //std::cout<<"entra quii";
            int destraCopy = destra;
            destra = ((destra +2 +8)%8);
            return destraCopy;
        }
        

        else{
            return -1;
        }
    }
    catch(Maze::Invalid){
        return -1;
    }
}

std::vector<int> RightHandRuleRobot::getCoordinatePiastrellaVicina(int nPiastrella){
    
    int xPiastrella = getX();
    int yPiastrella = getY();
    
    switch (nPiastrella){
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

    return {yPiastrella,xPiastrella};
}