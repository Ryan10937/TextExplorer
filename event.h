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
    //events here
    int GetEventID();
    void SetEventID(int ID);
    bool GetIsCompleted();
    void SetIsCompleted(bool isCompleted);
    void GreetingMessage(string greeting);
    
    void BearAttack(entity* player);
    void AngryMan(entity* player);
    int DisplayChoices(vector<string> choices);
    void Fight(entity* player, entity* enemy);



    private:
    int eventID;
    bool isCompleted;


};


#endif

