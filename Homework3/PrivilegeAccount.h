#ifndef PRIVILEGEACCOUNT_H
#define PRIVILEGEACCOUNT_H

#include <iostream>
#include <string.h>
#include "Account.h"
using namespace std;

class PrivilegeAccount: public Account
{

private:
	int overdraft;

public:
	PrivilegeAccount();
	PrivilegeAccount(const string &  iban, long int ownerID, double amount, int overdraft);
	int getOverdraft() const;
	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;

	Account * copy() const {return new PrivilegeAccount(*this);};
};

#endif
