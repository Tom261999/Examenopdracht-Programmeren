#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BaseFlow_Tom_Stoops.h"
#include "Uniform_Tom_Stoops.h"

class Grid {
public:
	// Constructor & Destructor
	Grid(double xmin, double xmax, double ymin, double ymax, int xstep, int ystep);
	~Grid();

	void addBaseFlow(BaseFlow* bfPtr);
	void clearBaseFlow();

	// Naar bestand wegschrijven
	void writeStream(std::string filename) const;
	void writePotential(std::string filename) const;
	void writeVelocity(std::string filename) const;
	void writeCp(std::string filename, Uniform* UniPtr) const;
	
	//TIJDELIJK
	void testOutput();
	

private:
	// Input check functies
	int checkStep(int step);

	// Gridparameters
	int xstep; // geeft de resolutie van het grid
	int ystep;
	double xmin; // geeft de minimale en maximale waarden voor x en y richtingen
	double xmax;
	double ymin;
	double ymax;

	std::vector<double> xaxis;
	std::vector<double> yaxis;

protected: // protected omdat ik deze nog wil accessen in DrukCoeff
	std::vector<BaseFlow*> fundSoln; // bevat de fundamentele oplossingen
};