#include<vector>
#include<string>
#include"spot.h"
#include"entity.h"
#include"iAmHere.h"

using namespace std;

spot::spot(char fogOfWarChar){
    displayChar = fogOfWarChar;
    eventCollection = new event;
    position = make_pair(-1,-1);
    type = "noType";
    hasPlayer = false;
    entity* player = nullptr;
    hasEvent = false;
}

void spot::Copy(spot* newSpot) 
{
  this->displayChar = newSpot->GetDisplayChar();
  this->eventCollection = newSpot->GetEventCollection();
  this->position = newSpot->GetPosition();
  this->type = newSpot->GetType();
  this->hasPlayer = newSpot->GetHasPlayer();
  this->player = newSpot->GetEntity();
  this->hasEvent = newSpot->GetHasEvent();
}

char spot::GetDisplayChar(){
    return displayChar;
}
void spot::SetDisplayChar(char displayChar){
    this->displayChar = displayChar;
}
event* spot::GetEventCollection(){
    return eventCollection;
}
void spot::SetEventCollection(event* eventCollection){
    this->eventCollection = eventCollection;
}
bool spot::GetHasEvent(){
    return hasEvent;
}
void spot::SetHasEvent(bool hasEvent){
    this->hasEvent = hasEvent;
}
void spot::FlipHasEvent(){
    hasEvent = !hasEvent;
}
pair<int,int> spot::GetPosition(){
    return position;
}
void spot::SetPosition(pair<int,int> position){
    this->position = position;
}
void spot::SetPosition(int xPos, int yPos){
    this->position.first = xPos;
    this->position.second = yPos;
}
string spot::GetType(){
    return type;
}
void spot::SetType(string type){
    this->type = type;
}
bool spot::GetHasPlayer(){
    return hasPlayer;
}
void spot::SetHasPlayer(bool hasPlayer){
    this->hasPlayer = hasPlayer;
}

entity* spot::GetEntity(){
    return player;
}
void spot::SetEntity(entity* player){
    this->player = player;
    displayChar = player->GetDisplayChar();
}
void spot::RemoveEntity(){//sets entity pointer to null
    this->player = nullptr;
}

void spot::SetPlayer(entity* player){

    this->player = player;
}


spot::~spot(){
    delete(player);
}