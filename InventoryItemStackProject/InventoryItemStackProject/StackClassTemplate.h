/*************************************
Program: StackClassTemplate.h (Week 5 Programming Assignment 2)

Author: James Olney
Created: 03/30/2017
Revisions: N/A

This is my own version of a class template that will create
a dynamic stack of any data type. The pop function returns
a bool; it returns a false if it was not able to pop an item
off the stack. Otherwise, it returns true. The parameter to
the pop function is passed by a reference and is the item on
the list if it was able to pop something.

**************************************/
#ifndef STACKCLASSTEMPLATE_H
#define STACKCLASSTEMPLATE_H
#pragma once
#include <stddef.h>
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class StackClassTemplate {
private:
	T *stackArray;
	int stackSize;
	class StackNode
	{
		friend class StackClassTemplate;
		T value;
		StackNode *next;
		// Constructor.
		StackNode(T value1, StackNode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	StackNode *top;
public:
	StackClassTemplate();
	//StackClassTemplate(const StackClassTemplate &);
	//~StackClassTemplate();
	void push(T);
	bool pop(T &);
	bool isEmpty() const;
	void printStack();
	T getTopValue();
};

/*************************************
Program: StackClassTemplate.cpp (Week 5 Programming Assignment 1)

Author: James Olney
Created: 03/30/2017
Revisions: N/A

This is my own version of a class template that will create
a dynamic stack of any data type. The pop function returns
a bool; it returns a false if it was not able to pop an item
off the stack. Otherwise, it returns true. The parameter to
the pop function is passed by a reference and is the item on
the list if it was able to pop something.

**************************************/


template<class T>
StackClassTemplate<T>::StackClassTemplate()
{
	top = NULL;
}

template<class T>
void StackClassTemplate<T>::push(T value)
{
	top = new StackNode(value, top);
	//cout << "pushed " << value << " onto stack..." << endl;
}

template<class T>
bool StackClassTemplate<T>::pop(T &value)
{
	{
		StackNode *temp;

		if (isEmpty())
		{
			cout << "The stack is empty.\n";
			return false;
			//exit(1);
		}
		else if (value != top->value) {
			cout << "the pop's value (" << top->value << ") does not match your parameter value (" << value << ")" << endl;
			return false;
		}
		else // Pop value off top of stack
		{
			//value = top->value;
			temp = top;
			top = top->next;
			delete temp;
			cout << "popped " << setprecision(2) << value << " off stack..." << endl;
			return true;
		}
	}
}

template<class T>
bool StackClassTemplate<T>::isEmpty() const
{
	if (!top)
		return true;
	else
		return false;
}

template<class T>
void StackClassTemplate<T>::printStack()
{
	StackNode *temp;
	temp = top;
	while (temp) {
		cout << temp->value << ", ";
		temp = temp->next;
	}
	cout << endl;
}
template<class T>
inline T StackClassTemplate<T>::getTopValue()
{
	return top->value;
}
#endif