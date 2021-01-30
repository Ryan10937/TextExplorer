#include"event.h"
#include<vector>
#include<string>
#include<iostream>
#include "UserInputErrorChecking.h"
#include "entity.h"
#include<random>
#include<ctime>
#include <stdlib.h>
#include <fstream>
#include "Color.h"
#include "PauseGame.h"

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

bool event::RandomEnemyEncounter(entity* player, int Stagenumber)
{
    //load a pool of enemy names based on stage number
    vector<string> Enemypool;
    string EnemyName;
    ifstream Enemies("Enemies.txt");
    if (Enemies.is_open())
    {
        while (getline(Enemies, EnemyName))
        {
            if ((std::stoi(EnemyName.substr(0, EnemyName.find(' ')), nullptr)) == Stagenumber)
            {
                Enemypool.push_back(EnemyName.substr((EnemyName.find(" ") + 1)));
            }
        }
        Enemies.close();
    }

    else cout << "Unable to open Enemies.txt";
    ////////////////////////////////////////////

    //randomly pick a enemy from pool
    int randomnumber = rand() % (Enemypool.size());
    EnemyName = Enemypool[randomnumber];


    ////////////////////////////////////////////

    //create a new entity with the randomly picked enemys name
    entity* RandomEnemy = new entity;
    RandomEnemy->SetName(EnemyName);

    //set the damage and health of the enemy based on the stagenumber (With 20% deviation for health and damage)
    std::string EnemDmgHp;
    float RandomEnemyDmg = 0;
    float RandomEnemyHP = 0;
    ifstream Enemies_Dmg_Hp("Enemies_Dmg_Hp.txt");
    if (Enemies_Dmg_Hp.is_open())
    {
        while (getline(Enemies_Dmg_Hp, EnemDmgHp))
        {
            if ((std::stoi(EnemDmgHp.substr(0, EnemDmgHp.find(' ')), nullptr)) == Stagenumber)
            {
                RandomEnemyDmg = std::stoi(EnemDmgHp.substr(EnemDmgHp.find(' ') + 1, EnemDmgHp.rfind(' ') - 1));
                RandomEnemyHP = std::stoi(EnemDmgHp.substr(EnemDmgHp.rfind(' ') + 1));
            }
        }
        Enemies_Dmg_Hp.close();
    }

    else cout << "Unable to open Enemies_Dmg_Hp.txt";

    RandomEnemy->SetDamage(RandomEnemyDmg);
    RandomEnemy->SetHealth(RandomEnemyHP);


    std::cout << "You have encountered a ";
    SetColor(12);
    std::cout << RandomEnemy->GetName() << std::endl;
    ResetColor();

    Pause();

    //call fight between player and new enemy
    if (Fight(player, RandomEnemy))
    {
        delete(RandomEnemy);
        return true;
    }
    else
    {
        //Change
        delete(RandomEnemy);
        std::cout << "You have gained ";
        SetColor(11);
        std::cout << (Stagenumber * 50);
        ResetColor();
        std::cout << " experience!";
        player->AddExperience((Stagenumber * 50));
        return false;
    }
}

bool event::DoctorVisit(entity* player){
    BeginEvent("Hello Traveler. Let me treat your wounds");

    vector<string> choices{"1). Let the doctor treat your wounds\n", "2). Leave\n"};
    int userChoice = DisplayChoices(choices);
    
    if(userChoice == 1){
        cout <<player->GetName()<<": \"Heal what you can\"\n\n";
        player->SetHealth(player->GetMaxHealth());
        cout <<"Booop booop beep boop booooopp\n\n\n";
    }
    if(userChoice == 2){
        cout <<player->GetName()<<": \"On second thought, I will leave\"\n";
    }

    return true;
}



bool event::AngryMan(entity* player){

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
            return false;
            break;
            /////////////////////////////////
            case(2):
            cout <<"You grab the man but he snakes free. He draws his sword.\n";
            //insert fight function between angryMan and player
            Fight(player,angryMan);
            delete(angryMan);
            return false;
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
                        return false;
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
                            return false;
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
                        return false;
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
            return false;
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
        return false;
        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(3):
        cout <<"You wait for the man to get close. Once the time is right, you lunge and begin choking the man.\n";
        cout<<"Angry man: \"YOU WILL REGRET THIS\"\n";
        cout<<"The man breaks free, drawing his sword.\n";
        //fight between angry man and player
        Fight(player,angryMan);
        delete(angryMan);
        return false;
        break;
////////////////////////////////////////////////////////////////////////////////////////////////
        case(4):
        cout<<"You let the man pass. You hear him muttering in the distance.\n";
        delete(angryMan);
        return false;
        break;
////////////////////////////////////////////////////////////////////////////////////////////////
    };      
    cout<<"default return used in event.cpp"<<endl; 
    delete(angryMan);
    return false;
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

bool event::Fight(entity* player, entity* enemy){
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
        while(player->GetHealth() >= 0 && enemy->GetHealth() >= 0 && didEscape == false){
            //fight
            cout<<"\n\n";
            cout<<"---------------------------------------------" << endl;
            if(attackTurn == true){
                SetColor(12);
                cout<<"The enemy attacks!"<<endl;
                ResetColor();
                player->SetHealth(player->GetHealth()-enemy->GetDamage());//take hp based on weapon strength
                cout<<player->GetName()<<" has "<<player->GetHealth() <<" health left!"<<endl;
            }
            if(attackTurn == false){
                userChoice = DisplayChoices(choices);
                if(userChoice == 1){
                    cout<<"\n\n";
                    cout<<"---------------------------------------------" << endl;
                    SetColor(14);
                    cout<<"You attack!"<<endl;
                    ResetColor();
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
                        return false;
                    }
                    else{
                        didEscape = false;
                    cout<<"---------------------------------------------" << endl;
                        cout<<"You try to escape, but fail!"<<endl;
                    }
                }
            }
            
            cout<<"---------------------------------------------" << endl;

            if(player->GetHealth() <= 0){
                cout <<player->GetName() <<" was defeated..."<<endl;
                player->SetHealth(0);
                return true;
            }
            if(enemy->GetHealth() <= 0){
                cout <<enemy->GetName() <<" was defeated..."<<endl;
                enemy->SetHealth(0);
                return false;
            }
            attackTurn = !attackTurn;
        }
        return true;
}

void event::BeginEvent(string beginMessage){
    //Clear some lines for the event
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << std::endl;
    }
    cout<<"----------------------------------------------------------------\n";
    cout <<beginMessage<<endl<<endl;
}

bool event::EncounterRedStone(entity* player){
    BeginEvent("You walk past a meadow and hear a faint rambling whisper");
    cout<<"You walk towards the chatter, hoping to make sense of it\n\n";
    cout<<"In disbelief, you come to the conclusion that the whispering is coming from a stone at your feet\n\n";
    vector<string> choices{"1). Leave the stone\n","2). Take the stone with you\n"};
    int userChoice = DisplayChoices(choices);
    cout<<endl;
    switch(userChoice){
        case(1):
        cout<<"You leave the stone, leaving its mystery for another\n";
        return true;
        break;

        case(2):
        cout <<"You pick up the stone. It is hot to the touch, likely from the sun.\n";
        item* redStone = new item;
        redStone->name = "Red Whispering Stone";
        redStone->storyItem = true;
        redStone->ID = 1110;
        redStone->isOwnedByPlayer = true;
        redStone->value = 50;
        player->AddInventoryItem(redStone);
        return false;
        break;
    };
    return true;
}
bool event::EncounterBlueStone(entity* player){
    BeginEvent("As you walk forward, a sharp wind invites bitter cold air");
    cout<<"Even through the whirring of the wind, you hear a rambling whisper. The words are jumbled.\n\n";
    cout<<"You walk towards the chatter, hoping to make sense of it\n\n";
    cout<<"In disbelief, you come to the conclusion that the whispering is coming from a stone at your feet\n\n";
    vector<string> choices{"1). Leave the stone\n","2). Take the stone with you\n"};
    int userChoice = DisplayChoices(choices);
    cout<<endl;
    switch(userChoice){
        case(1):
        cout<<"You leave the stone, leaving its mystery for another\n";
        return true;
        break;

        case(2):
        cout <<"You pick up the stone. It is cold to the touch, likely from the wind.\n";
        item* blueStone = new item;
        blueStone->name = "Blue Whispering Stone";
        blueStone->storyItem = true;
        blueStone->ID = 1111;
        blueStone->isOwnedByPlayer = true;
        blueStone->value = 50;
        player->AddInventoryItem(blueStone);
        return false;
        break;
    };
    return true;
}
bool event::EncounterYellowStone(entity* player){
    BeginEvent("As you walk forward, clouds appear out of no where. A storm is brewing");
    cout<<"In between the cracks of thunder, you hear a rambling whisper. The words are jumbled.\n\n";
    cout<<"You walk towards the chatter, hoping to make sense of it\n\n";
    cout<<"In disbelief, you come to the conclusion that the whispering is coming from a stone at your feet\n\n";
    vector<string> choices{"1). Leave the stone\n","2). Take the stone with you\n"};
    int userChoice = DisplayChoices(choices);
    cout<<endl;
    switch(userChoice){
        case(1):
        cout<<"You leave the stone, leaving its mystery for another\n";
        return true;
        break;

        case(2):
        cout <<"You pick up the stone. Its center is radiating light like a lamp, likely from a lightning strike.\n";
        item* yellowStone = new item;
        yellowStone->name = "Yellow Whispering Stone";
        yellowStone->storyItem = true;
        yellowStone->ID = 1112;
        yellowStone->isOwnedByPlayer = true;
        yellowStone->value = 50;
        player->AddInventoryItem(yellowStone);
        return false;
        break;
    };
    return true;
}
bool event::MadMan(entity* player){
    bool hasRedStone = player->SearchItem(1110);
    bool hasBlueStone = player->SearchItem(1111);
    bool hasYellowStone = player->SearchItem(1112);

    int userChoice=0;
    int userChoice2=0;
    int numberOfStones = hasRedStone + hasBlueStone + hasYellowStone;

    string trashVar;


    BeginEvent("You see the top of an old hut in the distance. Your curiosity throws you to its front porch.");

    cout <<"Knock on the door?\n";
    vector<string> choices{"1). Knock\n","2). Walk away from the house\n"};
    userChoice = DisplayChoices(choices);
    if(userChoice == 2){
        cout <<"You walk away from the house, hearing rambling whispers from within\n\n";
        cout<<"Enter any key to continue"<<endl;
        cin>>trashVar;
        return true;
    }
    else{
        cout <<"You walk to the door and knock 3 times.\n";
        cout <<"An old man with countable hairs on his head opens the door\n\n";

        cout<<"Enter any key to continue"<<endl;
        cin>>trashVar;
    }

    switch(numberOfStones){
        case(0):
        cout<<"Old Man: *whispers* \"All are separate. All are one. From this prison I cannot run.\"\n\n ";
        cout <<"Old Man: My home, though it be mine, cannot hold my broken mind.\n\n";
        cout <<"The Old Man closes the door, leaving you with crawling skin and the will to walk away.";
        break;

        case(1):
        cout<<"Old Man: *whispers* \"All are separate. All are one. From this prison I cannot run.\"\n\n ";
        if(hasRedStone){
            cout <<"The Old Man looks up from the ground and grows his voice from a grumble to a shout\n";
            cout <<"Old Man: it...IT is YOU. LEAVE AT ONCE YOU FILTHY BEAST!\n";
            cout <<"The Old Man slams the door. You respect the man's wishes and leave his home.\n\n";
            
        }
        if(hasBlueStone){
            cout <<"Old Man: Years ago time split who was once mine\n";
            cout<<"She is gone, but a shell remains\n\n";
        }
        if(hasYellowStone){
            cout <<"Old Man: If only to be young again...Taverns, women, money, conquest.\n";
            cout <<"Old Man: Why must fruit turn sour? Why must the day turn to night. Why does it have to end\n";
            cout <<"The Old Man shuts the door\n\n";
        }
        break;

        case(2):
        cout<<"Old Man: *whispers* \"All are separate. All are one. From this prison I cannot run.\"\n\n ";
        if(hasRedStone && hasBlueStone){
            //doesnt have yellow
            cout <<"The Old Man looks up at you and looks on the edge of tears.";
            cout <<"The Old Man grits his teeth, draws a knife and lunges towards you.\n";
            cout <<"You decide not to kill the Old Man and instead, let him be. He is clearly not well.\n\n";
        }

        if(hasRedStone && hasYellowStone){
            //doesnt have blue
            cout<<"Old Man: \"Give me 500 coins and I will spare your life.\"\n";
            cout<<player->GetName()<<": *Laughing* \"If you can catch me, I'll give you 1000 coins\"\n";
            cout<<"You run from the house. Something about the Old Man made you feel as if he, in fact, could take your life...\n\n";
        }

        if(hasYellowStone && hasBlueStone){
            //doesnt have red
            cout<<"Old Man: \"I beg you, kill me where I stand. I am but a shadow of my former self. I have nothing to live for.\"\n";
            cout<<"Old Man: \"There is nothing in this life for me\"\n";
            cout<<player->GetName()<<": \"I have no intention of killing you Old Man. I wish to help you.\"\n";
            cout<<"The Old Man closes and locks the door. You hope you to see the man again.\n\n";
        }
        break;

        case(3):
        cout<<"Old Man: *whispers* \"All are separate. All are one. From this prison I cannot...wait...I feel.\"\n\n";
        cout<<"Old Man: \"Who are you traveler? What have you done to me?\"\n";
        cout<<player->GetName()<<": \"I have done nothing to you...\"\n";
        cout <<"Old Man: \"GIVE ME YOUR BAG, QUICKLY!\"\n";
        choices = {"1). Give the man your bag\n","2). Walk away from the house\n\n"};
        userChoice2 = DisplayChoices(choices);
        if(userChoice2 == 2){
            cout <<"\n\nYou run from the house.\n As you run, you can hear the Old Man descending into madness\n\n";
            cout<<"Enter any key to continue"<<endl;
            cin>>trashVar;
            return true;
        }
        player->RemoveInventoryItem(1110);//take red stone
        player->RemoveInventoryItem(1111);//take blue stone
        player->RemoveInventoryItem(1112);//take yellow stone
        cout <<"\n\nThe Old Man dumps your bag and the floor and frantically takes hold of the Red, Blue, and Yellow Whispering Stones.\n";
        cout <<"After placing them on the ground in front of him, he closes his eyes. The Old Man begins to convulse as streams of light\n";
        cout <<"begin flowing from the stones to various parts of the Old Man's body.\n";
        cout <<"Curled up on the floor, the Old Man begins to speak.\n";
        cout <<"\nOld Man: \"Thank you traveller. \"\n";
        choices = {"1). Ask the man what happened\n","2). Walk away from the house\n\n"};
        userChoice2 = DisplayChoices(choices);
        if(userChoice2 == 2){
            cout <<"You leave the house, never knowing what happened to the Old Man.\n\n";
            cout<<"Enter any key to continue"<<endl;
            cin>>trashVar;
            return true;
        }
        cout <<"Old Man: \"Many years ago, I was married to an outstanding young woman. She was perfect.\"\n";
        cout <<"Old Man: \"The world was perfect in my eyes. I had all I had ever wanted.\"\n";
        cout <<"Old Man: \"Until one tragic day, the world took her from me. I didn't know how to handle it.\"\n";
        cout <<"Old Man: \"After years of anger, despair, and desire, I turned to my magic to rid me of my pain.\"\n";
        cout <<"Old Man: \"I casted each of these desires to a stone. After, an old friend of mine scattered them across the land.\"\n";
        cout <<"Old Man: \"Little did I know, but I had also placed some of my conciousness into each of these stones. \"\n";
        cout <<"Old Man: \"This eventually drove me to madness. I could feel the winters, summers, storms all from my home.\"\n";
        cout <<"Old Man: \"The mind is not built for such a task. Especially an old mind like mine.\"\n";
        cout <<"Old Man: \"Thank you traveller, I will always be grateful.\"\n";
        cout <<"You leave the Old Man's house. He is given back the mind he once lost.";
        cout<<"Enter any key to continue"<<endl;
        cin>>trashVar;
        return false;
        break;
    };

    cout<<"Enter any key to continue"<<endl;
    cin>>trashVar;

    return true;
}


bool event::CallEvent(int eventID, entity* player){
    bool keepSymbol = false;
    switch(eventID){
        case(0):
        return true;
        break;

        case(1):
        return true;
        break;
        
        case(2):
        keepSymbol = AngryMan(player);
        break;

        case(3):
        keepSymbol = EncounterRedStone(player);
        break;

        case(4):
        keepSymbol = EncounterBlueStone(player);
        break;

        case(5):
        keepSymbol = EncounterYellowStone(player);
        break;

        case(6):
        keepSymbol = MadMan(player);
        break;

        case(7):
        keepSymbol = RandomEnemyEncounter(player,1);
        break;

        case(8):
        keepSymbol = DoctorVisit(player);
        break;
        
    }
    return keepSymbol;
}







