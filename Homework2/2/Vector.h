#ifndef VECTOR_H
#define VECTOR_H
#include<cstring>
#include<iostream>

using namespace std;

const int INITIAL_CAPACITY=100;
const int MULTIPLIER=2;

template <class T>
class Vector
{

public:
	T* data;
	int capacity;
	int size;
	Vector<T>(int capacity);
	Vector<T>(const Vector & other);
	Vector<T>();

	Vector<T>& operator=(const Vector & other);
	~Vector<T>();

	void copyVector(const Vector<T> * other);
	int getSize() const;

	// returns -1 if not found
	int getIndex(const T & item) const;

	void grow();

	T& operator[](int index) const;

	void add(const T & item);

	
	bool removeAt(int index);
	bool remove(T & item);




};
template <class T>
Vector<T>::~Vector()
{
	if(this->data)
	{
		delete[] data;
	}

}


template <class T>
Vector<T>::Vector()
{
	this->data=0;
	this->capacity=INITIAL_CAPACITY;
	this->data=new T[this->capacity];
	this->size=0;

}

template <class T>
Vector<T>::Vector(int capacity)
{
	this->data=0;
	this->data=new T[capacity];
	this->capacity=capacity;
	this->size=0;

}

template <class T>
void Vector<T>::copyVector(const Vector<T>* other)
{
	if(this->data)
	{
		delete[] this->data;
		this->data=0;
	}

	this->capacity=other->capacity;
	this->size=other->size;
	this->data=new T[other->capacity];
	for(int i=0;i<other->size;i++)
	{
		this->data[i]=other->data[i];
	}

}

template <class T>
Vector<T>::Vector(const Vector & other)
{
	copyVector(&other);

}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector & other)
{
	if(this!=&other)
	{
		copyVector(&other);
	}
	return *this;
}

template <class T>
int Vector<T>::getSize() const
{
	
	return this->size;
}

template <class T>
void Vector<T>::grow()
{
	int newCapacity=this->capacity*MULTIPLIER;
	T * newData = new T[newCapacity];
	
	for(int i=0;i<this->size;i++)
	{
		newData[i]=this->data[i];
	}

	delete[] this->data;
	this->data=0;
	this->data=newData;
	this->capacity=newCapacity;

}

template <class T>
int Vector<T>::getIndex(const T & item) const
{
	for(int i=0;i<this->size;i++)
	{
		if (this->data[i]==item)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
T& Vector<T>::operator[](int index) const
{
	if(index>=-1 && index<this->size)
	{
		return this->data[index];
	}
	
}



template<class T>
bool Vector<T>::removeAt(int index)
{
	if(index>=0 && index<this->size)
	{
		for(int i=index+1;i<this->size;i++)
		{
			this->data[i-1]=this->data[i];
		}
		size--;
		return true;
	}
	return false;
}

template<class T>
bool Vector<T>::remove(T & item)
	{
	int itemIndex=this->getIndex(item);
	if(itemIndex!=-1)
	{
		this->removeAt(itemIndex);
		return true;
	}

	return false;

}

template<class T>
void Vector<T>::add(const T & other)
{
	if(this->size==this->capacity)
	{
		this->grow();
	}
	this->data[this->size]=other;
	this->size++;
}

#endif
