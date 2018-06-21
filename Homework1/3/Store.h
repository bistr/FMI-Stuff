#ifndef STORE_H
#define STORE_H
#include "Product.h"

class Store
{
private:

	int top;
	int size;
	

public:
	Product * inventory;
	Store(unsigned int capacity);
	Store (Store const&);

	~Store();
	bool isFull() const;
	bool isEmpty() const;
	Store& operator=(Store const&);
	void addProduct();
	void addProduct(Product const&);
	void removeProduct();
	void viewAll();
	int getSize();
	int getTop();
	void setSize(int size);
	void setTop(int top);
	

};

#endif