#include <iostream>
#include <regex>
using namespace std;

int main()
{
	regex url("(\\+|-)?[[:digit:]]+");
	char str[10]="bistra";
	int str1=5;
	return 0;
	if (regex_match(url,str1))
	{
		cout<<"congratulations!";
	}
}