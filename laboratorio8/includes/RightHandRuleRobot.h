#ifndef RIGHTHANDRULEROBOT_H
#define RIGHTHANDRULEROBOT_H

#include "Robot.h"


class RightHandRuleRobot : public Robot
{
private:
    int destra;
public:
    RightHandRuleRobot();
    int generaRandomPiastrella();
    int getDirezione(int y,int x);
    std::vector<int> getCoordinatePiastrellaVicina(int nPiastrella);
    virtual void  move(Maze& maze) override;
};


#endif