#pragma once

class IDataOutput;
class IDataInput;
class Tag;

class CompoundTag: public Tag {
	public:
	CompoundTag();
	CompoundTag(std::string const&);
	CompoundTag(CompoundTag&&);
	
	int getId();
	void write(IDataOutput &);
	void read (IDataInput &);
	void save(IDataOutput &);
	void load(IDataInput &);
	bool equals(Tag const&);
	std::string toString();
	void print(std::string const&,PrintStream &);
	bool isEmpty();
	CompoundTag* get(std::string const&);
	bool contains(std::string const&,int);
	byte getByte(std::string const&);
	bool getBoolean(std::string const&);
	short getShort(std::string const&);
	int getInt(std::string const&);
	float getFloat(std::string const&);
	double getDouble(std::string const&);
	std::string getString(std::string const&);
	byte getByteArray(std::string const&);
	int getIntArray(std::string const&);
};