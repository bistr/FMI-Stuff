#include "Account.h"

Account::Account()
{
	this->ownerID=0;
	this->amount=0;
}

Account::Account(const string &  iban, long int ownerID, double amount)
{
	this->iban=iban;
	this->ownerID=ownerID;
	this->amount=amount;
}

Account::Account(const Account & other)
{
	this->iban=other.iban;
	this->ownerID=other.ownerID;
	this->amount=other.amount;
}


double Account::getBalance() const
{
	return this->amount;
}

const string &  Account::getIBAN() const
{
	return this->iban;
}

long int Account::getOwnerID() const
{
	return this->ownerID;
}

void Account::setBalance(double amount)
{
	this->amount=amount;
}
