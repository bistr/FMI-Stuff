#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
using namespace std;
#include <cstring>

class Company
{
private:
	char * name;
protected:
	int successfulProjects;
	int totalProjects;
public:
	Company();
	Company(const char * name);
	Company(const Company & other);
	virtual ~Company();
	virtual bool perform(const char * project){};
	double reliabilityRate() const;
	void setName(const char * name);
	int getTotalProjects();
	virtual Company * copy() const{};
	const char * getName() const;
	
};

#endif