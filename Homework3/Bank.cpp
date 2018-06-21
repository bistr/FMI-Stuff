#include "Bank.h"

Bank::Bank()
{
}

Bank::Bank(const string & name, const string & address)
{
	this->name=name;
	this->address=address;
}

Bank::Bank (const Bank & other)
{
	this->name=other.name;
	this->address=other.address;
	//copying other bank's vectors
	this->accounts.resize(other.accounts.capacity());
	for (int i = 0; i < other.accounts.size(); i++)
	{
		//copy() because we have different kinds of accounts
		this->accounts[i]=other.accounts[i]->copy();
	}

	customers.resize(other.customers.capacity());
	for (int i = 0; i < other.customers.size(); i++)
	{
		this->customers[i]=new Customer(*other.customers[i]);
	}
}

Bank::~Bank()
{
	for (int i = 0; i < this->accounts.size(); i++)
	{
		delete this->accounts[i];
	}
	for (int i = 0; i < this->customers.size(); i++)
	{
		delete this->customers[i];
	} 
}

const string & Bank::getName() const
{
	return this->name;
}

const string &  Bank::getAddress() const
{
	return this->address;
}
//here
void Bank::addCustomer(long int customerID, const string & name, const string & address)
{
	int customerIdx=findCustomerIndexByID(customerID);
	if(customerIdx!=-1)
	{
		cout<<"Customer with this ID already exists."<<endl;
		return;
	}

	customers.push_back(new Customer(customerID,name,address));
}

void Bank::listCustomers() const
{
	cout<<"Customers of "<<this->name<<endl;
	cout<<customers.size()<<endl;
	cout.flush();
	for (int i=0;i<customers.size();i++)
	{
		customers[i]->display();
	}
}
//here
void Bank:: deleteCustomer(long int customerID)
{
	int customerIdx=findCustomerIndexByID(customerID);
	delete customers[customerIdx];
	customers.erase(customers.begin()+customerIdx);
	//customers.removeAt(customerIdx);

	for (int i=0;i<accounts.size();i++)
	{
		if (accounts[i]->getOwnerID()==customerID)
		{
			delete accounts[i];
			accounts.erase(accounts.begin()+i);
			i--;
			//accounts.removeAt(i);
		}
	}
}
// add here
void Bank::addAccount(int accountType, const string & iban, long int ownerID, double amount)
{

	if (findAccountIndexByIBAN(iban)!=-1)
	{
		cout<<"There was an error adding account with IBAN "<<iban<<"."<<endl;
		cout<<"Account with this IBAN already exists."<<endl;
		return;
	}

	if(findCustomerIndexByID(ownerID)==-1)
	{
		cout<<"There was an error creating account for customer "<<ownerID<<endl;
		cout<<"Customer doesn't exist."<<endl;
		return;
	}

	switch(accountType)
	{
		case 1:
			accounts.push_back(new CurrentAccount(iban, ownerID, amount));
			cout<<"Account "<<iban<<" added successfully!"<<endl;
			break;
		
		case 2:
			double interestRate;
			cout<<"Input interest rate (without percent symbol) for account "<<iban<<endl;
			cin>>interestRate;
			accounts.push_back(new SavingsAccount(iban, ownerID, amount, interestRate));
			cout<<"Account "<<iban<<" added successfully!"<<endl;
			break;
		
		case 3:
			int overdraft;
			cout<<"Input overdraft amount for account "<<iban<<endl;
			cin>>overdraft;
			accounts.push_back(new PrivilegeAccount(iban, ownerID, amount, overdraft));
			cout<<"Account "<<iban<<" added successfully!"<<endl;
			break;

		default:
			cout<<"Invalid account type "<<accountType<<endl;
			break;
	}

}

void Bank::deleteAccount(const string & iban)
{
	int accountIdx=findAccountIndexByIBAN(iban);
	if (accountIdx!=-1)
	{
		delete accounts[accountIdx];
		accounts.erase(accounts.begin()+accountIdx);
	}
	cout<<"Error! No account with this IBAN."<<endl;
}

void Bank::listAccounts() const
{
	for (int i=0;i<accounts.size();i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(long int customerID) const 
{
	cout<<"ACCOUNTS OF CUSTOMER "<<customerID<<endl;
	cout<<endl;
	for (int i=0;i<accounts.size();i++)
	{
		if (accounts[i]->getOwnerID()==customerID)
		{
			accounts[i]->display();
		}	
	}
}

void Bank::transfer(const string & fromIBAN, const string & toIBAN, double amount)
{
	int fromIndex=findAccountIndexByIBAN(fromIBAN);
	int toIndex=findAccountIndexByIBAN(toIBAN);
	
	if(fromIndex ==-1 || toIndex==-1)
	{
		cout<<"One of these accounts doesn't exist!"<<endl;
		return;
	}

	if(accounts[fromIndex]->withdraw(amount))
	{
		accounts[toIndex]->deposit(amount);
		cout<<amount<<" transferred."<<endl;
	}

	else
	{
		cout<<"Error! Insufficient balance. Can't transfer. "<<endl;
	}
}

void Bank::display() const
{
	cout<<"BANK DETAILS"<<endl;
	cout<<"Name:\t\t"<<this->name<<endl;
	cout<<"Address:\t"<<this->address<<endl;
	cout<<"Customers:\t"<<customers.size()<<endl;
	cout<<"Accounts:\t"<<accounts.size()<<endl;	
}

void Bank::withdrawFromAccount(const string & iban, double amount)
{
	int accountIdx=findAccountIndexByIBAN(iban);
	if(accountIdx!=-1)
	{
		if(accounts[accountIdx]->withdraw(amount))
		{
			cout<<amount<<" successfully withdrawn."<<endl;
			return;
		}
	}
	cout<<"There was an error withdrawing money from account "<<iban<<endl;
	cout<<"No such account."<<endl;
}

void Bank::depositToAccount(const string & iban, double amount)
{
	int accountIdx=findAccountIndexByIBAN(iban);
	if(accountIdx!=-1)
	{
		accounts[accountIdx]->deposit(amount);
		cout<<amount<<" successfully deposited."<<endl;
		return;
	}
	cout<<"There was an error depositing money into account "<<iban<<"."<<endl;
	cout<<"No such account."<<endl;
}

int Bank::findCustomerIndexByID(int id) const
{
	for (int i=0;i<customers.size();i++)
	{
		if (customers[i]->getID()==id)
		{
			return i;
		}
	}
	return -1;
}


int Bank::findAccountIndexByIBAN(const string &  iban) const
{
	for (int i=0;i<accounts.size();i++)
	{
		if (accounts[i]->getIBAN()==iban)
		{
			return i;
		}
	}
	return -1;
}

