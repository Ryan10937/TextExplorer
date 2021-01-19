#include"event.h"
#include<vector>
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


void event::AngryMan(entity* player){

    //Clear some lines for the event
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << std::endl;
    }
    int userInput=0;
    int loopBreaker = 0;
    entity* angryMan = new entity;
    item* angryManWeapon = new item;
    angryManWeapon->ID = 0002;
    angryManWeapon->damage = 10;
    angryManWeapon->isOwnedByPlayer = false;
    angryManWeapon->value = 1000;
    angryMan->SetWeapon(angryManWeapon);

    cout <<"As you continue forward, you spot a man wearing a nobelman's clothes and a very expensive looking ring.\n ";
    cout <<"He is walking quickly, stomping, and muttering something angrily. Although he clearly does not want to \nbe bothered, you are drawn to ask where he's off to\n";
    
    vector<string> choices{"1). Ask the man where he is going\n","2). Trip the man\n","3). Rob the man\n,","4). Do nothing\n"};
    userInput = DisplayChoices(choices);

    switch(userInput){
////////////////////////////////////////////////////////////////////////////////////////////////
        case(1):
        cout <<player->GetName()<<": \"Sir, where are you going?\"\n";
        cout <<"The man comes to a hault and turns to you. He is practically spitting in your face.\n";
        cout <<"Angry Man: \"WHERE I am going and what I am doing is NONE of your business you maggot!\"\n";
        choices = {"1). Push the man and draw your weapon\n","2). Rob the man\n","3). You never asked what he was doing...\n,","4). Say nothing and walk away\n"};
        int userInput2 = DisplayChoices(choices);
        switch(userInput2){
            /////////////////////////////////
            case(1):
            cout<<"You push the man and draw your sword. The man recovers and reacts in kind.\n";
            cout<<"Angry man: \"If it's a fight you want, it's a fight you'll get!\"\n";
            //insert fight function between angryMan and player
            return;
            break;
            /////////////////////////////////
            case(2):
            cout <<"You grab the man but he snakes free. He draws his sword.\n";
            //insert fight function between angryMan and player
            return;
            break;
            /////////////////////////////////
            case(3):
            cout <<player->GetName()<<"\"I never asked what you were doing, just where you were going.\"\n";
            cout <<"Angry Man: *huffs* \"I am GOING to my cottage. Alone. I forgot something there. Happy?\"\n";
                //yes
                    //starts "Help the angry man" event chain
                //no

            break;
            /////////////////////////////////
            case(4):
            cout <<"You walk away. All is well but your pride.\n";
            cout <<"Angry Man: \"Run back to your mother, peasant.\"\n";
            return;
            break;
            /////////////////////////////////
        };

        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(2):

        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(3):

        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(4):

        break;
////////////////////////////////////////////////////////////////////////////////////////////////
    };

}

int event::DisplayChoices(vector<string> choices){
    int userInput;
    for(int i=0;i<choices.size();i++){
        cout <<choices.at(i);
    }
    while(userInput<1 || userInput > choices.size()-1){
            cout<<"Select An answer from 1 to "<<choices.size()<<": ";
            cin>>userInput;
    }
    return userInput;
}