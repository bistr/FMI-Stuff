#ifndef PAIR_H
#define PAIR_H
#include<cstring>
#include<iostream>
using namespace std;
template <class T>
class Pair
{
private:
	char * key;
	T value;
public:
	
	Pair()
	{
		this->key=0;
		this->value=0;	
	};
	
	Pair(char const * key, T value)
	{
		this->key=new char[strlen(key)+1];
		strcpy(this->key,key);
		this->value=value;
		
	};
	Pair(const Pair<T> & other)
	{
		this->key=new char[strlen(other.key)+1];
		strcpy(this->key,other.key);
		this->value=other.value;
	};
	
	~Pair()
	{
		delete[] this->key;

	}
	
	Pair & operator=(const Pair<T> & other)
	{
		if(this!=&other)
	{
		this->key=new char[strlen(other.key)+1];
		strcpy(this->key,other.key);
		this->value=other.value;
	}
	return *this;
};

	T getValue()
	{
		return this->value;
	};

	char * getKey()
	{
		return this->key;
	}

	void setValue(T value)
	{
		this->value=value;
	}


};

#endif
