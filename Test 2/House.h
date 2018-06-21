#pragma once
#include <iostream>
using namespace std;
#include "Building.h"


class House :
	public Building
{
private:
	unsigned int m_rooms;
	char * m_owner;
public:
	House();
	House(unsigned int height, unsigned int area, unsigned int floors, unsigned int rooms, const char * owner);
	House(const House & other);
	House & operator=(const House & other);
	
	unsigned int getRooms()const;
	char * getOwner()const;
	void setRooms(unsigned int rooms);
	void setOwner(const char * owner);
	bool operator<(const House other)const;
	~House();
};

