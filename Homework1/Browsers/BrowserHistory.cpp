#include "HistoryEntry.h"
#include <cstring>

BrowserHistory::BrowserHistory(unsigned int capacity)
{	
	size=capacity
	top=-1
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


HistoryEntry * BrowserHistory::peek() const
{
	return  history[top];
}

HistoryEntry * BrowserHistory::pop()
{
	if (isEmpty())
	{
		return -1;
	}
	return history[top--];
}

void BrowserHistory::push(double newElement)
{
	if(isFull())
	{
		grow();
	}
	history[++top]=newElement;
}

