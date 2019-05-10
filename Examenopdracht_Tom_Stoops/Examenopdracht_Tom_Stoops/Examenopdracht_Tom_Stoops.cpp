#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include "BaseFlow_Tom_Stoops.h"
#include "Source_Tom_Stoops.h"
#include <iostream>

int main()
{

	std::cout << "Hello world!" << std::endl;

	Grid mytestgrid(0, 1, 2, 3, 100, 150);

	Source mysourcetest(0.5, 2.5, 5);
	Source* myPtr = &mysourcetest;
	mytestgrid.addBaseFlow(myPtr);

	mytestgrid.writeStream("stroomtest");
};
