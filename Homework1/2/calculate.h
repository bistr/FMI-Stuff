#ifndef CALCULATE_H
#define CALCULATE_H


#include <iostream>
#include <cstring>
#include "Stack.h"

bool isDigit(char symbol);
double calculate(char* polska, Stack& numberStack);

double calculate(char* polska)
{
	Stack numberStack;
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
			numberStack.push(number+flpoint);
		}

		if (polska[i]!=' ') {
			double num2=numberStack.pop();
			double num1=numberStack.pop();
			double res=0;
			switch (polska[i]){
				case '+':
					res=num1+num2;
					break;
				case '-':
					res=num1-num2;
					break;
				case '*':
					res=num1*num2;
					break;
				case '/':
					res=num1/num2;
					break;
				case '%':
					res=(int)num1%(int)num2;
					break;

}
		numberStack.push(res);
		}
	}
	return numberStack.pop();
}


bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

#endif
