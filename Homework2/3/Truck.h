#ifndef TRUCK_H
#define TRUCK_H

class Truck:public Vehicle
{
public:
Truck();
Truck(const char * make, const char * model, const char * color, int year, long int mileage, int size);
Truck(const Truck & other);
~Truck();
Truck & operator=(const Truck & other);
void details();
void setSize(int size);
int getSize();


private:
	int m_size;

};

#endif