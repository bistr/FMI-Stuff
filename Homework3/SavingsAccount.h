#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <string.h>
#include "Account.h"
#include "Customer.h"	
using namespace std;

class SavingsAccount: public Account
{

private:
	double interestRate;

public:
	SavingsAccount();
	SavingsAccount(const string &  iban, long int ownerId, double amount,double interestRate);
	double getInterestRate() const;
	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;
	Account * copy() const {return new SavingsAccount(*this);};
};

#endif
