#include "Stack.h"
#include <iostream>

#include "calculate.h"
using namespace std;

int main()
{
	char h[50]={"5 1 2 + 4 * + 3  + 8 %"};
	double k=calculate(h);
	cout<<k;


	return 0;
	
}
