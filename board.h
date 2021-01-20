#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<vector>
#include<string>
#include"spot.h"
#include"entity.h"

using namespace std;

class board{

    public:
    board(int boardHeight, int boardWidth); //parameterized constructor
    vector<vector<spot*>*>* GetGrid(); 
    void AddNewEntity(int xPos, int yPos);
    void AddNewEntity(entity* player);
    void AddNewEntity(entity* player, pair<int,int> position);
    void AddNewEntity(entity* player, int xPos, int yPos);
    void MoveEntity(string direction, entity* player);//move player in direction
    void SetEntity(int xPos, int yPos, entity* player);
    void SetDisplayChar(int xPos, int yPos, char displayChar);//sets display character of the spot at (xPos,yPos)
    void PrintGrid(); //Prints map
    bool PromptPlayer(string prompt, entity* player);//prompts the user for input, calls appropriate function after
    void SetSpotEventID(int xPos, int yPos, int eventID);
    void SetSpotDisplayCharacter(int xPos, int yPos, char displayChar);
    void SetPrintMapEachTurn(bool printMapEachTurn);
    bool GetPrintMapEachTurn();
    void PrintOptionsMenu();
    int DisplayChoices(vector<string> choices);
    ~board();

    

    private:
    vector<vector<spot*>*>* grid;//map
    char fogOfWar;//fog of war character
    bool printMapEachTurn;
};
#endif