#ifndef ELECTRICNET_H
#define ELECTRICNET_H

#include <iostream>
#include <cstring>

#include "Vector.h"
#include "ElectricDevice.h"

class ElectricNet
{
private:
	Vector <ElectricDevice*> devices;
	long int maxPower;
	long int consumption;

public:

	ElectricNet();
	ElectricNet(long int maxPower);
	ElectricNet(const ElectricNet & other);
	ElectricNet & operator= (ElectricNet const & other);

	long int getMaxPower();
	long int getConsumption();


	ElectricNet & operator+=(const ElectricDevice & newDevice);
	ElectricNet operator+(const ElectricDevice & newDevice);
	ElectricNet & operator-=(const ElectricDevice & newDevice);
	ElectricNet operator-(const ElectricDevice & newDevice);
	ElectricDevice & operator[](const char * name);
	bool operator!();
	void operator++(int);
	void operator--(int);
	void print();


};



#endif
