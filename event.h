#ifndef EVENT_H
#define EVENT_H

#include<string>
#include<vector>

using namespace std;

//this is the master parent class for all other quests/events
class event{

    public:
    //events here
    int GetEventID();
    void SetEventID(int ID);
    bool GetIsCompleted();
    void SetIsCompleted(bool isCompleted);
    void GreetingMessage(string greeting);
    

    private:
    int eventID;
    bool isCompleted;

};


#endif

