#include"event.h"
#include<vector>
#include<string>
#include<iostream>
#include "UserInputErrorChecking.h"
#include "entity.h"
#include<random>
#include<ctime>

using namespace std;

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
    bear->SetName("Bear");

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
        Fight(player, bear);
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
    int userChoice=0;
    int userChoice2 = 0;
    int userChoice3 = 0;
    int userChoice4 = 0;
    int userChoice5 = 0;
    int loopBreaker = 0;
    item* angryManWeapon = new item;
    angryManWeapon->ID = 0002;
    angryManWeapon->damage = 10;
    angryManWeapon->isOwnedByPlayer = false;
    angryManWeapon->value = 1000;
    entity* angryMan = new entity;
    angryMan->SetName("Angry Man");
    angryMan->SetWeapon(angryManWeapon);

    cout <<"As you continue forward, you spot a man wearing a nobelman's clothes and a very expensive looking ring.\n ";
    cout <<"He is walking quickly, stomping, and muttering something angrily. Although he clearly does not want to \nbe bothered, you are drawn to ask where he's off to\n";
    
    vector<string> choices{"1). Ask the man where he is going\n","2). Trip the man\n","3). Rob the man\n","4). Do nothing\n"};
    userChoice = DisplayChoices(choices);

    switch(userChoice){
////////////////////////////////////////////////////////////////////////////////////////////////
        case(1):
        cout <<player->GetName()<<": \"Sir, where are you going?\"\n";
        cout <<"The man comes to a hault and turns to you. He is practically spitting in your face.\n";
        cout <<"Angry Man: \"WHERE I am going and what I am doing is NONE of your business you maggot!\"\n";
        choices = {"1). Push the man and draw your weapon\n","2). Rob the man\n","3). You never asked what he was doing...\n","4). Say nothing and walk away\n"};
        userChoice2 = DisplayChoices(choices);
        switch(userChoice2){
            /////////////////////////////////
            case(1):
            cout<<"You push the man and draw your sword. The man recovers and reacts in kind.\n";
            cout<<"Angry man: \"If it's a fight you want, it's a fight you'll get!\"\n";
            //insert fight function between angryMan and player
            Fight(player,angryMan);
            delete(angryMan);
            return;
            break;
            /////////////////////////////////
            case(2):
            cout <<"You grab the man but he snakes free. He draws his sword.\n";
            //insert fight function between angryMan and player
            Fight(player,angryMan);
            delete(angryMan);
            return;
            break;
            /////////////////////////////////
            case(3):
            cout <<player->GetName()<<"\"I never asked what you were doing, just where you were going.\"\n";
            cout <<"Angry Man: *huffs* \"I am GOING to my cottage. Alone. I forgot something there. Happy?\"\n";
            choices = {"1). That was sufficient information, let the man be on his way \n","2). Pry in to why the man is going back home\n"};
            userChoice3 = DisplayChoices(choices);
                switch(userChoice3){
                    ///////////
                    case(1):
                    cout<<player->GetName()<<": \"Didn't mean to pry, I'll be on my way.\"\n";
                    cout<<"Angry Man: *mutters* \"What a weirdo\"\n";
                    break;
                    ///////////
                    case(2):
                    cout<<player->GetName()<<": \"What are you going back to get?\"\n";
                    cout<<"Angry Man: \"YOU WANNA KNOW WHAT I'M GETTING?!?! I'M GETTING A SWORD. A FUCKING SWORD DAMN IT! \n";
                    cout<<"A SWORD TO KILL A MAN WHO WAS ONCE MY FRIEND!! NOW LET ME BE!\"\n";
                    choices = {"1). Let the man be\n","2). Offer to help kill his friend\n","3). Convince him not to kill his friend\n"};
                    userChoice4 = DisplayChoices(choices);
                    switch(userChoice4){
                        /////
                        case(1):
                        cout<<player->GetName()<<": \"Alright alright sorry I ever asked...\"\n";
                        cout <<"You turn and leave the man, letting him stomp his way back to his cottage and perform his deed.\n";
                        delete(angryMan);
                        return;
                        break;
                        /////
                        case(2):
                        cout<<player->GetName()<<": \"I've killed my fair share of backstabbers in the day. Want some help?\"\n";
                        cout<<"Angry Man: \"As long as he dies, I don't care where you go\"\n\n";
                        cout <<"-----------------------------------------------------------------";
                        cout<<"The two of you make a fire a few miles outside of town, not saying a word to each other.\n";
                        cout<<"A few hours pass, the moon is high in the sky. The man decides it is time.\n\n";
                        cout<<"The two of you walk in to town. The streets are quiet, the market is empty. The only sounds are those made\n";
                        cout<<" by the wind. The moon, the third accomplice, lights the way to the house of the transgressor.\n\n";
                        cout<<"There are 2 doors, one in front, the other in back. The man motions you to follow him to the back door.\n";
                        cout<<"The door is in front of you, you look to your accomplice, he motions you do go in first.\n";
                        choices = {"1). Open the door and look around","2). Motion for the man to go in first\n"};
                        userChoice5 = DisplayChoices(choices);
                        switch(userChoice5){
                            case(1):
                            cout<<"You nod in agreement and slowly turn the knob. You slowly move the door from its frame.\n";
                            cout<<"You open the door just enough to slide through.\n";
                            cout<<"Now inside the house, you turn and motion to your partner to follow\n";
                            cout<<"As you turn towards the inside of the house, you feel a sharp pain in your back. \n";
                            cout <<"You look down to see a blade growing from your stomach. The dark room gets darker as you fall to the floor\n";
                            cout<<"While your conciousness fades, you see sparks from a duel between you accomplice and the victim.\n";
                            cout<<"The victim's blade finds another kill, silencing your accomplice as well. You should have never come here...\n";
                            player->SetHealth(0);
                            delete(angryMan);
                            return;
                            break;

                            case(2):
                            cout<<"You shake your head and motion for the man to enter the house first.\n";
                            cout<<"Angry Man: *whispers loudly* \"No, you go.\" \n";
                            cout<<"You know his voice was too loud but it is too late.\n";
                            cout<<"Guard: \"By the order of the Jarl, stand now\"\n";
                            cout<<"Angry Man: \"I came here with a single purpose, I will complete my task.\"\n";
                            cout<<"Guard:\"No! Stop!\"\n";
                            cout<<"The man darts in to the house, only to run in to the victim's sword. Your accomplice is dead.\n";
                            cout<<"You are sent to life in prison for attempted murder\n";
                            player->SetHealth(0);//could set position to a jail in a city instead...
                            break;
                        };
                        break;
                        /////
                        case(3):
                        cout<<player->GetName()<<": \"Revenge is hardly ever worth it. They're not worth your time. \"\n";
                        cout <<"The angry man looks at you, disgusted. As he storms off, you hear weeping in the distance...\n";
                        delete(angryMan);
                        return;
                        break;
                        /////
                    };

                    break;
                    ///////////
                };

            break;
            /////////////////////////////////
            case(4):
            cout <<"You walk away. All is well but your pride.\n";
            cout <<"Angry Man: \"Run back to your mother, peasant.\"\n";
            delete(angryMan);
            return;
            break;
            /////////////////////////////////
        };

        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(2):
        cout<<"You stick out your foot and the angry man trips. He tumbles on the groud.\n";
        cout<<"Angry Man: \"I am NOT in the mood for games. Draw your sword.\"\n";
        //fight between angry man and player
        Fight(player,angryMan);
        delete(angryMan);
        return;
        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(3):
        cout <<"You wait for the man to get close. Once the time is right, you lunge and begin choking the man.\n";
        cout<<"Angry man: \"YOU WILL REGRET THIS\"\n";
        cout<<"The man breaks free, drawing his sword.\n";
        //fight between angry man and player
        Fight(player,angryMan);
        delete(angryMan);
        return;
        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(4):
        cout<<"You let the man pass. You hear him muttering in the distance.\n";
        delete(angryMan);
        return;
        break;
////////////////////////////////////////////////////////////////////////////////////////////////
    };      
    cout<<"default return used in event.cpp"<<endl; 
    delete(angryMan);
    return;
}

int event::DisplayChoices(vector<string> choices){
    int userInput=0;
    for(int i=0;i<choices.size();i++){
        cout <<choices.at(i);
    }
    while(userInput<1 || userInput > choices.size()){
            cout<<"Select An answer from 1 to "<<choices.size()<<": ";
            cin>>userInput;
    }
    return userInput;
}

void event::Fight(entity* player, entity* enemy){
        srand(time(0));
        int coinFlip = rand() % 2;
        bool attackTurn = false;
        bool didEscape = false;
        vector<string> choices{"1). Attack\n","2). Attempt Escape\n"};
        int userChoice;
        int escapeNum=0;
        if(coinFlip == 0){
            attackTurn = false;
        }
        if(coinFlip == 1){
            attackTurn = true;
        }
        while(player->GetHealth() > 0 && enemy->GetHealth() > 0 && didEscape == false){
            //fight
            cout<<"\n\n";
            cout<<"---------------------------------------------" << endl;
            if(attackTurn == true){
                cout<<"The enemy attacks!"<<endl;
                player->SetHealth(player->GetHealth()-enemy->GetDamage());//take hp based on weapon strength
                cout<<player->GetName()<<" has "<<player->GetHealth() <<" health left!"<<endl;
            }
            if(attackTurn == false){
                userChoice = DisplayChoices(choices);
                if(userChoice == 1){
                    cout<<"\n\n";
                    cout<<"---------------------------------------------" << endl;
                    cout<<"You attack!"<<endl;
                    enemy->SetHealth(enemy->GetHealth()-player->GetDamage());//take hp based on weapon strength
                    cout<<enemy->GetName()<<" has "<<enemy->GetHealth() <<" health left!"<<endl;
                }
                if(userChoice == 2){
                    cout<<"\n\n";
                    escapeNum = rand() % 3;
                    if(escapeNum <= 1){
                        didEscape = true;
                        cout<<"---------------------------------------------" << endl;
                        cout <<"Got away safely!"<<endl;
                        
                    }
                    else{
                        didEscape = false;
                    cout<<"---------------------------------------------" << endl;
                        cout<<"You try to escape, but fail!"<<endl;
                    }
                }
            }
            
            cout<<"---------------------------------------------" << endl;

            if(player->GetHealth() < 0){
                cout <<player->GetName() <<" was defeated..."<<endl;
                player->SetHealth(0);
            }
            if(enemy->GetHealth() < 0){
                cout <<enemy->GetName() <<" was defeated..."<<endl;
                enemy->SetHealth(0);
            }
            attackTurn = !attackTurn;
        }
        
    return;
}



void event::CallEvent(int eventID, entity* player){
    switch(eventID){
        case(1):
        BearAttack(player);
        break;
        
        case(2):
        AngryMan(player);
        break;

        
    }
}






