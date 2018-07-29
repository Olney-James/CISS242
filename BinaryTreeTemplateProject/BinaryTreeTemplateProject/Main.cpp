/*************************************
Program: Main.cpp (Week 7 Programming Assignment 2)

Author: James Olney
Created: 04/15/2017
Revisions: N/A

This is Main.cpp. The program creates an instance of the binary tree class
with a data type of EmployeeInfo (BinaryTree<EmployeeInfo>). The binary tree 
will be sorted by the Employee ID number found in the EmployeeInfo class. The
program allows the user to search for Employee by the Employee ID. If the 
employee is found in the tree, its name and ID should be displayed. If not, a 
message should be displayed indicating that it was not found. 

**************************************/

#include "BinaryTree.h"
#include "EmployeeInfo.h"
#include <iostream>
using namespace std;

void displayTree(BinaryTree<EmployeeInfo> *t);

int main() {
	int exit = 1;

	BinaryTree<EmployeeInfo> EmployeeBinaryTree;
	EmployeeInfo john(1021, "John Williams");
	EmployeeInfo bill(1057, "Bill Witherspoon");
	EmployeeInfo jennifer(2487, "Jennifer Twain");
	EmployeeInfo sophia(3769, "Sophia Lancaster");
	EmployeeInfo debbie(1017, "Debbie Reece");
	EmployeeInfo george(1275, "George McMullen");
	EmployeeInfo ashley(1899, "Ashley Smith");
	EmployeeInfo josh(4218, "Josh Plemmons");
	EmployeeBinaryTree.insertNode(john);
	EmployeeBinaryTree.insertNode(bill);
	EmployeeBinaryTree.insertNode(jennifer);
	EmployeeBinaryTree.insertNode(sophia);
	EmployeeBinaryTree.insertNode(debbie);
	EmployeeBinaryTree.insertNode(george);
	EmployeeBinaryTree.insertNode(ashley);
	EmployeeBinaryTree.insertNode(josh);
	displayTree(&EmployeeBinaryTree);
	
	EmployeeInfo bogus;
	while (exit != 0) {
		cout << "enter empID to search or 0 to exit: ";
		cin >> exit;
		bogus.setEmpID(exit);
		if (exit != 0) {
			EmployeeBinaryTree.searchFor(bogus);
		}
	}
	
	
	if (exit != 0) {
		cout << endl << "enter 0 to exit...";
		cin >> exit;
	}
}

void displayTree(BinaryTree<EmployeeInfo> *t) {
	cout << "display in order: ";
	t->displayTreeInOrder(t->getRoot());
	cout << endl << "display pre order: ";
	t->displayTreePreOrder(t->getRoot());
	cout << endl << "display post order: ";
	t->displayTreePostOrder(t->getRoot());
	cout << endl;

	cout << "Number Of Nodes: " << t->numberOfNodes() << endl;
	cout << "Number Of Leaf Nodes: " << t->numberOfLeafNodes() << endl;
	cout << "Tree Height: " << t->getTreeHeight();
	cout << endl << endl;
}