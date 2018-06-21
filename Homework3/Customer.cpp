#include "Customer.h"

Customer::Customer()
{
	this->id=0;
	//this->name=0;
	//this->address=0;
}

Customer::Customer(long int id, const string &  name, const string &  address)
{
	this->id=id;
	this->name=name;
	this->address=address;
}

Customer::Customer(const Customer & other)
{
	this->id=other.id;
	this->name=other.name;
	this->address=other.address;
}

long int Customer::getID() const
{
	return this->id;
}

const string &  Customer::getName() const
{
	return this->name;
}

const string &  Customer::getAddress() const
{
	return this->address;
}

void Customer::display() const
{
	cout<<endl;
	cout<<"----- CUSTOMER "<< this->id<<" --------"<<endl;
	cout<<"Name:\t\t"<<this->name<<endl;
	cout<<"Address:\t"<<this->address<<endl;
	cout<<"-------------------------"<<endl;
}