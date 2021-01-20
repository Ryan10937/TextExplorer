#ifndef ITEM_H
#define ITEM_H

#include <string>


struct item
{
    std::string name = "noItemName";
    int ID;
    bool isOwnedByPlayer;
    int value;
    float damage;
    int durability;
    bool storyItem = false;
};
#endif