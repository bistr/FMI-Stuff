#include "CurrentAccount.h"

CurrentAccount::CurrentAccount():Account()
{
}

CurrentAccount::CurrentAccount(const string &  iban, long int ownerID, double amount):Account(iban, ownerID, amount)
{
}

void CurrentAccount::deposit(double amount)
{
	this->setBalance(this->getBalance()+amount);
}

bool CurrentAccount::withdraw(double amount)
{
	if (this->getBalance()>=amount)
	{
		this->setBalance(this->getBalance()-amount);
		return true;
	}
	return false;
}

void CurrentAccount::display() const
{
	cout<<endl;
	cout<<"-- CURRENT ACCOUNT "<< this->getIBAN()<<" --"<<endl;
	cout<<"Owner ID:\t"<<this->getOwnerID()<<endl;
	cout<<"Balance:\t"<<this->getBalance()<<endl;
	cout<<"-------------------------"<<endl;
}