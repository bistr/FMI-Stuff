#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include <iostream>
#include <string.h>
#include "Account.h"
using namespace std;

class CurrentAccount: public Account
{

public:
	CurrentAccount();
	CurrentAccount(const string &  iban, long int ownerId, double amount);
	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;
	Account * copy() const {return new CurrentAccount(*this);};
};

#endif