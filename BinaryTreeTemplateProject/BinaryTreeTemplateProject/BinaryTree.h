/*************************************
Program: BinaryTree.h (Week 7 Programming Assignment 2)

Author: James Olney
Created: 04/15/2017
Revisions: N/A

This is BinaryTree.h that was written for Assignment 1. It allows the EmployeeInfo
objects to be sorted into a binary tree that can then be searched through, displayed
in different orders, deleted, and provide different quantities (see assignment 1)

**************************************/

#ifndef BINARYTREE_H
#define BINARYTREE_H
#pragma once
//#include <stddef.h>
//#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class BinaryTree {
private:
	int count = 0;
	class TreeNode {
	private:
		T value;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode(T value1, TreeNode *left1 = NULL, TreeNode *right1 = NULL)
		{
			value = value1;
			left = left1;
			right = right1;
		}
		TreeNode* getLeft() {
			return left;
		}
		TreeNode* getRight() {
			return right;
		}
		T getValue() {
			return value;
		}
		void setValue(T v) {
			value = v;
		}
		void setLeft(T v) {
			left->setValue(v);
		}
		bool add(T value) {
			if (this == NULL) {
				this->setValue(value);
			}
			else {
				if (value > this->value) {
					if (right == NULL) {
						this->right = new TreeNode(value);
					}
					else {
						return right->add(value);
					}
				}
				else {
					if (left == NULL) {
						this->left = new TreeNode(value);
					}
					else {
						return left->add(value);
					}
				}
			}
		}
		TreeNode* deleteNode(int value, TreeNode *parent) {
			if (value < this->value) {
				if (left != NULL)
					return left->deleteNode(value, this);
				else
					return NULL;
			}
			else if (value > this->value) {
				if (right != NULL)
					return right->deleteNode(value, this);
				else
					return NULL;
			}
			else {
				if (left != NULL && right != NULL) {
					this->value = right->minValue();
					return right->deleteNode(this->value, this);
				}
				else if (parent->left == this) {
					parent->left = (left != NULL) ? left : right;
					return this;
				}
				else if (parent->right == this) {
					parent->right = (left != NULL) ? left : right;
					return this;
				}
			}
		}
		T minValue() {
			if (left == NULL) {
				return value;
			}
			else {
				return left->minValue();
			}
		}
	};
	TreeNode *root;
public:
	BinaryTree();
	//~BinaryTree();
	
	bool insertNode(T value);
	bool deleteNode(T value);
	void displayTreeInOrder(TreeNode *nodePtr) const;
	TreeNode* getRoot();
	void displayTreePreOrder(TreeNode *nodePtr) const;
	void displayTreePostOrder(TreeNode *nodePtr) const;
	bool searchFor(T item);
	int numberOfNodes();
	int countNodes(TreeNode *nodePtr);
	int numberOfLeafNodes();
	void countLeaves(TreeNode *nodePtr);
	int determineHeight(TreeNode *nodePtr); //the number of levels the tree hastt
	int getTreeHeight();
	//TreeNode& getRoot();
};



#endif // !BINARYTREE_H

template<class T>
inline BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template<class T>
inline typename BinaryTree<T>::TreeNode * BinaryTree<T>::getRoot()
{
	return root;
}

template<class T>
inline bool BinaryTree<T>::insertNode(T value) //if buggy try returning bool
{
	if (root == NULL) {
		root = new TreeNode(value);
		return true;
	}
	else {
		return root->add(value);
	}
}

template<class T>
inline bool BinaryTree<T>::deleteNode(T value)
{
	if (root == NULL) {
		return false;
	}
	else {
		if (root->getValue() == value) {
			TreeNode auxRoot(0);
			auxRoot.setLeft(root->getValue());
			TreeNode* removedNode = root->deleteNode(value, &auxRoot);
			root = auxRoot.getLeft();
			if (removedNode != NULL) {
				delete removedNode;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			TreeNode* removedNode = root->deleteNode(value, NULL);
			if (removedNode != NULL) {
				delete removedNode;
				return true;
			}
			else {
				return false;
			}
		}
	}
}

template<class T>
inline void BinaryTree<T>::displayTreeInOrder(TreeNode *nodePtr) const
{
	if (nodePtr) {
		displayTreeInOrder(nodePtr->getLeft());
		cout << nodePtr->getValue() << ", " << endl;
		displayTreeInOrder(nodePtr->getRight());
	}
}

template<class T>
inline void BinaryTree<T>::displayTreePreOrder(TreeNode *nodePtr) const
{
	if (nodePtr) {
		cout << nodePtr->getValue() << ", " << endl;
		displayTreePreOrder(nodePtr->getLeft());
		displayTreePreOrder(nodePtr->getRight());
	}
}

template<class T>
inline void BinaryTree<T>::displayTreePostOrder(TreeNode *nodePtr) const
{
	if (nodePtr) {
		displayTreePostOrder(nodePtr->getLeft());
		displayTreePostOrder(nodePtr->getRight());
		cout << nodePtr->getValue() << ", " << endl;
	}
}

template<class T>
inline bool BinaryTree<T>::searchFor(T item)
{
	TreeNode *nodePtr = root;
	while (nodePtr) {
		if (nodePtr->getValue() == item) {
			cout << nodePtr->getValue() << " was found..." << endl;
			return true;
		}
		else if (item < nodePtr->getValue()){
			nodePtr = nodePtr->getLeft();
		}
		else {
			nodePtr = nodePtr->getRight();
		}
	}
	cout << item << " was not found..." << endl;
	return false;
	}

template<class T>
inline int BinaryTree<T>::numberOfNodes()
{
	return countNodes(root);
}

template <class T>
int BinaryTree<T>::countNodes(TreeNode *nodePtr)
{
	if (nodePtr == NULL)
		return 0;
	else
		return 1 + countNodes(nodePtr->getLeft()) + countNodes(nodePtr->getRight());
}

template<class T>
inline int BinaryTree<T>::numberOfLeafNodes()
{
	count = 0;
	countLeaves(root);
	return count;
}

template<class T>
inline void BinaryTree<T>::countLeaves(TreeNode * nodePtr)
{
	if (nodePtr) {
		countLeaves(nodePtr->getLeft());
		countLeaves(nodePtr->getRight());
		if (nodePtr->getLeft() == NULL && nodePtr->getRight() == NULL) {
			count++;
		}
	}
}

template<class T>
inline int BinaryTree<T>::determineHeight(TreeNode *nodePtr)
{
	int leftHeight;
	int rightHeight;
	if (nodePtr) {
		leftHeight = determineHeight(nodePtr->getLeft());
		rightHeight = determineHeight(nodePtr->getRight());
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
	else {
		return 0;
	}
}

template<class T>
inline int BinaryTree<T>::getTreeHeight()
{
	return determineHeight(root);
}
