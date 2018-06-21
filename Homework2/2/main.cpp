#include <iostream>
#include "Vector.h"
#include "Pair.h"
#include "Settings.h"
using namespace std;

int main()
{
	Pair<int>first("first",1);
	Pair<int>second("second",2);
	Pair<int>third("third",3);
	Pair<int>fourth("fourth",4);
	Settings <int> container;
	container.add(first);
	container.add(second);
	container.add(third);
	container.add(fourth);
	cout<<"The next number is the amount of objects in the container."<<endl;
	cout<<container.count()<<endl;
	int valueVar=0;
	cout<<"The next number is whether the pair is found in the container - it should be 1"<<endl;
	cout<<bool(container.get("fourth",valueVar))<<endl;
	cout<<"The pair has been found and valueVar is set to its value"<<endl;
	cout<<"valueVar = "<<valueVar<<endl;
	cout<<"The pairs so far are:"<<endl;
	container.print();
	container.set("fifth",5);
	cout<<"Adding a new one..."<<endl;
	container.print();
	cout<<endl;
	return 0;
}
