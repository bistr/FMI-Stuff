#include "SavingsAccount.h"

SavingsAccount::SavingsAccount():Account(),interestRate(0)
{
}

SavingsAccount::SavingsAccount(const string &  iban, long int ownerID, double amount, double interestRate):Account(iban, ownerID, amount)
{
	this->interestRate=interestRate;
}

void SavingsAccount::deposit(double amount)
{
	this->setBalance(this->getBalance()+amount);
}

bool SavingsAccount::withdraw(double amount)
{
	if (this->getBalance()>=amount)
	{
		this->setBalance(this->getBalance()-amount);
		return true;
	}
	return false;
}

void SavingsAccount::display() const
{
	cout<<endl;
	cout<<"-- SAVINGS ACCOUNT "<< this->getIBAN()<<" --"<<endl;
	cout<<"Owner ID:\t"<<this->getOwnerID()<<endl;
	cout<<"Balance:\t"<<this->getBalance()<<endl;
	cout<<"Interest Rate:\t"<<this->interestRate<<endl;
	cout<<"-------------------------"<<endl;
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}