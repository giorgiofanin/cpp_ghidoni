#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "Robot.h"


class RandomRobot : public Robot
{
private:
    
public:
    RandomRobot(Maze& maze);
    int generaRandomPiastrella();
    void risolviPercorso();
    virtual void  move() override;
};

#endif