#include <iostream>
#include "Stack.h"
#include "calculate.h"
using namespace std;


//TODO Razkarai tiq shitni ot tuka

Stack::Stack()
{
	size=100;
	arr=new double[size];
	top=-1;
}

Stack::Stack(Stack const& other)
{
	size=other.size;
	top=other.top;
	for (int i = 0; i <= top; ++i)
	{
		arr[i]=other.arr[i];
	}
}


Stack::~Stack()
{
	delete[] arr;
}

Stack& Stack::operator=(Stack const& other)
{
	if (this!=&other)
	{
		size=other.size;
		top=other.top;
		for (int i = 0; i <= top; ++i)
		{
			arr[i]=other.arr[i];
		}
	}
	return *this;
}



bool Stack::isEmpty() const
{
	return top==-1;
}

bool Stack::isFull() const
{
	return top==size-1;
}

void Stack::grow()
{
	size*=2;
	double *newArr=new double[size];
	for (int i = 0; i <= top; ++i)
	{
		newArr[i]=arr[i];
	}
	delete[] arr;
	arr=newArr;
}

double Stack::peek() const
{
	return arr[top];
}

double Stack::pop()
{
	if (isEmpty())
	{
		return -1;
	}
	return arr[top--];
}

void Stack::push(double newElement)
{
	if(isFull())
	{
		grow();
	}
	arr[++top]=newElement;
}

int main()
{
	char h[20]={"5 1 2 + 4 * + 3  -"};
	double k=calculate(h);
	cout<<k;


	return 0;
	
}