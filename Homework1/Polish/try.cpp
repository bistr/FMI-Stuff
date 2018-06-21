#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;

bool isDigit(char symbol);
double calculate(char* polska);

double calculate(char* polska)
{
	//Stack numberStack;
	for (int i=0; i<strlen(polska); i++)
	{

		if(isDigit(polska[i]))
		{	
			double number=0;
			double flpoint=0;
			double div=10;
			while(isDigit(polska[i]))
			{
				number=10*number+(polska[i]-'0');	
				i++;
			}
			if (polska[i]=='.')
			{
				i++;
				while(isDigit(polska[i]))
				{
					flpoint+=(double)(polska[i]-'0')/div;	
					i++;
					div*=10;
				}
			}
			cout<<number+flpoint<<endl;
		}
	}
}


bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

int main()
{
	char h[60]={"124.34+18.45+7.9+1275.46"};
	calculate(h);
	return 0;
}