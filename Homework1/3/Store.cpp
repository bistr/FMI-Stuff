#include "Product.h"
#include "Store.h"
#include <iostream>

#include <cstring>
using namespace std;

Store::Store(unsigned int capacity)
{	
	size=capacity;
	top=-1;
	inventory=new Product[size];
}

Store::Store(Store const& other)
{
	size=other.size;
	top=other.top;
	for (int i = 0; i <= top; ++i)
	{
		inventory[i]=Product(other.inventory[i]);
	}
}

Store::~Store()
{
	delete[] inventory;
}

Store& Store::operator=(Store const& other)
{
	if (this!=&other)
	{
		size=other.size;
		top=other.top;
		for (int i = 0; i <= top; ++i)
		{
			inventory[i]=Product(other.inventory[i]);
		}
	}
	return *this;
}

bool Store::isEmpty() const
{
	return top==-1;
}

bool Store::isFull() const
{
	return top==size-1;
}


void Store::setSize(int size1)
{
	size=size1;
}

void Store::setTop(int top1)
{
	top=top1;
}

int Store::getSize()
{
	return size;
}

int Store::getTop()
{
	return top;
}


void Store::addProduct()
{
	if (isFull())
	{
		cout<<"Error! Inventory is full."<<endl;
		return;
	}
	 Product newProduct;
	 int SKU;
	 char * brand;
	IcecreamType model;
	char * flavor; 
	unsigned int milliliters;
	double price;
	unsigned int count;

	newProduct.setSKU(SKU);
	newProduct.setBrand(brand);
	newProduct.setModel(model);
	newProduct.setFlavor(flavor);
	newProduct.setMilliliters(milliliters);
	newProduct.setPrice(price);
	newProduct.setCount(count);



	inventory[++top]=newProduct;
}

void Store::addProduct(const Product& newProduct)
{
	if (isFull())
	{
		cout<<"Error! Inventory is full."<<endl;
		return;
	}
	inventory[++top]=newProduct;
}

void Store::removeProduct()
{
	int sku;
	cout<<"Enter SKU to remove"<<endl;
	cin>>sku;
	/*for (int i=0;i<=top;i++){
			
				if (inventory[i].getSKU()==sku)
				{
					Product swap;
					swap=inventory[i];
					inventory[i]=inventory[top];
					inventory[top]=swap;
					top--;
				}
			}
			*/
		}


void Store::viewAll()
{
	int fullCount=0;
	for(int i=0;i<=top;i++)
	{
		inventory[i].print();
		fullCount+=inventory[i].getCount();
		cout<<endl;
	}
	cout.flush();
	cout<<"Total of "<<fullCount<<" items in the store."<<endl;
}

