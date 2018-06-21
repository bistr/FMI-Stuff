#ifndef PRIVATECOMPANY_H
#define PRIVATECOMPANY_H

#include "Company.h"
class PrivateCompany:public Company
{
private:
	int k;
public:
	PrivateCompany();
	PrivateCompany(const char * name, int k);
	PrivateCompany(const PrivateCompany & other);
	bool perform(const char * project);
	Company * copy () const 
	{
		return new PrivateCompany(*this);
	}
	friend ostream& operator<<(ostream& out, const PrivateCompany& company);
};



#endif