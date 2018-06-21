#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
private:
	char * m_model;
	int m_year;
public:
	Vehicle();
	Vehicle(const char * model, int year);
	Vehicle(const Vehicle & other);
	Vehicle & operator = (const Vehicle & other);
	~Vehicle();

	virtual void details()=0;

	char * getModel();
	void setModel(const char * model);
	int getYear();
	void setYear(int * year);
}
 