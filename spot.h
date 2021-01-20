#ifndef SPOT_H
#define SPOT_H

#include<string>

#include"event.h"
#include"iAmHere.h"
#include"entity.h"

using namespace std;

class spot{

    public:
    //constructor
    spot(char fogOfWarChar);
    //mutators
    //accessors
    void Copy(spot* newSpot);
    char GetDisplayChar();
    void SetDisplayChar(char displayChar);
    event* GetEventCollection();
    void SetEventCollection(event* eventCollection);
    bool GetHasEvent();
    void SetHasEvent(bool hasEvent);
    void FlipHasEvent();
    pair<int,int> GetPosition();
    void SetPosition(pair<int,int> position);
    void SetPosition(int xPos, int yPos);
    string GetType();
    void SetType(string type);
    bool GetHasPlayer();
    void SetHasPlayer(bool hasPlayer);
    entity* GetEntity();
    void SetEntity(entity* player);
    void SetPlayer(entity* player);
    void RemoveEntity();//sets entity pointer to null
    void CallEvent();
    void SetEventID(int eventID);
    ~spot();


    private:
    char displayChar;
    event* eventCollection;
    bool hasEvent;
    pair<int,int> position;
    string type;
    bool hasPlayer;
    entity* player;
    int eventID;
};




#endif