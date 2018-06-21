#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Motorcycle.h"
using namespace std;

Motorcycle::Motorcycle():Vehicle(),m_type(0)
{

}

Motorcycle::Motorcycle(const char * make, const char * model, const char * color, int year, long int mileage, const char * type):Vehicle(make,model,color,year,mileage),m_type(0)
{
	this->setType(type);
}

Motorcycle::Motorcycle(const Motorcycle & other):Vehicle(other),m_type(0)
{
	this->setType(other.m_type);
}

Motorcycle::~Motorcycle()
{
}

void Motorcycle::setType(const char * type)
{
	if(m_type)
	{
		delete[] m_type;
		m_type=0;
	}
	m_type=new char[strlen(type)+1];
	strcpy(m_type,type);

}

char * Motorcycle::getType()
{
	return m_type;
}

void Motorcycle::details()
{
	cout<<endl<<"-------"<<endl;
	cout<<"Make: "<<this->getMake()<<endl;
	cout<<"Model: "<<this->getModel()<<endl;
	cout<<"Color: "<<this->getColor()<<endl;
	cout<<"Year: "<<this->getYear()<<endl;
	cout<<"Mileage: "<<this->getMileage()<<endl;
	cout<<"Type: "<<this->getType()<<endl;
	cout<<"--------"<<endl;
}

Motorcycle & Motorcycle::operator=(const Motorcycle & other)
{
	if(this!=&other)
	{
		Motorcycle::operator=(other);
		this->setType(other.m_type);
	}
	return * this;
}