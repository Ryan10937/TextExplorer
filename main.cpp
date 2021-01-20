#include<iostream>
#include<string>
#include<vector>

#include"iAmHere.h"
#include"entity.h"
#include"board.h"
#include "event.h"

using namespace std;

int main()
{
    /*
    * 
    * TESTING FOR EVENTS
    *    
    char playerChar = 'O';
    entity* player = new entity;
    player->SetDisplayChar(playerChar);
    player->SetName("Ryan");
    event* events = new event;

    //events->BearAttack(player);
    events->AngryMan(player);
    */

    int boardHeight = 20;
    int boardWidth = 100;
    char playerChar = 'O';

    //event* eventCollection = new event;
    entity* player = new entity;
    player->SetName("Ryan");
    player->SetDisplayChar(playerChar);
    board* gameMap = new board(boardHeight,boardWidth);
    gameMap->AddNewEntity(player,20,15);
    gameMap->SetSpotEventID(10,10,1);
    gameMap->SetSpotDisplayCharacter(10,10,'B');
    gameMap->SetSpotEventID(23,15,2);
    gameMap->SetSpotDisplayCharacter(23,15,'A');    

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