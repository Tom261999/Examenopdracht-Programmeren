#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include "BaseFlow_Tom_Stoops.h"
#include "Source_Tom_Stoops.h"
#include "Uniform_Tom_Stoops.h"
#include "Vortex_Tom_Stoops.h"
#include "Doublet_Tom_Stoops.h"
#include "VortexSheet_Tom_Stoops.h"
#include "Opdrachten_Tom_Stoops.h"

int main()
{
	/*
	Opdracht_1();
	Opdracht_2();
	Opdracht_3();
	Opdracht_4();
	Opdracht_5();
	Opdracht_6();
	*/

	/*Vortex vortex(1, 0, 1);
	Vortex vortex2(-1, 0, -1);
	Uniform uniform(3.14 / 2, -4);
	Grid mygrid(-2, 2, -2, 2, 100, 100);
	mygrid.addBaseFlow(&vortex);
	mygrid.addBaseFlow(&vortex2);
	mygrid.testOutput();*/

	Grid mygrid(-1, 1, -1, 1, 200, 200);
	Doublet doublet(0, 0, 5);
	Vortex vort(0, 0, 5);
	Uniform stroom(0, 5);
	mygrid.addBaseFlow(&doublet);
	mygrid.addBaseFlow(&stroom);
	mygrid.addBaseFlow(&vort);
	mygrid.writeCp("Cptest", &stroom);
	mygrid.testOutput();




	///////////////////////////////////////////////////////////////////////// TEST FUNCTIES

	/*
	Grid mytestgrid(-2, 2, -1, 1, 200, 100);
	*/

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
	Uniform myuniform(0, 1.5);
	Uniform* uniPtr = &myuniform;
	mytestgrid.addBaseFlow(uniPtr);
	*/

	/*
	Vortex myvortex(0, 0, 1);
	Vortex* vorPtr = &myvortex;
	mytestgrid.addBaseFlow(vorPtr);
	*/

	/*
	Doublet* douPtr = &mydoublet;
	mytestgrid.addBaseFlow(douPtr);
	Doublet mydoublet(0, 0, 1);
	*/

	/*
	//Numerieke vortexsheet
	VortexSheet myvs(1, -1, 0, 1, 4);
	VortexSheet* vsPtr = &myvs;
	mytestgrid.addBaseFlow(vsPtr);
	*/

	/*
	//Analytisch
	VortexSheet myvs2(1, 0.25);
	VortexSheet* vsPtr2 = &myvs2;
	mytestgrid.addBaseFlow(vsPtr2);
	*/
	
	/*
	mytestgrid.writeStream("stream");
	mytestgrid.writePotential("pressure");
	mytestgrid.writeVelocity("vectors");
	*/

	return 0;
};
