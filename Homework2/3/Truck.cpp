#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Truck.h"
using namespace std;

Truck::Truck():Vehicle(),m_size(0)
{
}

Truck::Truck(const char * make, const char * model, const char * color, int year, long int mileage, int size):Vehicle(make,model,color,year,mileage),m_size(0)
{
	this->setSize(size);
}

Truck::Truck(const Truck & other):Vehicle(other),m_size(0)
{
	this->setSize(other.m_size);
}

Truck::~Truck()
{

}

void Truck::setSize(int size)
{
	m_size=size;
}

int Truck::getSize()
{
	return m_size;
}

void Truck::details()
{
	cout<<endl<<"-------"<<endl;
	cout<<"Make: "<<this->getMake()<<endl;
	cout<<"Model: "<<this->getModel()<<endl;
	cout<<"Color: "<<this->getColor()<<endl;
	cout<<"Year: "<<this->getYear()<<endl;
	cout<<"Mileage: "<<this->getMileage()<<endl;
	cout<<"Size: "<<this->getSize()<<endl;
	cout<<"--------"<<endl;
}

Truck & Truck::operator=(const Truck & other)
{
	if(this!=&other)
	{
		Truck::operator=(other);
		this->setSize(other.m_size);
	}
	return * this;
}