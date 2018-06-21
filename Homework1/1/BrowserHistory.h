#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H
#include "HistoryEntry.h"

class BrowserHistory
{
private:
	HistoryEntry* history;
	int top;
	int size;
	

public:

	BrowserHistory(unsigned int capacity);
	BrowserHistory (BrowserHistory const&);

	~BrowserHistory();
	bool isFull() const;
	bool isEmpty() const;

	BrowserHistory& operator=(BrowserHistory const&);

	HistoryEntry peek() const;
	HistoryEntry pop();
	void push(HistoryEntry);
	void addNewSite();
	void addNewSite(const HistoryEntry& newSite);
	void removeLatest();
	void viewAll();
	unsigned int findCountByMonth(unsigned short int month);
	unsigned short int findMonthWithMaxSites();
	BrowserHistory concat(const BrowserHistory& br2);
	int getSize();
	int getTop();
	void setSize(int size);
	void setTop(int top);
	

};

#endif
