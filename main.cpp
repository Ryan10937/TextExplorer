#include<iostream>
#include<string>
#include<vector>

#include"iAmHere.h"
#include"entity.h"
#include"board.h"
#include"InsertCity.h"

using namespace std;

int main()
{

    //std::cout << "Please Work" << std::endl;
    
    int boardHeight = 20;
    int boardWidth = 100;
    char playerChar = 'O';

    entity* player = new entity;
    player->SetDisplayChar(playerChar);
    board* gameMap = new board(boardHeight,boardWidth);
    gameMap->AddNewEntity(player,boardWidth/2,boardHeight/2);

    //make and insert cities
        //make city
        city* testCity = new city(5,6,make_pair(10,30));//does not test board x and y
        testCity->AddPerimeterWalls();
        testCity->SetName("SterzOpolis");

        //insert city
        gameMap->AddCity(testCity);
        //InsertCity(gameMap);
    
        gameMap->PrintGrid();

    bool isQuitting = false;
    int loopBreaker = 0;
    cout << "Use WASD to move and M to view map" << endl;
    while(isQuitting == false){
        isQuitting = gameMap->PromptPlayer(" ",player);
        
        if(isQuitting == false){
            //gameMap->PrintGrid();
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