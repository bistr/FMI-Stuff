#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
using namespace std;

int main()
{
	Vehicle first("Tiger","Porsche","Red",1998,20000);
	Vehicle second(first);
	Car third("Lion","Lanca","Green",2001,10000);
	first.setModel("BMW"); 	
	cout<<first.getModel()<<endl;
	cout<<second.getModel()<<endl;
	cout<<third.getModel()<<endl;
	Truck fourth("Elephant","TIR","Gray",2003,450000,15);
	Truck fifth=fourth;
	fifth.details();
	Motorcycle sixth("Antelope","Hummer","Black",1999,25000,"touring");
	sixth.details();

	cout<<endl;
	return 0;
}
