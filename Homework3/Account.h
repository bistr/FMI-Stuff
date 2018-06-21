#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string.h>
#include "Customer.h"


class Account
{
private:
	string iban;
	long int ownerID;
	double amount;

public:
	Account();
	Account(const string &  iban, long int ownerID, double amount);
	Account(const Account & other);
	virtual void deposit(double amount){};
	virtual bool withdraw(double amount){};
	virtual void display() const {};
	double getBalance() const;
	long int getOwnerID() const;
	const string &  getIBAN() const;
	void setBalance(double amount);

	virtual Account * copy() const{};
};



#endif
