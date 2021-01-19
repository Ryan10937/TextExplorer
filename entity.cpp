#include"entity.h"
#include"item.h"
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"spot.h"

using namespace std;

entity::entity(){
    this->currentHealth = 100;
    this->maxHealth = 100;
    this->position = make_pair(10,10);
    this->weapon = new item;
    this->faction = "Nature";
    this->displayChar = 'D';
    this->weapon = new item;
    weapon->damage = 5;
    this->name = "noName";
}

void entity::SetHealth(float health)
{
    currentHealth = health;
    maxHealth = health;
}

float entity::GetHealth()
{
    return currentHealth;
}

float entity::GetDamage()
{
    return weapon->damage;
}

pair<int,int> entity::GetPosition(){
    return position;
}
void entity::SetPosition(pair<int,int> position){
    this->position = position;
}
void entity::SetPosition(int xPos, int yPos){
    (this->position).first = xPos;
    (this->position).second = yPos;
}
char entity::GetDisplayChar(){
    return displayChar;
}
void entity::SetDisplayChar(char displayChar){
    this->displayChar = displayChar;
}

void entity::Attack(entity* enemy){
    enemy->currentHealth = enemy->currentHealth - weapon->damage;
}
void entity::SetWeapon(item* weapon){

    this->weapon = weapon;

}
void entity::SetName(string name){
    this->name = name;
}
string entity::GetName(){
    return name;
}