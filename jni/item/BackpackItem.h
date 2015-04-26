#pragma once
#include "Item.h"
#include "ItemInstance.h"

class BackpackItem: public Item {
	public:
	BackpackItem();
	//virtual void setNameID(const std::string &);
	bool useOn(ItemInstance *itemStack, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3);
};