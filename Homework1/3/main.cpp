#include <iostream>
#include <cstring>
#include <stdio.h>
#include "Product.h"
#include "Store.h"
using namespace std;


int main()
{
	Store newStore=Store(20);
	char  choice;

	while (true)
	{
			cout<<" A for ADD"<<endl;
	cout<<"X for DELETE"<<endl;
	cout<<"C for EDIT"<<endl;
	cout<<"D for DISPLAY"<<endl;
	cout<<"Q for QUIT"<<endl;	
		cin>>choice;
		if (choice=='A')
		{
			newStore.addProduct();
		}
		if (choice=='X')
		{
			newStore.removeProduct();
			cout<<"Enter";
		}
		if (choice=='C')
		{
			int sku;
			cout<<"Which SKU will you change?"<<endl;
			cin>>sku;
			for (int i=0;i<newStore.getTop();i++)
			{
				if (newStore.inventory[i].getSKU()==sku)
				{
					newStore.inventory[i].edit();
				}
			}
		}
		if(choice=='D')
		{
			newStore.viewAll();
		}
		if(choice=='Q')
		{
			break;
		}
	} 

return 0;
}