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
    board(int boardHeight, int boardWidth);
    vector<vector<spot*>*>* GetGrid();
    void AddNewEntity(int xPos, int yPos);
    void AddNewEntity(entity* player);
    void AddNewEntity(entity* player, pair<int,int> position);
    void AddNewEntity(entity* player, int xPos, int yPos);
    void MoveEntity(string direction, entity* player);
    void PrintGrid();
    bool PromptPlayer(string prompt, entity* player);
    ~board();

    

    private:
    vector<vector<spot*>*>* grid;
    char fogOfWar;
};
#endif