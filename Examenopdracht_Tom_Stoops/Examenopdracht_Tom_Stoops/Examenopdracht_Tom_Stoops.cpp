#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include "BaseFlow_Tom_Stoops.h"
#include "Source_Tom_Stoops.h"
#include <iostream>

int main()
{

	std::cout << "Hello world!" << std::endl;

	Grid mytestgrid(-2, 2, -2, 2, 100, 100);

	Source mysourcetest(1, 0, 1);
	Source* myPtrsource = &mysourcetest;
	mytestgrid.addBaseFlow(myPtrsource);
	
	Source mysource2(-1, 0, -1);
	Source* SinkPtr = &mysource2;
	mytestgrid.addBaseFlow(SinkPtr);
	
	mytestgrid.writeStream("stream");
	mytestgrid.writePotential("pressure");
	mytestgrid.writeVelocity("vectors");
};
