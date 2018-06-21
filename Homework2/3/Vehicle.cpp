#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle()
{
	m_model=0;
	m_year=0;
}

Vehicle::Vehicle(const char * make, const char * model, const char * color, int year, long int mileage)
{
	/*this->setMake(make);
	this->setModel(model);
	this->setColor(color);*/

	m_model=new char[strlen(model)+1];
	strcpy(m_model,model);

	m_color=new char[strlen(color)+1];
	strcpy(m_color,color);

	m_make=new char[strlen(make)+1];
	strcpy(m_make,make);

	m_year=year;
	m_mileage=mileage;
}

Vehicle::Vehicle(const Vehicle & other)
{
	m_model=new char[strlen(other.m_model)+1];
	strcpy(m_model,other.m_model);

	m_color=new char[strlen(other.m_color)+1];
	strcpy(m_color,other.m_color);

	m_make=new char[strlen(other.m_make)+1];
	strcpy(m_make,other.m_make);

	m_year=other.m_year;
	m_mileage=other.m_mileage;
}

Vehicle & Vehicle::operator =(const Vehicle & other)
{
	if (this!=&other)
	{
		m_model=new char[strlen(other.m_model)+1];
		strcpy(m_model,other.m_model);

		m_color=new char[strlen(other.m_color)+1];
		strcpy(m_color,other.m_color);

		m_make=new char[strlen(other.m_make)+1];
		strcpy(m_make,other.m_make);

		m_year=other.m_year;
		m_mileage=other.m_mileage;
	}
	return *this;
}

Vehicle::~Vehicle()
{
	if(m_make)
	{
		delete[] m_make;
	}
	if(m_color)
	{
		delete[] m_color;
	}
	if(m_model)
	{
		delete[] m_model;
	}
	/*if(m_year)
	{
		delete &m_year;
	}

	if(m_mileage)
	{
		delete &m_mileage;
	}*/
}



int Vehicle::getYear()
{
	return m_year;
}

long int Vehicle::getMileage()
{
	return m_mileage;
}

char * Vehicle::getModel()
{
	return m_model;
}

char * Vehicle::getColor()
{
	return m_color;
}

char * Vehicle::getMake()
{
	return m_make;
}

void Vehicle::setMake(const char * make)
{
	if (m_make)
	{
		delete[] m_make;
		m_make=0;
	}
	m_make=new char[strlen(make)+1];
	strcpy(m_make,make);
}

void Vehicle::setModel(const char * model)
{
	if (m_model)
	{
		delete[] m_model;
		m_model=0;
	}
	m_model=new char[strlen(model)+1];
	strcpy(m_model,model);
}

void Vehicle::setColor(const char * color)
{
	if (m_color)
	{
		delete[] m_color;
		m_color=0;
	}
	m_color=new char[strlen(color)+1];
	strcpy(m_color,color);
}

void Vehicle::setYear(int year)
{
	m_year=year;
} 

void Vehicle::setMileage(long int mileage)
{
	m_mileage=mileage;
}