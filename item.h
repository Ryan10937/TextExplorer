#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "ItemTypes.h"

struct item
{
    std::string name;
    ItemType Type;
    int ID;
    bool isOwnedByPlayer;
    int value;
    float damage;
    int durability;
};
#endif