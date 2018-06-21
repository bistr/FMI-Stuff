#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

class Motorcycle:public Vehicle
{
private:
	char * m_type;

public:
	Motorcycle();
	Motorcycle(const char * make, const char * model, const char * color, int year, long int mileage, const char * type);
	Motorcycle(const Motorcycle & other);
	Motorcycle & operator = (const Motorcycle & other);
	~Motorcycle();

	void details();

	char * getType();
	void setType(const char * type);

};
 
 #endif