#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string.h>
#include "Customer.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
//#include "Vector.h"
#include <vector>
using namespace std;

class Bank
{
private:
	string name;
	string address;
	vector<Customer*> customers;
	vector<Account*> accounts;


public:
	Bank();
	Bank(const string &  name, const string &  address);
	//do we do this
	Bank (const Bank & other);
	Bank & operator = (const Bank & other);
	~Bank();
	const string & getName() const;
	const string & getAddress() const;
	void addCustomer(long int customerID, const string &  name, const string &  address);
	void listCustomers() const;
	//not only the customer, but also his accounts
	void deleteCustomer(long int customerID);
	void addAccount(int accountType, const string &  iban, long int ownerID, double amount);
	void deleteAccount(const string &  iban);
	void listAccounts() const;
	void listCustomerAccount(long int customerID) const;
	void transfer(const string &  fromIBAN, const string & toIBAN, double amount);
	void display() const;
	void withdrawFromAccount(const string &  iban, double amount);
	void depositToAccount(const string &  iban, double amount);
	int findCustomerIndexByID(int id) const;
	int findAccountIndexByIBAN(const string &  iban) const;

};
#endif
