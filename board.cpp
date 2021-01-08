#include"board.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include"spot.h"
#include"entity.h"
#include"iAmHere.h"

board::board(int boardHeight, int boardWidth){
    //create board
    grid = new vector<vector<spot*>* >;
    vector<spot*>* tempRow;
    spot* tempSpot;
    char borderChar = 219;
    fogOfWar = 177;

    for(int i=0; i<boardHeight;i++){
        tempRow = new vector<spot*>;
        for(int j=0; j<boardWidth;j++){
            tempSpot = new spot(fogOfWar);
            tempSpot->SetPosition(i,j);
            if(i == 0 || i == boardHeight-1 || j==0 || j ==boardWidth-1){
                tempSpot->SetDisplayChar(borderChar);
            }
            tempRow->push_back(tempSpot);
        }
        grid->push_back(tempRow);
    }
}
vector<vector<spot*>*>* board::GetGrid(){
    return grid;
}
void board::AddNewEntity(int xPos, int yPos){
    //add general entity to a new spot
    entity* player = new entity;

    ((grid->at(yPos))->at(xPos))->SetEntity(player);

    //update position in player also
    player->SetPosition(xPos,yPos);

}
void board::AddNewEntity(entity* player){
    //add entity to board at its position
    ((grid->at((player->GetPosition()).second))->at((player->GetPosition()).first))->SetEntity(player);

}
void board::AddNewEntity(entity* player, pair<int,int> position){
    //add entity to board at position specified
    ((grid->at(position.second))->at(position.first))->SetEntity(player);
    //update position in player also
    player->SetPosition(position);

}
void board::AddNewEntity(entity* player, int xPos, int yPos){
    //add entity to board at position specified
    ((grid->at(yPos))->at(xPos))->SetEntity(player);

    //update position in player also
    player->SetPosition(xPos,yPos);

}
void board::MoveEntity(string direction, entity* player){
    pair<int,int> position = player->GetPosition();
    char blockChar = 'a'+122;
    char fogOfWarChar = fogOfWar;
    
    //update grid
    if(direction == "w" ){
        if(((grid->at((position.second)-1))->at(position.first))->GetDisplayChar() == blockChar){
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "up";
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);
        position.second = position.second - 1;
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(player->GetDisplayChar());

    }
    if(direction == "a" ){
        if(((grid->at(position.second))->at((position.first)-1))->GetDisplayChar() == blockChar){
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "left";
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);
        position.first = position.first - 1;
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(player->GetDisplayChar());

    }
    if(direction == "s" ){
        if(((grid->at((position.second)+1))->at(position.first))->GetDisplayChar() == blockChar){
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "down";
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);
        position.second = position.second + 1;
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(player->GetDisplayChar());

    }
    if(direction == "d" ){
        if(((grid->at(position.second))->at((position.first)+1))->GetDisplayChar() == blockChar){
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "right";
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);
        position.first = position.first + 1;
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(player->GetDisplayChar());
    }
    player->SetPosition(position);

    
    

}
void board::PrintGrid(){

    //system("CLS");
    cout <<"\n\n\n\n\n\n\n";
    //print grid to console
    for(int i=0; i<grid->size();i++){
        for(int j=0; j<(grid->at(i))->size();j++){
            
            //cout <<((grid->at(i))->at(j))->GetDisplayChar()<<" ";
            cout <<((grid->at(i))->at(j))->GetDisplayChar();
        }
        cout <<endl;
    }
}

bool board::PromptPlayer(string prompt, entity* player){
    
    string answer;
    int width = 20;
    
    
    cout <<setfill('=')<< setw(width) <<"=" <<endl;
    setfill(' '); 
    setw(1);
    

    cout << prompt << endl;
    cin >> answer;

    
    cout <<setfill('=')<< setw(width) <<"=" <<endl;
    setfill(' '); 
    setw(1);
    

    if(answer == "w" || answer == "a" || answer == "s" || answer == "d" ){
        MoveEntity(answer,player);
    }
    if(answer == "map" || answer == "m"){
        PrintGrid();
    }
    if(answer == "quit" || answer == "q"){
        return true;
    }
    return false;
    
}
board::~board(){
    for(int i=0;i<grid->size();i++){
        for(int j=0;j<(grid->at(i))->size();j++){
            delete((grid->at(i))->at(j));
        }
        delete(grid->at(i));
    }
    delete(grid);
}