#include "createItems.h"
#include "item.h"
#include "ItemTypes.h"

item CreateItem(item _item, std::string _name, int _ID, ItemType _Type, bool _isOwnedByPlayer, int _value, float _damage, int _durability)
{
	_item.name = _name;
	_item.Type = _Type;
	_item.ID = _ID;
	_item.value = _value;
	_item.damage = _damage;
	_item.durability = _durability;
	_item.isOwnedByPlayer = _isOwnedByPlayer;

	return _item;
}