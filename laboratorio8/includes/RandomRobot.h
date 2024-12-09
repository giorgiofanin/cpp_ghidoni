#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "Robot.h"


class RandomRobot : public Robot
{
public:
    RandomRobot();
    int generaRandomPiastrella();
    virtual void  move(Maze& maze) override;
};

#endif