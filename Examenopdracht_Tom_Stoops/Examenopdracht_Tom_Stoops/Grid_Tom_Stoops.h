#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BaseFlow_Tom_Stoops.h"

class Grid {
public:
	// Constructor & Destructor
	Grid(double xmin, double xmax, double ymin, double ymax, int xstep, int ystep);
	~Grid();

	void addBaseflow(BaseFlow* bfPtr);
	void writeOutput(std::string filename, std::string type); // type = "velocity","potential", ...


private:
	// Input check functies
	double checkStep(double step);

	// Gridparameters
	int xstep; // geeft de resolutie van het grid
	int ystep;
	double xmin; // geeft de minimale en maximale waarden voor x en y richtingen
	double xmax;
	double ymin;
	double ymax;

	// Grid
	std::vector<BaseFlow*> fundSoln; // bevat de fundamentele oplossingen
};