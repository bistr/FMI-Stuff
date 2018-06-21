#include <iostream>
#include <cstring>
#include "ElectricDevice.h"

using namespace std;

ElectricDevice::ElectricDevice()
{
	this->name = 0;
	this->power=0;
}

ElectricDevice::ElectricDevice(const char  * name, int power)
{
	int length=strlen(name);
	char * newName = new char [length];
	memcpy(newName,name,length+1);
	this->name=newName;
	this->power=power;
}

ElectricDevice::~ElectricDevice()
{
	if(this->name)
	{
		delete[] this->name;
		this->name=0;
	}
}

ElectricDevice::ElectricDevice(const ElectricDevice & other)
{
	int length=strlen(other.name);
	char * newName = new char [length];
	memcpy(newName,other.name,length+1);
	this->name=newName;
	this->power=other.power;
}

ElectricDevice & ElectricDevice::operator =(const ElectricDevice & other)
{
	if (this != &other)
	{
		if(this->name)
		{
			delete[] this->name;
			this->name=0;
		}
		int length=strlen(other.name);
		char * newName = new char [length];
		memcpy(newName,other.name,length+1);
		this->name=newName;
		this->power=other.power;
		return *this;
	}
}


void ElectricDevice::setName(const char * name)
{
	if(this->name)
	{
		delete[] this->name;
		this->name=0;
		int length=strlen(name);
		this->name = new char [length];
		memcpy(this->name,name,length+1);
		return;
	}

	if (name)
	{
		int length=strlen(name);
		this->name = new char [length];
		memcpy(this->name,name,length+1);
		return;
	}



}

char * ElectricDevice::getName() const
{
	return this->name;
}

void ElectricDevice::setPower(int power)
{
	this->power=power;
}

int ElectricDevice::getPower() const
{
	return this->power;
}

