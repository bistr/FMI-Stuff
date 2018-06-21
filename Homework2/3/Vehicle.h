#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
private:
	char * m_make;
	char * m_model;
	char * m_color;
	int m_year;
	long int m_mileage;
public:
	Vehicle();
	Vehicle(const char * make, const char * model, const char * color, int year, long int mileage);
	Vehicle(const Vehicle & other);
	Vehicle & operator = (const Vehicle & other);
	~Vehicle();

	virtual void details(){};

	char * getMake();
	void setMake(const char * make);
	char * getModel();
	void setModel(const char * model);
	char * getColor();
	void setColor(const char * color);
	int getYear();
	void setYear(int year);
	long int getMileage();
	void setMileage(long int mileage);
};
 
 #endif