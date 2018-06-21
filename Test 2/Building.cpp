#include "Building.h"

Building::Building()
{
	m_area = 0;
	m_floors = 0;
	m_height = 0;

}


Building::~Building()
{
	
}

Building::Building(unsigned int height, unsigned int area, unsigned int floors)
{
	m_height = height;
	m_area = area;
	m_floors = floors;
}

unsigned int Building::getHeight() const
{
	return m_height;
}

unsigned int Building::getArea()const
{
	return m_area;
}

unsigned int Building::getFloors()const
{
	return m_floors;

}

void Building::setArea(unsigned int area)
{
	m_area = area;
}

void Building::setHeight(unsigned int height)
{
	m_height = height;
}

void Building::setFloors(unsigned int floors)
{
	m_floors=floors;
}

unsigned int Building::getTotalArea()const
{
	return m_floors*m_area;
}

bool Building::operator <(const Building & other)const
{
	return (m_floors < other.m_floors);
}

ostream & operator<<(ostream & out, const Building & building) const
{
	out<<"hey bistra"<<endl;
	return out;
}
