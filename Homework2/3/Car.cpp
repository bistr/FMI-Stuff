#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"
using namespace std;



Car::Car():Vehicle()
{
}

Car::~Car()
{
	//
}

Car & Car::operator =(const Car & other)
{
	if (this!=&other)
	{
		Car::operator=(other);
	}
	return *this;
}

Car::Car(const char * make, const char * model, const char * color, int year, long int mileage):Vehicle(make,model,color,year,mileage)
{
}

Car::Car(const Car & other):Vehicle(other)
{
}

void Car::details()
{
	cout<<endl<<"-------"<<endl;
	cout<<"Make: "<<this->getMake()<<endl;
	cout<<"Model: "<<this->getModel()<<endl;
	cout<<"Color: "<<this->getColor()<<endl;
	cout<<"Year: "<<this->getYear()<<endl;
	cout<<"Mileage: "<<this->getMileage()<<endl;
	cout<<"--------"<<endl;

}