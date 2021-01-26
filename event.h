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
    bool AngryMan(entity* player);
    bool EncounterRedStone(entity* player);
    bool EncounterBlueStone(entity* player);
    bool EncounterYellowStone(entity* player);
    bool MadMan(entity* player);
    bool RandomEnemyEncounter(entity* player, int Stagenumber);
    bool DoctorVisit(entity* player);

    //Event creation functions
    int DisplayChoices(vector<string> choices);
    bool Fight(entity* player, entity* enemy);

    //Call Event
    bool CallEvent(int eventID,entity* player);



    private:
    bool isCompleted;   
    void BeginEvent(string beginMessage);


};


#endif

