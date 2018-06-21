#pragma once

#include <iostream>
#include <cstring>
using namespace std;


class Building
{
private:
	unsigned int m_height;
	unsigned int m_area;
	unsigned int m_floors;
public:
	Building();
	Building(unsigned int height, unsigned int area, unsigned int floors);
	~Building();
	unsigned int getHeight()const;
	unsigned int getArea()const;
	unsigned int getFloors()const;
	void setHeight(unsigned int height);
	void setArea(unsigned int area);
	void setFloors(unsigned int floors);
	unsigned int getTotalArea()const;
	bool operator <(const Building & other)const;
	friend ostream & operator<<(ostream & out, const Building & building)const;

};

