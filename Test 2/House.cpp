#include "House.h"

House::House():Building()
{
	m_rooms = 0;
	m_owner = 0;
}

House::House(unsigned int height, unsigned int area, unsigned int floors, unsigned int rooms, const char * owner):Building(height,area,floors),m_rooms(rooms),m_owner(0)
{
	this->setOwner(owner);
}

House::House(const House & other):Building(other),m_owner(0)
{
	
	this->setRooms(other.m_rooms);
	this->setOwner(other.m_owner);
} 


House & House::operator=(const House & other)
{
	if (this != &other)
	{
		this->setArea(other.getArea());
		this->setHeight(other.getHeight());
		this->setFloors(other.getFloors());
		this->setRooms(other.getRooms());
		this->setOwner(other.getOwner());

	}
	return *this;
}

unsigned int House::getRooms()const
{
	return m_rooms;
}

char * House::getOwner()const
{
	return m_owner;
}

void House::setRooms(unsigned int rooms)
{
	m_rooms = rooms;
}

void House::setOwner(const char * owner)
{
	if (m_owner)
	{
		delete[] m_owner;
		m_owner = 0;
	}

	char * newOwner = new char[strlen(owner)+1];
	memcpy(newOwner, owner, strlen(owner) + 1);
	m_owner = newOwner;
	
}

House::~House()
{
}

bool House::operator<(const House other) const
{
	return m_rooms < other.m_rooms;
}