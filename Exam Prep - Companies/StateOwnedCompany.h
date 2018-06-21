#ifndef STATEOWNEDCOMPANY_H
#define STATEOWNEDCOMPANY_H

#include "Company.h"	
class StateOwnedCompany:public Company
{
public:
	StateOwnedCompany();
	StateOwnedCompany(const char * name);
	StateOwnedCompany(const StateOwnedCompany & other);
	bool perform(const char * project);
	Company * copy () const 
	{
		return new StateOwnedCompany(*this);
	}
	friend ostream& operator<<(ostream& out, const StateOwnedCompany& company);
};

#endif