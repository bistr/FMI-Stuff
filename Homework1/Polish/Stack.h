#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	double* arr;
	int top;
	int size;


public:
	Stack();
	Stack (Stack const&);

	~Stack();
	bool isFull() const;
	bool isEmpty() const;
	void grow();

	Stack& operator=(Stack const&);

	double peek() const;
	double pop();
	void push(double);


};

#endif