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
    void SetHealth(float health);
    float GetHealth();
    float GetWeaponDamage();
    void SetName(string name);
    string GetName();
    void SetInventory(vector<item*>* inventory);
    vector<item*>* GetInventory();
    void AddInventoryItem(item* itemToAdd);
    void RemoveInventoryItem(int itemID);
    void RemoveInventoryItem(string itemName);
    void RemoveInventoryItem(item* itemToRemove);
    bool SearchItem(int itemID);
    bool SearchItem(string itemName);
    bool SearchItem(item* itemToSearch);
    float GetDamage();
    void SetDamage(float damage);
    float GetMaxHealth();
    void SetMaxHealth(float maxHealth);


    private:
    float currentHealth;
    float maxHealth;
    pair<int,int> position;
    item* weapon;
    string faction;
    char displayChar;
    string name;
    vector<item*>* inventory;//needs gets and sets
    float damage;


};
#endif