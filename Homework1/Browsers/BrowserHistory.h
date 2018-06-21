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
	void grow();

	BrowserHistory& operator=(BrowserHistory const&);

	HistoryEntry  peek() const;
	HistoryEntry * pop();
	void push(HistoryEntry);


};

#endif