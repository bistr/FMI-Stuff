#ifndef SETTINGS_H
#define SETTINGS_H
#include<cstring>
#include<iostream>
#include "Pair.h"
#include "Vector.h"

using namespace std;
template <class T>
class Settings
{
private:
	
public:
	Vector<Pair <T>* > pairs;
	Settings<T>();
	Settings<T>(const Settings<T>& other);
	Settings<T> & operator = (const Settings<T> & other);
	int count();
	void add(const Pair<T> & pair);
	void set(const char * key, T value);
	bool get(const char * key, T& value);
	void print();
};

template <class T>
Settings<T>::Settings()
{
}

template <class T>
Settings<T>::Settings(const Settings<T>& other)
{
	this->pairs=other.pairs;
}

template <class T>
Settings<T> & Settings<T>::operator = (const Settings<T> & other)
{
	if(this != &other)
	{
		this->pairs=other.pairs;
	}
	return *this;
}

template <class T>
int Settings<T>::count()
{
	return this->pairs.getSize();
}

template <class T>
void Settings<T>::add(const Pair<T> & pair)
{
	this->pairs.add(new Pair<T>(pair));
}

template <class T>
void Settings<T>::set(const char * key, T value)
{
	for(int i=0;i<pairs.getSize();i++)
	{
		if(strcmp(pairs[i]->getKey(),key)==0)
		{
			pairs[i]->setValue(value);
			return;
		}
	}
	this->add(Pair<T>(key,value));
	return;
}

template <class T>
bool Settings<T>::get(const char * key, T & value)
{
	for(int i=0;i<pairs.getSize();i++)
	{
		if(strcmp(pairs[i]->getKey(),key)==0)
		{
			value=pairs[i]->getValue();
			return true;
		}
	}
	return false;
}

template <class T>
void Settings<T>::print()
{
	for(int i=0;i<pairs.getSize();i++)
	{
		cout<<pairs[i]->getKey()<<"\t"<<pairs[i]->getValue()<<endl;
	}
}



#endif



