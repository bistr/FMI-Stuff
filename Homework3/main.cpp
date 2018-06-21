#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include "Bank.h"

using namespace std;

bool isDigit(const char & symbol)
{
	return symbol >= '0' && symbol <= '9';
}

void printChoices()
{
		cout<<endl;
		cout<<"1 List customers"<<endl;
		cout<<"2 Add new customer"<<endl;
		cout<<"3 Delete customer"<<endl;
		cout<<"4 List all accounts"<<endl;
		cout<<"5 List customer accounts"<<endl;
		cout<<"6 Add new account"<<endl;
		cout<<"7 Delete account"<<endl;
		cout<<"8 Withdraw from account"<<endl;
		cout<<"9 Deposit to account"<<endl;
		cout<<"10 Transfer"<<endl;
		cout<<"11 Display info for the bank"<<endl;
		cout<<"12 Quit"<<endl;
		cout<<"Input your choice (1-12):"<<endl;
}

long int checkInput(const string & input)
{
	long int result = 0;
	for(int i = 0; i <input.size(); i++)
	{
		if(isDigit(input[i]))
		{
			result = result*10 + input[i]-'0';
		}
		else
		{
			string buffer;
			cout<<"Wrong input! Please enter a number."<<endl;
			cin>>buffer;
			return checkInput(buffer);
		}
	}
	return result;
}

int main()
{
	Bank BSK("BSK","Dondukov 6");
	int choice=0;
	long int customerID;
	string buffer;
	string name;
	string address;
	int accountType;
	string iban;
	long int ownerID;
	double amount;
	string fromIBAN;
	string toIBAN;
	BSK.addCustomer(1,"Tosho","Dupnica");
	BSK.addCustomer(2,"Doncho","Harmanli");
	BSK.addCustomer(3,"Gancho","Kaspichan");
	BSK.addAccount(1,"iban1",1,250);
	BSK.addAccount(1,"iban2",2,3000);
	BSK.addAccount(1,"iban3",3,10000);
	bool runLoop=true;

	while(runLoop)
	{
		printChoices();
		cin>>choice;
		switch(choice)
		{
			case 1:
				BSK.listCustomers();
				break;

			case 2:
				cout<<"Input customer ID."<<endl;
				cin >> buffer;
				customerID =checkInput(buffer);
				cout<<"Input name."<<endl;
				cin.ignore();
				getline(cin,name);
				cout<<"Input address."<<endl;
				getline(cin,address);
				BSK.addCustomer(customerID,name,address);
				break;

			case 3:
				cout<<"Input customer ID."<<endl;
				cin >> buffer;
				customerID =checkInput(buffer);
				BSK.deleteCustomer(customerID);
				break;

			case 4:
				BSK.listAccounts();
				break;

			case 5:
				cout<<"Input customer ID."<<endl;
				cin >> buffer;
				customerID =checkInput(buffer);

				BSK.listCustomerAccount(customerID);
				break;

			case 6:
				cout<<"1 Current Account"<<endl;
				cout<<"2 Savings Account"<<endl;
				cout<<"3 Privilege Account"<<endl;
				cout<<"Input account type."<<endl;
				cin>>accountType;
				while(accountType!=1 && accountType!=2 && accountType!=3)
				{
					cout<<"Input correct choice."<<endl;
					cin>>accountType;
				}

				cout<<"Input IBAN."<<endl;
				cin>>iban;
				cout<<"Input owner ID."<<endl;
				cin >> buffer;
				ownerID =checkInput(buffer);
				cout<<"Input amount."<<endl;
				cin>>amount;
				BSK.addAccount(accountType, iban, ownerID, amount);
				break;

			case 7:
				cout<<"Input IBAN"<<endl;
				cin.ignore();
				getline(cin,iban);
				BSK.deleteAccount(iban);
				break;

			case 8:
				cout<<"Input IBAN"<<endl;
				cin.ignore();
				getline(cin,iban);
				cout<<"Input amount."<<endl;
				cin>>amount;
				BSK.withdrawFromAccount(iban,amount);
				break;
			
			case 9:
				cout<<"Input IBAN"<<endl;
				cin.ignore();
				getline(cin,iban);
				cout<<"Input amount."<<endl;
				cin>>amount;
				BSK.depositToAccount(iban,amount);
				break;

			case 10:
				cout<<"Input IBAN for sender."<<endl;
				cin.ignore();
				getline(cin,fromIBAN);
				cout<<"Input IBAN for receiver."<<endl;
				//cin.ignore();
				getline(cin,toIBAN);
				cout<<"Input amount."<<endl;
				cin>>amount;
				BSK.transfer(fromIBAN,toIBAN,amount);
				break;

			case 11:
				BSK.display();
				break;

			case 12:
				runLoop=false;
				break;

			default:
				cout<<"Wrong input!"<<endl;
				cout<<"Ending program..."<<endl;
				runLoop=false;
				break;
				

		}
	}

	return 0;
}
