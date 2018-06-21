#include <iostream>
#include "HistoryEntry.h"
#include "BrowserHistory.h"
#include <cstring>
using namespace std;


BrowserHistory::BrowserHistory(unsigned int capacity)
{	
	size=capacity;
	top=-1;
	history=new HistoryEntry[size];
}

BrowserHistory::BrowserHistory(BrowserHistory const& other)
{
	size=other.size;
	top=other.top;
	for (int i = 0; i <= top; ++i)
	{
		history[i]=other.history[i];
	}
}


BrowserHistory::~BrowserHistory()
{
	delete[] history;
}

BrowserHistory& BrowserHistory::operator=(BrowserHistory const& other)
{
	if (this!=&other)
	{
		size=other.size;
		top=other.top;
		for (int i = 0; i <= top; ++i)
		{
			history[i]=other.history[i];
		}
	}
	return *this;
}



bool BrowserHistory::isEmpty() const
{
	return top==-1;
}

bool BrowserHistory::isFull() const
{
	return top==size-1;
}


HistoryEntry  BrowserHistory::peek() const
{
	return  history[top];
}

HistoryEntry * BrowserHistory::pop()
{
	if (isEmpty())
	{
		return nullptr;
	}
	return history[top--];
}

void BrowserHistory::push(HistoryEntry newElement)
{

	history[++top]=newElement;
}



int main()
{
	HistoryEntry bisi(4,"pizza.com");
	BrowserHistory br= new BrowserHistory(5);

	cout<<bisi.url;
//char k[10]={"hello"};

	return 0;
}