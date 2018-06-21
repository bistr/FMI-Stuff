#include "PrivateCompany.h"

PrivateCompany::PrivateCompany():Company(),k(1)
{
}

PrivateCompany::PrivateCompany(const char * name, int k):Company(name)
{
	this->k=k;
}
PrivateCompany::PrivateCompany(const PrivateCompany & other):Company(other)
{
	this->k=other.k;
}

bool PrivateCompany::perform(const char * project)
{
	this->totalProjects++;
	if(totalProjects%k!=0)
	{
		this->successfulProjects++;
		cout<<project<<"\tdone\t"<<getName()<<endl;
		return true;
	}
	cout<<project<<"\tFAILED\t"<<getName()<<endl;
	return false;
}

ostream& operator<<(ostream& out, const PrivateCompany& company)
{
	out << "private: "<< company.k <<" "<< company.getName() << endl;
	out << endl;

}