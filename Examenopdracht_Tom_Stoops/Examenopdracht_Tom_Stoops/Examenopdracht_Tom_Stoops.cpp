#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include "BaseFlow_Tom_Stoops.h"
#include "Source_Tom_Stoops.h"
#include "Uniform_Tom_Stoops.h"
#include "Vortex_Tom_Stoops.h"

int main()
{
	Grid mytestgrid(-2, 2, -2, 2, 100, 100);

	/*
	Source mysourcetest(1, 0, 1);
	Source* myPtrsource = &mysourcetest;
	mytestgrid.addBaseFlow(myPtrsource);
	*/

	/*
	Source mysource2(-1, 0, -1);
	Source* SinkPtr = &mysource2;
	mytestgrid.addBaseFlow(SinkPtr);
	*/

	/*
	Uniform myuniform(3.14 / 4, 1);
	Uniform* uniPtr = &myuniform;
	mytestgrid.addBaseFlow(uniPtr);
	*/

	Vortex myvortex(0, 0, 1);
	Vortex* vorPtr = &myvortex;
	mytestgrid.addBaseFlow(vorPtr);


	mytestgrid.writeStream("stream");
	mytestgrid.writePotential("pressure");
	mytestgrid.writeVelocity("vectors");
};
