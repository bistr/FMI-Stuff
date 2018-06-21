#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount():Account(),overdraft(0)
{
}

PrivilegeAccount::PrivilegeAccount(const string &  iban, long int ownerID, double amount, int overdraft):Account(iban, ownerID, amount)
{
	this->overdraft=overdraft;
}

void PrivilegeAccount::deposit(double amount)
{
	this->setBalance(this->getBalance()+amount);
}

bool PrivilegeAccount::withdraw(double amount)
{
	if (this->getBalance()+this->overdraft>=amount)
	{
		this->setBalance(this->getBalance()-amount);
		return true;
	}
	return false;
}

void PrivilegeAccount::display() const
{
	cout<<endl;
	cout<<"-- PRIVILEGE ACCOUNT "<< this->getIBAN()<<" --"<<endl;
	cout<<"Owner ID:\t"<<this->getOwnerID()<<endl;
	cout<<"Balance:\t"<<this->getBalance()<<endl;
	cout<<"Overdraft:\t"<<this->overdraft<<endl;
	cout<<"-------------------------"<<endl;
}

int PrivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}