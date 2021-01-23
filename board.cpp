#include"board.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include"spot.h"
#include"entity.h"
#include"iAmHere.h"
#include "Color.h"

board::board(int boardHeight, int boardWidth){
    //create board
    grid = new vector<vector<spot*>* >;
    vector<spot*>* tempRow;
    spot* tempSpot;
    borderChar = 219;
    fogOfWar = 177;
    printMapEachTurn = true;
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
vector<vector<spot*>* >* board::GetGrid(){
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
player->SetPosition(xPos, yPos);

}


void board::MoveEntity(string direction, entity* player) {
    pair<int, int> position = player->GetPosition();
    char blockChar = 'a' + 122;
    char fogOfWarChar = fogOfWar;
    //add player to spot each time moved
        //to add player, call spot::addPlayer(entity* player)
            //in that function, call spot's event after player assignment
    //update grid
    if (direction == "w") {
        if (((grid->at((position.second) - 1))->at(position.first))->GetDisplayChar() == blockChar) {
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "up";
        if (((grid->at(position.second))->at(position.first))->GetKeepSymbol() == false || ((grid->at(position.second))->at(position.first))->GetEventID() == 0) {
            ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);//Reset fog of war character
        }
        ((grid->at(position.second))->at(position.first))->SetPlayer(NULL);//Remove player from spot
        position.second = position.second - 1;//update position based on direction selection

    }
    if (direction == "a") {
        if (((grid->at(position.second))->at((position.first) - 1))->GetDisplayChar() == blockChar) {
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "left";
        if (((grid->at(position.second))->at(position.first))->GetKeepSymbol() == false || ((grid->at(position.second))->at(position.first))->GetEventID() == 0) {
            ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);//Reset fog of war character
        }
        ((grid->at(position.second))->at(position.first))->SetPlayer(NULL);//Remove player from spot

        position.first = position.first - 1;//update position based on direction selection

    }
    if (direction == "s") {
        if (((grid->at((position.second) + 1))->at(position.first))->GetDisplayChar() == blockChar) {
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "down";
        if (((grid->at(position.second))->at(position.first))->GetKeepSymbol() == false || ((grid->at(position.second))->at(position.first))->GetEventID() == 0) {
            ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);//Reset fog of war character
        }
        ((grid->at(position.second))->at(position.first))->SetPlayer(NULL);//Remove player from spot

        position.second = position.second + 1;//update position based on direction selection

    }
    if (direction == "d") {
        if (((grid->at(position.second))->at((position.first) + 1))->GetDisplayChar() == blockChar) {
            cout << "That space is blocked" << endl;
            return;
        }
        //direction == "right";
        if (((grid->at(position.second))->at(position.first))->GetKeepSymbol() == false || ((grid->at(position.second))->at(position.first))->GetEventID() == 0) {
            ((grid->at(position.second))->at(position.first))->SetDisplayChar(fogOfWarChar);//Reset fog of war character
        }
        ((grid->at(position.second))->at(position.first))->SetPlayer(NULL);//Remove player from spot

        position.first = position.first + 1;//update position based on direction selection
    }

    //now that position is updated, update player position, display character of spot moved to, and give that spot the player address
    player->SetPosition(position);
    if (((grid->at(position.second))->at(position.first))->GetKeepSymbol() == false || ((grid->at(position.second))->at(position.first))->GetEventID() == 0) {
        ((grid->at(position.second))->at(position.first))->SetDisplayChar(player->GetDisplayChar());
    }
    ((grid->at(position.second))->at(position.first))->SetPlayer(player);

}

void board::SetEntity(int xPos, int yPos, entity* player) {
    AddNewEntity(player, xPos, yPos);
}
void board::SetDisplayChar(int xPos, int yPos, char displayChar) {
    ((grid->at(yPos))->at(xPos))->SetDisplayChar(displayChar);
}
void board::AddEventToSpot(int xPos, int yPos, char displayChar, int eventNum) {
    SetDisplayChar(xPos, yPos, displayChar);
    SetSpotEventID(xPos, yPos, eventNum);
}


void board::PrintGrid() {

    cout << "\n\n\n\n\n\n\n";
    //print grid to console
    for (int i = 0; i < grid->size(); i++) {//number of rows (y). This is not backwards
        for (int j = 0; j < (grid->at(i))->size(); j++) {//number of columns(x)

            //cout <<((grid->at(i))->at(j))->GetDisplayChar()<<" ";
            if (((grid->at(i))->at(j))->GetDisplayChar() == 'O')
            {
                SetColor(9);
                cout << ((grid->at(i))->at(j))->GetDisplayChar();
                ResetColor();
            }
            else if (((grid->at(i))->at(j))->GetDisplayChar() != fogOfWar && ((grid->at(i))->at(j))->GetDisplayChar() != 'M' && ((grid->at(i))->at(j))->GetDisplayChar() != borderChar)
            {
                SetColor(10);
                cout << ((grid->at(i))->at(j))->GetDisplayChar();
                ResetColor();
            }
            else if (((grid->at(i))->at(j))->GetDisplayChar() == 'M')
            {
                SetColor(12);
                cout << ((grid->at(i))->at(j))->GetDisplayChar();
                ResetColor();
            }
            else
            {
                cout << ((grid->at(i))->at(j))->GetDisplayChar();
            }
            
            //position (x,y) is (grid->at(y))->at(x)
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

    for(int i=0; i<answer.size(); i++){
        answer.at(i) = tolower(answer.at(i));
    }

    
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
    if(answer =="o"||answer  == "options"){
        PrintOptionsMenu();
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



void board::SetSpotEventID(int xPos, int yPos, int eventID){
    ((grid->at(yPos))->at(xPos))->SetEventID(eventID);
}

void board::SetSpotDisplayCharacter(int xPos, int yPos, char displayChar){
    ((grid->at(yPos))->at(xPos))->SetDisplayChar(displayChar);

}

void board::SetPrintMapEachTurn(bool printMapEachTurn){
    this->printMapEachTurn = printMapEachTurn;
}
bool board::GetPrintMapEachTurn(){
    return printMapEachTurn;
}

void board::PrintOptionsMenu(){
    cout<<"\n\n\n\n";
    int userChoice2;
    int userChoice;
    cout<<"---------------------------------------------\n\n";
    cout<<"Select a setting to change: \n";
    vector<string> choices{"1). Return To Game\n","2). Map Print On Move\n"};
    userChoice = DisplayChoices(choices);
    cout<<"---------------------------------------------\n\n";
    switch(userChoice){
        case(1):
        return;
        break;
        
        case(2):
        cout<<"---------------------------------------------\n\n";
        cout<<"Select a value to change \"Map Print On Move\" to: \n";
        vector<string> choices{"1). True\n","2). False\n"};
        userChoice2 = DisplayChoices(choices);
        if(userChoice2 == 1){
            printMapEachTurn = true;
        }
        if(userChoice2 == 2){
            printMapEachTurn = false;
        }
        cout<<"---------------------------------------------\n\n";
        break;
    };

}
int board::DisplayChoices(vector<string> choices){
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