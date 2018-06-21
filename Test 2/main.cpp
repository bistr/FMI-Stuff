#include <iostream>
#include "Building.h"
#include "House.h"
using namespace std;

int main()
{
	Building building1(12,240,3);
	Building building2(15,350,5);
	House house1(7, 240, 1, 3, "OwnerName");
	House house2(house1);
	house2.setRooms(6);
	house2.setArea(220);
	//since house 1 has less rooms, this will evaluate to true
	cout<< (house1 < house2)<<endl;
	//but house2 has less area. so this will be false 
	cout << ((Building)house1 < (Building)house2) << endl;
	//system("pause");
	cout<<house2;
	return 0;
}