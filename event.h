#ifndef EVENT_H
#define EVENT_H

#include<string>
#include<vector>
#include"entity.h"

using namespace std;

//this is the master parent class for all other quests/events
class event
{

    public:
    bool GetIsCompleted();
    void SetIsCompleted(bool isCompleted);
    void GreetingMessage(string greeting);
    
    //Events
    void BearAttack(entity* player);
    void AngryMan(entity* player);
    void EncounterRedStone(entity* player);
    void EncounterBlueStone(entity* player);
    void EncounterYellowStone(entity* player);
    void MadMan(entity* player);

    //Event creation functions
    int DisplayChoices(vector<string> choices);
    void Fight(entity* player, entity* enemy);

    //Call Event
    void CallEvent(int eventID,entity* player);



    private:
    bool isCompleted;   
    void BeginEvent(string beginMessage);


};


#endif

