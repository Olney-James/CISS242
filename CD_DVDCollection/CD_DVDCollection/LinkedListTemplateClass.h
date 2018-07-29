/***********************************************************
Program: LinkedListTemplateClass.h (Week 8 Course Project)

Detail: This is the Linked List file that DVD and CD use to sort their objects.

Author: James Olney
Created: 04/22/2017
Revisions: N/A
*******************/

#ifndef LINKEDLISTTEMPLATECLASS_H
#define LINKEDLISTTEMPLATECLASS_H
#pragma once
#include <iostream>
using namespace std;

template <class T>
class LinkedListTemplateClass {
private:
	struct ListNode {
		T data;
		ListNode *next;
		ListNode() {};
	};
	ListNode *head;
public:
	LinkedListTemplateClass();
	~LinkedListTemplateClass();//destructor
	void appendNode(T node);
	void insertNode(T node);
	void deleteNode(T node);
	void displayTheContentsOfTheListToTheScreen() const;
	void displayTheContentsOfTheListToTheScreenWithSpacing() const;
	void displayTheContentsOfTheListToTheScreenWithLessSpacing() const;
	int searchTheListForAnElementInTheList(T node);
	T provideAnItemFromTheList(int index);
};
#endif

template<class T>
LinkedListTemplateClass<T>::LinkedListTemplateClass() {
	head = nullptr;
}

template<class T>
LinkedListTemplateClass<T>::~LinkedListTemplateClass() {
	ListNode *nodePtr;
	ListNode *nextNode;

	nodePtr = head;

	while (nodePtr != NULL) {
		nextNode = nodePtr->next;
		nodePtr = nextNode;
	}
}

template<class T>
void LinkedListTemplateClass<T>::appendNode(T node) {
	ListNode *newNode = new ListNode;
	ListNode *nodePtr;
	newNode->data = node;
	newNode->next = NULL;

	if (!head) {
		head = newNode;
	}
	else {
		nodePtr = head;
		while (nodePtr->next != NULL) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
}

template<class T>
void LinkedListTemplateClass<T>::insertNode(T node) {
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = NULL;

	newNode = new ListNode;
	newNode->data = node;

	if (!head) {
		head = newNode;
		newNode->next = NULL;
	}
	else {
		nodePtr = head;
		previousNode = NULL;
		while (nodePtr != NULL && nodePtr->data < node) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

template<class T>
void LinkedListTemplateClass<T>::deleteNode(T node) {
	ListNode *nodePtr;
	ListNode *previousNode = NULL;

	if (!head) {
		return;
	}

	if (head->data == node) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;

		while (nodePtr != nullptr&& nodePtr->data != node) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}
template<class T>
void LinkedListTemplateClass<T>::displayTheContentsOfTheListToTheScreen() const {
	ListNode *nodePtr;

	if (!head) {
		return;
	}

	nodePtr = head;

	while (nodePtr != nullptr) {
		cout << nodePtr->data;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

template<class T>
void LinkedListTemplateClass<T>::displayTheContentsOfTheListToTheScreenWithSpacing() const {
	ListNode *nodePtr;

	if (!head) {
		return;
	}

	nodePtr = head;

	while (nodePtr != nullptr) {
		cout << "                                                " << nodePtr->data;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

template<class T>
void LinkedListTemplateClass<T>::displayTheContentsOfTheListToTheScreenWithLessSpacing() const {
	ListNode *nodePtr;

	if (!head) {
		return;
	}

	nodePtr = head;

	while (nodePtr != nullptr) {
		cout << "                                " << nodePtr->data;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}
template<class T>
int LinkedListTemplateClass<T>::searchTheListForAnElementInTheList(T node) {
	int index = 0;
	ListNode *nodePtr;

	if (!head) {
		return -1;
	}
	nodePtr = head;
	while (nodePtr != nullptr && nodePtr->data != node) {
		nodePtr = nodePtr->next;
		index++;
	}
	if (nodePtr == nullptr) {
		index = -1;
	}

	return index;
}

template<class T>
T LinkedListTemplateClass<T>::provideAnItemFromTheList(int index)
{
	ListNode *nodePtr;
	T item;
	int x = 0;
	nodePtr = head;

	while (x < index && nodePtr != nullptr) {
		nodePtr = nodePtr->next;
		x++;
	}

	item = nodePtr->data;
	return item;
}
