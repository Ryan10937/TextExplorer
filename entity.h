#ifndef ENTITY_H
#define ENTITY_H

#include<string>
#include<vector>
#include"item.h"
//#include"spot.h"

using namespace std;

class entity{

    public:
    //mutators and accessors
    entity();
    pair<int,int> GetPosition();
    void SetPosition(pair<int,int> position);
    void SetPosition(int xPos, int yPos);
    char GetDisplayChar();
    void SetDisplayChar(char displayChar);
    void Attack(entity* enemy);
    void SetWeapon(item* weapon);


    private:
    float currentHealth;
    float maxHealth;
    pair<int,int> position;
    item* weapon;
    string faction;
    char displayChar;


};
#endif