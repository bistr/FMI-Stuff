#ifndef PRODUCT_H
#define PRODUCT_H

#include <cstring>

enum IcecreamType 
{

	Normal,
	Vegan,
	GlutenFree,
	DairyFree,
	NutFree,
	JoyFree,
	MeatballFree

};

class Product
{
	
	private:

		int SKU;
		char * brand;
		IcecreamType model;
		char * flavor; 
		unsigned int milliliters;
		double price;
		unsigned int count;

	public:
		Product();
		Product(int SKU, char const * brand, int model, char const * flavor, unsigned int milliliters, double price, unsigned int count);
		Product(Product const & other);
		Product & operator=(Product const & other);

		void edit();

		char * getBrand() const;
		void setBrand(char const * brand);

		IcecreamType getModel() const;
		void setModel(IcecreamType model);

		char * const getFlavor() const;
		void setFlavor(char const * flavor);

		unsigned int getMilliliters() const;
		void setMilliliters(unsigned int milliliters); 

		double getPrice() const;
		void setPrice(double price);

		unsigned int getCount() const;
		void setCount(unsigned int count);

		int getSKU() const;
		void setSKU(int SKU);

		void print();
};


#endif