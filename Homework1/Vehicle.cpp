#include <iostream>
#include <strlen>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle()
{
	m_model=0;
	m_year=0;
}

Vehicle::Vehicle(const char * model, int year)
{
	strcpy(m_model,model);
	m_year=year;
}

Vehicle::Vehicle(const Vehicle & other)
{
	strcpy(m_model,other.m_model);
	m_year=other.m_year;
}

Vehicle & Vehicle::operator =(const Vehicle & other)
{
	if (this!=&other)
	{
		if(m_model)
		{
			delete[] m_model;
			m_model=0;
		}

		strcpy(m_model,other.m_model);
		m_year=other.m_year;
	}
	return *this;
}

~Vehicle()
{
	delete[] m_model;
}

void Vehicle::setYear(int year)
{
	m_year=year;
} 

void Vehicle::setModel(const char * model)
{
	if (m_model)
	{
		delete[] m_model;
		m_model=0;
	}
	strcpy(m_model,model);
}

int Vehicle::getYear()
{
	return m_year;
}

char * Vehicle::getModel()
{
	return m_model;
}

