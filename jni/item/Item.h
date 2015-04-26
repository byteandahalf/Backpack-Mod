#pragma once
#include <string>
#include <memory>

class TextureUVCoordinateSet;
class Player;
class Entity;
class Mob;
class Tile;
class Level;
class TextureAtlas;
class ItemInstance;
class Random;

class Item {
public:
	int _maxStackSize;
	std::string _textureAtlasFile;
	int _frameCount;
	bool _animatesInToolbar;
	const int id;
	int maxDamage;
	int creativeCategory;
	bool _handEquipped;
	bool _isStackedByData;
	Item* craftingRemainingItem;
	std::string descriptionId;

	char filler_item[76];

// static fields
	static Item* items[256];
	int getIconYOffset();
	bool isLiquidClipItem(int);
	bool requiresInteract();
	bool isEmissive(int);
	int getAnimationFrameFor(Mob &);
	std::string getInteractText(void);
	int getMaxStackSize(ItemInstance const*);
	void setMaxStackSize(unsigned char);
	bool canBeDepleted();
	TextureUVCoordinateSet getIcon(int,int,bool);
	void setIcon(TextureUVCoordinateSet);
	bool isMirroredArt(void);
	void use(ItemInstance &,Player &);
	void useOn(ItemInstance *,Player *,int,int,int,signed char,float,float,float);
	int getMaxUseDuration();
	int getUseAnimation();
	void releaseUsing(ItemInstance *,Player *,int);
	int getDestroySpeed(ItemInstance *,Tile *);
	bool canDestroySpecial(Tile const*);
	int getLevelDataForAuxValue(int);
	bool isStackedByData();
	int getMaxDamage();
	int getAttackDamage(Entity *);
	void hurtEnemy(ItemInstance *,Mob *,Mob *);
	void interactEnemy(ItemInstance *,Mob *,Player *);
	void mineBlock(ItemInstance *,int,int,int,int,Mob *);
	void handEquipped();
	bool isHandEquipped();
	bool isFood();
	bool isSeed();
	bool isArmor();
	bool isDye();
	std::string getName(ItemInstance const*);
	void setNameID(std::string const&);
	void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	void teardownItems();
	Item(int);
	void setCategory(int);
	void setStackedByData(bool);
	void setMaxDamage(int);
	TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&,int);
	void setIcon(std::string const&,int);
	std::string getTextureItem(std::string const&);
	bool _textMatch(std::string const&,std::string const&,bool);
	void useTimeDepleted(ItemInstance *,Level *,Player *);
	int getIDByName(std::string const&,bool);
	static void addCreativeItem(short,short);
	static void addCreativeItem(Tile *,short);
	static void addCreativeItem(Item *,short);
	static void initCreativeItems();
	static void initItems();
};