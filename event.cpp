#include"event.h"
#include<string>
#include<iostream>

using namespace std;

int event::GetEventID(){
    return eventID;
}
void event::SetEventID(int ID){
    this->eventID = ID;
}
bool event::GetIsCompleted(){
    return isCompleted;
}
void event::SetIsCompleted(bool isCompleted){
    this->isCompleted = isCompleted;
}
void event::GreetingMessage(string greeting){
    cout << greeting << endl;
}