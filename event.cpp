#include"event.h"
#include<string>
#include<iostream>
#include "UserInputErrorChecking.h"
#include "entity.h"

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

void event::BearAttack(entity* player)
{
    //TODO ADD COLOR
    bool isEventOver = false;
    int playersAction;

    entity* bear = new entity;
    bear->SetHealth(10);

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
    while (!(std::cin >> playersAction) || playersAction > 2 || playersAction < 1)
    {
        //Error Message
        std::cout << "Please enter the number of the action you want to take." << std::endl;

        // Clear input stream
        std::cin.clear();

        // Discard previous input
        std::cin.ignore(123, '\n');
    }
    // Clear input stream
    std::cin.clear();

    // Discard previous input
    std::cin.ignore(123, '\n');
    if (playersAction == 1)
    {
        while (!isEventOver)
        {
            //Player Attacks bear
            std::cout << "You swing your sword at the bear dealing " << player->GetDamage() << " damage" << std::endl;
            player->Attack(bear);

            //display health of both
            std::cout << "Bear's health: " << bear->GetHealth() << std::endl;
            std::cout << "Your health: " << player->GetHealth() << std::endl;

            //press enter to continue
            std::cout << "Press enter to continue..." << std::endl;
            std::cin.ignore();

            //Check if HP is 0
            if (player->GetHealth() <= 0)
            {
                std::cout << "Player is dead" << std::endl;

                std::cout << "Press enter to continue..." << std::endl;
                std::cin.ignore();
                delete(bear);
                return;
            }
            else if (bear->GetHealth() <= 0)
            {
                std::cout << "You have killed the bear!" << std::endl;

                std::cout << "Press enter to continue..." << std::endl;
                std::cin.ignore();
                delete(bear);
                return;
            }

            //bear attacks player
            std::cout << "The bear swipes at you dealing " << bear->GetDamage() << " damage" << std::endl;
            bear->Attack(player);

            //display health of both
            std::cout << "Bear's health: " << bear->GetHealth() << std::endl;
            std::cout << "Your health: " << player->GetHealth() << std::endl;

            //Press enter to continue
            std::cout << "Press enter to continue..." << std::endl;
            std::cin.ignore();

            //Check if either has 0 health
            if (player->GetHealth() <= 0)
            {
                std::cout << "Player is dead" << std::endl;

                std::cout << "Press enter to continue..." << std::endl;
                std::cin.ignore();
                delete(bear);
                return;
            }
            else if (bear->GetHealth() <= 0)
            {
                std::cout << "You have killed the bear!" << std::endl;

                std::cout << "Press enter to continue..." << std::endl;
                std::cin.ignore();
                delete(bear);
                return;
            }
        }
    }
    else
    {
        std::cout << "You run as fast as you can back to where you came" << std::endl;
        //Return Player to previous spot
        isEventOver = true;

        delete(bear);
        return;
    }
}
