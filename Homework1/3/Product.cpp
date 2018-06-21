#include "Product.h"
#include <cstring>
#include <iostream>

using namespace std;

const int MAX_LENGTH=50;

Product::Product()
{
	this->SKU=0;
	this->brand="0";
	this->model=(IcecreamType)0;
	this->flavor="0";
	this->milliliters=0;
	this->price=0;
	this->count=0;
}

Product::Product(int SKU,char const * brand, int model, char const * flavor, unsigned int milliliters, double price, unsigned int count)
{
	this->SKU=SKU;
	unsigned int length=strlen(brand)+1;
	char * newBrand=new char[length];
	memcpy(newBrand,brand,length);
	this->brand=newBrand;
	//memcpy(this->brand,newBrand,length);

	this->model=(IcecreamType)model;
	length=strlen(flavor)+1;
	char * newFlavor= new char[length];
	memcpy(newFlavor,flavor,length);
	this->flavor=newFlavor;
	this->milliliters=milliliters;
	this->price=price;
	this->count=count;
}


Product::Product(Product const & other)
{
	this->SKU=other.SKU;
	unsigned int length=strlen(other.brand)+1;
	char * newBrand=new char[length];
	memcpy(newBrand,other.brand,length);
	this->brand=newBrand;
	//memcpy(this->brand,newBrand,length);

	this->model=other.model;
	length=strlen(other.flavor)+1;
	char * newFlavor= new char[length];
	memcpy(newFlavor,other.flavor,length);
	this->flavor=newFlavor;
	this->milliliters=other.milliliters;
	this->price=other.price;
	this->count=other.count;	
}


Product & Product ::operator=(Product const & other)
{
	if (this!=&other)
	{
		this->SKU=other.SKU;
		unsigned int length=strlen(other.brand)+1;
		char * newBrand=new char[length];
		memcpy(newBrand,other.brand,length);
		this->brand=newBrand;
		//memcpy(this->brand,newBrand,length);

		this->model=other.model;
		length=strlen(other.flavor)+1;
		char * newFlavor= new char[length];
		memcpy(newFlavor,other.flavor,length);
		this->flavor=newFlavor;
		this->milliliters=other.milliliters;
		this->price=other.price;
		this->count=other.count;
	}
	return *this;

}

void Product::edit()
{
	int choice;
	cout<<"What do you want to edit? Enter a number."<<endl;
	cout<<"1 Brand"<<endl;
	cout<<"2 Model"<<endl;
	cout<<"3 Flavor"<<endl;
	cout<<"4 Milliliters"<<endl;
	cout<<"5 Price"<<endl;
	cout<<"6 Count"<<endl;
	cin>>choice;
	while(choice<1 || choice>6)
	{
		cout<<"Wrong choice. Try again"<<endl;
		cin>>choice;
	}
	switch(choice)
	{
		case 1:
		{
			char * newBrand = new char[MAX_LENGTH+1];
			cout<<"Input new brand name:"<<endl;
			cin.ignore();
			cin.getline(newBrand,MAX_LENGTH);
			int newLength;
			newLength=strlen(newBrand)+1;
			memcpy(this->brand,newBrand,newLength);
			break;
		}
		case 2:
			int newModel;
			cout<<"Input model index from 0 to 5"<<endl;
			cin>>newModel;
			this->model=(IcecreamType)newModel;
			break;

		case 3:
		{
			char * newFlavor= new char[MAX_LENGTH+1];
			cout<<"Input new flavor name:"<<endl;
			cin.ignore();
			cin.getline(newFlavor,MAX_LENGTH);
			int newLength=strlen(newFlavor)+1;
			memcpy(this->flavor,newFlavor,newLength);
			break;
		}
		case 4:
			unsigned int milliliters;
			cout<<"Input milliliters"<<endl;
			cin>>milliliters;
			this->milliliters=milliliters;
			break;

		case 5:
			double price;
			cout<<"Input price"<<endl;
			cin>>price;
			this->price=price;
			break;

		case 6:
			unsigned int count;
			cout<<"Input count"<<endl;
			cin>>count;
			this->count=count;
			break;

		default:
			cout<<"You chose ... poorly."<<endl;


	} 
}

char * Product::getBrand() const
{
	return brand;
};

void Product::setBrand(char const * brand)
{
	int length=strlen(brand)+1;
	memcpy(this->brand, brand, length);
};

IcecreamType Product::getModel() const
{
	return model;
};
void Product::setModel(IcecreamType model)
{
	this->model=model;
};

char * const Product::getFlavor() const
{
	return flavor;
};
void Product::setFlavor(char const * flavor)
{
	int length=strlen(flavor)+1;
	memcpy(this->flavor, flavor, length);
};

unsigned int Product::getMilliliters() const
{
	return milliliters;
};
void Product::setMilliliters(unsigned int milliliters)
{
	this->milliliters=milliliters;
};

double Product::getPrice() const
{
	return price;
};
void Product::setPrice(double price)
{
	this->price=price;
};

unsigned int Product::getCount() const
{
	return count;
};
void Product::setCount(unsigned int count)
{
	this->count=count;
};

void Product::print()
{
	cout<<"SKU: "<<SKU<<endl;
	cout<<"Brand: "<<this->brand<<endl;
	cout<<"Model: "<<(IcecreamType)model<<endl;
	cout<<"Flavor: "<<flavor<<endl;
	cout<<"Milliliters: "<<milliliters<<endl;
	cout<<"Price: "<<price<<endl;
	cout<<"Count: "<<count<<endl;

}

int Product::getSKU() const
{
	return SKU;
}

void Product::setSKU(int SKU)
{
	this->SKU=SKU;
}