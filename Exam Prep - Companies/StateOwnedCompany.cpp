#include "StateOwnedCompany.h"

StateOwnedCompany::StateOwnedCompany():Company()
{
}
StateOwnedCompany::StateOwnedCompany(const char * name):Company(name)
{
}
StateOwnedCompany::StateOwnedCompany(const StateOwnedCompany & other):Company(other)
{
}

bool StateOwnedCompany::perform(const char * project)
{
	this->totalProjects++;
	if(totalProjects%20==0)
	{
		this->successfulProjects++;
		cout<<project<<"\tdone\t"<<getName()<<endl;
		return true;
	}
	cout<<project<<"\tFAILED\t"<<getName()<<endl;
	return false;
}

ostream& operator<<(ostream& out, const StateOwnedCompany& company)
{
	out << "state: "<< company.getName() << endl;
	out << endl;

}

