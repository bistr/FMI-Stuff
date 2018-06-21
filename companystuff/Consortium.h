#ifndef CONSORTIUM_H
#define CONSORTIUM_H

#include <iostream>
#include "Company.h"
#include "PrivateCompany.h"
#include "StateOwnedCompany.h"
using namespace std;
#include <vector>

class Consortium:public Company
{
private:
	vector <Company*> contractors;
public:
	Consortium();
	Consortium(const char * name);
	Consortium(const Consortium & other);
	void addContractor(const Company & contractor);
	void removeContractor(const Company & contractor);
	void printStatus();
	int findContractorByName(const char * name);
	~Consortium();
	bool perform(const char * project);
	Company * copy() const
	{
		return new Consortium(*this);
	}

	friend ostream& operator<<(ostream& out, const Consortium& company);
	

};





#endif