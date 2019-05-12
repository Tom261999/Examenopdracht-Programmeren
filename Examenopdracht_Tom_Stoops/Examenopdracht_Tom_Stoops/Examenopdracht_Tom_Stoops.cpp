#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include "BaseFlow_Tom_Stoops.h"
#include "Source_Tom_Stoops.h"
#include "Uniform_Tom_Stoops.h"
#include "Vortex_Tom_Stoops.h"
#include "Doublet_Tom_Stoops.h"
#include "VortexSheet_Tom_Stoops.h"

int main()
{
	Grid mytestgrid(-2, 2, -1, 1, 200, 100);

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
	Uniform myuniform(0.5, 1);
	Uniform* uniPtr = &myuniform;
	mytestgrid.addBaseFlow(uniPtr);
	*/

	/*
	Vortex myvortex(0, 0, 5);
	Vortex* vorPtr = &myvortex;
	mytestgrid.addBaseFlow(vorPtr);
	*/

	/*
	Doublet mydoublet(0, 0, 1);
	Doublet* douPtr = &mydoublet;
	mytestgrid.addBaseFlow(douPtr);
	*/

	/*
	VortexSheet myvs(-1, 1, 0, 1, 4);
	VortexSheet* vsPtr = &myvs;
	mytestgrid.addBaseFlow(vsPtr);
	*/

	
	VortexSheet myvs2(1, 0.5);
	VortexSheet* vsPtr2 = &myvs2;
	mytestgrid.addBaseFlow(vsPtr2);
	

	mytestgrid.writeStream("stream");
	mytestgrid.writePotential("pressure");
	mytestgrid.writeVelocity("vectors");
};
