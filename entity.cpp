#include"entity.h"
#include"item.h"
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"spot.h"
#include"item.h"
#include "UserInputErrorChecking.h"

using namespace std;

entity::entity() {
    this->currentHealth = 100;
    this->maxHealth = 100;
    this->position = make_pair(10, 10);
    this->weapon = new item;
    this->faction = "Nature";
    this->displayChar = 'D';
    this->weapon = new item;
    weapon->damage = 5;
    this->name = "noName";
    inventory = new vector<item*>;
    this->damage = 1;
    this->NextLevelUp = 100;
    this->Level = 1;
    this->experience = 0;
}

void entity::SetHealth(float health)
{
    currentHealth = health;
}

float entity::GetHealth()
{
    return currentHealth;
}

float entity::GetWeaponDamage()
{
    return weapon->damage;
}

pair<int, int> entity::GetPosition() {
    return position;
}
void entity::SetPosition(pair<int, int> position) {
    this->position = position;
}
void entity::SetPosition(int xPos, int yPos) {
    (this->position).first = xPos;
    (this->position).second = yPos;
}
char entity::GetDisplayChar() {
    return displayChar;
}
void entity::SetDisplayChar(char displayChar) {
    this->displayChar = displayChar;
}

void entity::Attack(entity* enemy) {
    enemy->currentHealth = enemy->currentHealth - weapon->damage;
}
void entity::SetWeapon(item* weapon) {

    this->weapon = weapon;
    damage = weapon->damage;

}
void entity::SetName(string name) {
    this->name = name;
}
string entity::GetName() {
    return name;
}

void entity::SetInventory(vector<item*>* inventory) {
    this->inventory = inventory;
}
vector<item*>* entity::GetInventory() {
    return inventory;
}
void entity::AddInventoryItem(item* itemToAdd) {
    inventory->push_back(itemToAdd);
    cout << "\n" << itemToAdd->name << " added to inventory!\n";
}
void entity::RemoveInventoryItem(int itemID) {
    for (int i = 0; i < inventory->size(); i++) {
        if ((inventory->at(i))->ID == itemID) {
            inventory->erase(inventory->begin() + i);
        }
    }
}
void entity::RemoveInventoryItem(string itemName) {
    for (int i = 0; i < inventory->size(); i++) {
        if ((inventory->at(i))->name == itemName) {
            inventory->erase(inventory->begin() + i);
        }
    }
}
void entity::RemoveInventoryItem(item* itemToRemove) {
    RemoveInventoryItem(itemToRemove->ID);
}
bool entity::SearchItem(int itemID) {
    for (int i = 0; i < inventory->size(); i++) {
        if ((inventory->at(i))->ID == itemID) {
            return true;
        }
    }
    return false;
}
bool entity::SearchItem(string itemName) {
    for (int i = 0; i < inventory->size(); i++) {
        if ((inventory->at(i))->name == itemName) {
            return true;
        }
    }
    return false;
}
bool entity::SearchItem(item* itemToSearch) {
    return SearchItem(itemToSearch->ID);
}


float entity::GetDamage() {
    return damage;
}
void entity::SetDamage(float damage) {
    this->damage = damage;
}

float entity::GetMaxHealth() {
    return maxHealth;
}
void entity::SetMaxHealth(float MaxHP) {
    maxHealth = MaxHP;
}



void entity::AddExperience(int Exp)
{
    
    experience += Exp;
    bool loop = true;
    while (loop)
    {
        if (GetExperience() >= NextLevelUp)
        {
            
            LevelUp();
            loop = true; //Loops to see if leveled up more than once
        }
        else
        {
            loop = false;
        }
    }
}

int entity::GetExperience()
{
    return experience;
}

void entity::LevelUp()
{
    int choice;

    Level++;
    std::cout << "You have leveled up!" << std::endl;
    std::cout << "Level: " << Level << std::endl;
    std::cout << "Please pick and attribute to add your point too." << std::endl;
    std::cout << "1. Health + 50\n2. Damage + 5" << std::endl;
    while (!(cin >> choice) || choice <= 0 || choice >= 3)
    {
        ErrorCheck("Please Enter a 1 or 2.");
    }
    switch (choice)
    {
    case 1:
        SetMaxHealth((GetMaxHealth() + 50.f));
        break;
    case 2:
        SetDamage(GetDamage() + 5.f);
    default:
        break;
    }
    SetHealth(GetMaxHealth());
    NextLevelUp *= 1.5;
}

int entity::GetLevel()
{
    return Level;
}
