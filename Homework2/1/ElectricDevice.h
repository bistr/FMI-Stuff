#ifndef ELECTRICDEVICE_H
#define ELECTRICDEVICE_H

#include <iostream>
#include <cstring>


using namespace std;

class ElectricDevice
{
private:
	char * name;
	int power;


public:
	ElectricDevice();
	ElectricDevice(const char * name, int power);
	~ElectricDevice();
	ElectricDevice(const ElectricDevice & other);
	ElectricDevice & operator =(ElectricDevice const & other);
	
	void setName(const char * name);
	char * getName() const;
	void setPower(int power);
	int getPower() const;
};

#endif
