#include "BackpackItem.h"

BackpackItem::BackpackItem() : Item(356 - 256) {
	this->setNameID("Backpack");
	this->setIcon("apple", 0);
	this->setMaxStackSize(1);
	//this->handEquipped();
	this->setCategory(3);
};

bool BackpackItem::useOn(ItemInstance *i, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3) {
	i->count++;
};