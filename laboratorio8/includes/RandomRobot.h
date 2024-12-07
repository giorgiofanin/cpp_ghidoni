#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "Robot.h"


class RandomRobot : public Robot
{
public:
    RandomRobot(Maze& maze);
    int generaRandomPiastrella();
    virtual void  move() override;
};

#endif