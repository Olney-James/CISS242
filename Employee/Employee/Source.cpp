#include "Employee.h"
#include "stdafx.h"


int main() {
	Employee emp("James", 12, "Software", "Engineer");
	emp.displayEmployee(&emp);
}