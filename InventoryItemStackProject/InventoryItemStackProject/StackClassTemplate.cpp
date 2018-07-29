#include "StackClassTemplate.h"
#include <stddef.h>
#include <iostream>
#include <iomanip>

using namespace std;

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
		else // Pop value off top of stack
		{
			value = top->value;
			temp = top;
			top = top->next;
			delete temp;
			//cout << "popped " << setprecision(2) << value << " off stack..." << endl;
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