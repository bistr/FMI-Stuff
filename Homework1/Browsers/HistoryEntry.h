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

	HistoryEntry(unsigned short int date1, char * url1)
	{
		char * newurl= new char[strlen(url1)+1];
		for (int i=0; i<strlen(url1); i++)
		{
			newurl[i]=url1[i];
		}
		strcpy(newurl,url1);
		date=date1;
		url=newurl;
	}



};

#endif