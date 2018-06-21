#include "HistoryEntry.h"
#include "BrowserHistory.h"
#include <iostream>

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

HistoryEntry BrowserHistory::peek() const
{
	return  history[top];
}

HistoryEntry BrowserHistory::pop()
{
	if (isEmpty())
	{
		return HistoryEntry(0,"Null");
	}
	return history[top--];
}

void BrowserHistory::setSize(int size1)
{
	size=size1;
}

void BrowserHistory::setTop(int top1)
{
	top=top1;
}

int BrowserHistory::getSize()
{
	return size;
}

int BrowserHistory::getTop()
{
	return top;
}


BrowserHistory BrowserHistory::concat(const BrowserHistory& br2)
{
	BrowserHistory newBr=BrowserHistory(size+br2.size);
	newBr.setTop(top+br2.top+1);
	for(int i=0;i<=top;i++)
	{
		newBr.history[i]=history[i];
	}

	for(int j= top+1;j<=newBr.top;j++)
	{
		newBr.history[j]=br2.history[j-top-1];
	} 
	cout.flush();
	return newBr;
}


void BrowserHistory::addNewSite()
{
	if (isFull())
	{
		cout<<"Error! History is full."<<endl;
		return;
	}
	int newDate;
	char*newUrl;
	cout<<"Input URL"<<endl;
	cin>>newUrl;
	cout<<"Input month [1-12]"<<endl;
	cin>>newDate;
	while(newDate<1 || newDate>12)
	{
		cin>>newDate;
	}
	history[++top]=HistoryEntry(newDate,newUrl);
}

void BrowserHistory::addNewSite(const HistoryEntry& newSite)
{
	if (isFull())
	{
		cout<<"Error! History is full."<<endl;
		return;
	}
	history[++top]=newSite;
}

void BrowserHistory::removeLatest()
{
	top--;
}

void BrowserHistory::viewAll()
{
	cout<<"Url"<<"\t\t\t"<<"Date"<<endl;

	for(int i=0;i<=top;i++)
	{
		cout<<history[i].url<<"\t\t"<<history[i].date<<endl;
	}
	cout.flush();
}

unsigned int BrowserHistory::findCountByMonth(unsigned short int month)
{
	unsigned int counter=0;

	for(int i=0;i<=top;i++)
	{
		if (history[i].date==month)
		{
			counter++;
		}
	}
	return counter;
}

unsigned short int BrowserHistory::findMonthWithMaxSites()
{
	unsigned short int result=0;
	int maxSites=0;

	for (int month=1;month<13;month++)
	{
		if (this->findCountByMonth(month)>=maxSites)
		{
			maxSites=this->findCountByMonth(month);
			result=month;
			cout.flush();
		}
	}
	return result;
}