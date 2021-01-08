#ifndef FIGHT_EVENT_H
#define FIGHT_EVENT_H

#include"event.h"
#include"entity.h"
#include"item.h"

using namespace std;

class fightEvent : public event{

    public:
    //mutators/accessors
    
    //EnemyAttack()
    //PlayerVictoryMessage()
    //PlayerLossMessage()


    private:
    entity* enemy;
    bool isEnemyTurn;
    item* itemToWin;
};



#endif
