#include "Company.h"

Company::Company()
{
	this->name=0;
	this->successfulProjects=0;
	this->totalProjects=0;
}

Company::Company(const char * name)
{
	this->setName(name);
	this->successfulProjects=0;
	this->totalProjects=0;
}

void Company::setName(const char * name)
{
	if(this->name)
	{
		//this->name=0;
		delete[] this->name;
		this->name=0;
	}
	int length=strlen(name)+1;
	this->name=new char[length];
	strcpy(this->name,name);
}

Company::Company(const Company & other)
{
	this->setName(other.name);
	this->successfulProjects=other.successfulProjects;
	this->totalProjects=other.totalProjects;
}

double Company::reliabilityRate() const
{
	if (totalProjects==0)
	{
		return totalProjects;
	}
	return (double)successfulProjects/(double)totalProjects;
}

Company::~Company()
{
	delete[] this->name;
}

int Company::getTotalProjects()
{
	return totalProjects;
}

const char * Company::getName() const
{
	return this->name;
}



