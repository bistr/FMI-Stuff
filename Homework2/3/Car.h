#ifndef CAR_H
#define CAR_H

class Car:public Vehicle
{
private:
public:
	Car();
	Car(const char * make, const char * model, const char * color, int year, long int mileage);
	Car(const Car & other);
	~Car();
	Car & operator=(const Car & other);
	void details();
};

#endif