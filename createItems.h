#pragma once

#include "item.h"
#include "ItemTypes.h"

item CreateItem(item _item, std::string _name, int _ID, ItemType _Type, bool _isOwnedByPlayer, int _value, float _damage, int _durability);

