#ifndef HISTORYENTRY_H
#define HISTORYENTRY_H


#include <cstring>
struct HistoryEntry
{
	unsigned short int date;
	char * url;

	HistoryEntry()
	{
		date=0;
		url='\0';
	}

	HistoryEntry(unsigned short int date1, char const * url1)
	{
		unsigned short int newLength=strlen(url1)+1;
		char * newurl= new char[newLength];
		//strcpy(newurl,url1);
		memcpy(newurl,url1,newLength);
		date=date1;
		url=newurl;
	}



};

#endif
