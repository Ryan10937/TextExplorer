#include"event.h"
#include<string>
#include<iostream>
#include "UserInputErrorChecking.h"

using namespace std;

int event::GetEventID()
{
    return eventID;
}
void event::SetEventID(int ID)
{
    this->eventID = ID;
}
bool event::GetIsCompleted()
{
    return isCompleted;
}
void event::SetIsCompleted(bool isCompleted)
{
    this->isCompleted = isCompleted;
}
void event::GreetingMessage(string greeting)
{
    cout << greeting << endl;
}

void event::BearAttackEvent(entity* player)
{
    bool isEventOver = false;
    int playersAction;
    entity bear;
    bear.SetHealth(10);
    //Clear some lines for the event
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << std::endl;
    }

    std::cout << "You have encountered a giant bear!" << std::endl;
    std::cout << "The bear sees you and is preparing to charge you" << std::endl;
    std::cout << "What will you do!?" << std::endl;

    std::cout << "  1. Attack!" << std::endl; //Runs the Attack function
    std::cout << "  2. Run!" << std::endl; //Return Player to previous spot
    std::cin >> playersAction;
    while (!(std::cin >> playersAction) || playersAction > 2 || playersAction < 1)
    {
        //Error Message
        std::cout << "Please enter the number of the action you want to take." << std::endl;

        // Clear input stream
        std::cin.clear();

        // Discard previous input
        std::cin.ignore(123, '\n');
    }

    if (playersAction == 1)
    {
        while (!isEventOver)
        {
            //Player Attacks bear
            //display health of both
            //press enter to continue
            //bear attacks player
            //display health of both
            //Press enter to continue
        }
    }
    else
    {
        std::cout << "You run as fast as you can back to where you came" << std::endl;
        //Return Player to previous spot
        isEventOver == true;
        return;
    }
}
