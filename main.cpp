#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<ctime>

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

    //events->RandomEnemyEncounter(TestPlayer, 1);
    //events->BearAttack(player);
    //events->AngryMan(player):
    */


    

    int initialChoice;
    initialChoice = MainMenu();
    if(initialChoice == 2){
        cout <<"Game Exiting..."<<endl;
        return 0;
    }
////////////////////////////////////customizable variables////////////////////////////////////////////////////////////////////////////
    int boardHeight = 20;
    int boardWidth = 50;
    char playerChar = 'O';
    int numRandomMonsters = 20;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //event* eventCollection = new event;
    entity* player = new entity;
    player->SetName("Ryan");
    player->SetDisplayChar(playerChar);
    board* gameMap = new board(boardHeight,boardWidth);
    gameMap->AddNewEntity(player,25,11);


    //Add Events to map
    gameMap->AddEventToSpot(23,15,'A',2);//angry man
    gameMap->AddEventToSpot(25,16,'@',3);//red stone
    gameMap->AddEventToSpot(26,12,'@',4);//blue stone
    gameMap->AddEventToSpot(33,15,'@',5);//yellow stone
    gameMap->AddEventToSpot(30,15,'H',6);//madman
    
    srand(time(0));
    int randX;
    int randY;
    int randMonsterLoopBreaker = 0;
    for(int i=0;i<numRandomMonsters;i++){
        randX = (rand()% (boardWidth-3)) +1; //vary (0-47) + 1
        randY = (rand()% (boardHeight-3)) +1; //vary (0-16) + 1 
        cout<<"randX is: "<<randX<<endl;
        cout<<"randY is: "<<randY<<endl;
        if((((gameMap->GetGrid())->at(randY))->at(randX))->GetEventID() == 0){//if no event at spot, put monster there
            gameMap->AddEventToSpot(randX,randY,'M',7);//random monster
        }
        else{//if there was an event there, reduce i and try again
            i = i-1;
            randMonsterLoopBreaker++;
        }
        if(randMonsterLoopBreaker> 1000){
            cout<<"randMonsterLoopBreaker triggered. Breaking"<<endl;
            break;
        }
    }

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
        if(player->GetHealth() <= 0){
            cout <<"Death is a risk taken by all explorers. You have met that risk...\n";
            break;
        }
    }

    delete(player);
    delete(gameMap);


    cout <<"Thank you for playing!"<<endl;

    return 0;
}