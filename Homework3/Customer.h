#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string.h>
using namespace std;

class Customer
{
private:
	long int id;
	string name;
	string address;

public:
	Customer();
	Customer(long int id, const string &  name, const string &  address);
	Customer(const Customer & other);
	long int getID() const;
	const string &  getName() const;
	const string &  getAddress() const;
	void display() const;
};

#endif