#include<iostream>
#include<string>
#include<vector>

#include"iAmHere.h"
#include"entity.h"
#include"board.h"
#include "event.h"
#include"MainMenu.h"

using namespace std;

int main()
{
    /*
    * 
    * TESTING FOR EVENTS
    *    
    */
    /*
    char TestPlayerChar = 'T';
    entity* TestPlayer = new entity;
    TestPlayer->SetDisplayChar(TestPlayerChar);
    TestPlayer->SetName("TestPlayer");
    event* events = new event;

    events->RandomEnemyEncounter(TestPlayer, 1);

    //events->BearAttack(player);
    //events->AngryMan(player):
    */

    

    int initialChoice;
    initialChoice = MainMenu();
    if(initialChoice == 2){
        cout <<"Game Exiting..."<<endl;
        return 0;
    }

    int boardHeight = 20;
    int boardWidth = 50;
    char playerChar = 'O';

    //event* eventCollection = new event;
    entity* player = new entity;
    player->SetName("Ryan");
    player->SetDisplayChar(playerChar);
    board* gameMap = new board(boardHeight,boardWidth);
    gameMap->AddNewEntity(player,25,11);


    //Add Events to map
    gameMap->SetSpotEventID(10,10,1);//add BearAttack()
    gameMap->SetSpotDisplayCharacter(10,10,'B');
    gameMap->SetSpotEventID(23,15,2);//add AngryMan
    gameMap->SetSpotDisplayCharacter(23,15,'A');    
    gameMap->SetSpotEventID(25,16,3);//add EncounterRedStone()
    gameMap->SetSpotDisplayCharacter(25,16,'@');    
    gameMap->SetSpotEventID(26,12,4);//add EncounterBlueStone()
    gameMap->SetSpotDisplayCharacter(26,12,'@');  
    gameMap->SetSpotEventID(33,15,5);//add EncounterYellowStone()
    gameMap->SetSpotDisplayCharacter(33,15,'@');   
    gameMap->SetSpotEventID(30,15,6);//add MadMan()
    gameMap->SetSpotDisplayCharacter(30,15,'H'); 




    gameMap->PrintGrid();

    
    
    bool isQuitting = false;
    int loopBreaker = 0;
    cout << "Use WASD to move and M to view map" << endl;
    while(isQuitting == false){
        isQuitting = gameMap->PromptPlayer(" ",player);
        
        if(isQuitting == false && gameMap->GetPrintMapEachTurn() == true){
            gameMap->PrintGrid();
        }

        loopBreaker++;
        if(loopBreaker > 2000){
            cout <<"Loop break triggered" << endl;
            break;
        }
    }

    delete(player);
    delete(gameMap);

    cout <<"Thank you for playing!"<<endl;

    return 0;
}