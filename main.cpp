#include<iostream>
#include<string>
#include<vector>

#include"entity.h"
#include"board.h"

using namespace std;

int main(){
    int boardHeight = 20;
    int boardWidth = 100;
    char playerChar = 'O';

    entity* player = new entity;
    player->SetDisplayChar(playerChar);
    board* gameMap = new board(boardHeight,boardWidth);
    gameMap->AddNewEntity(player,boardWidth/2,boardHeight/2);
    gameMap->PrintGrid();

    bool isQuitting = false;
    int loopBreaker = 0;
    cout << "Use WASD to move and M to view map" << endl;
    while(isQuitting == false){
        isQuitting = gameMap->PromptPlayer(" ",player);
        
        if(isQuitting == false){
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
    return 0;
}