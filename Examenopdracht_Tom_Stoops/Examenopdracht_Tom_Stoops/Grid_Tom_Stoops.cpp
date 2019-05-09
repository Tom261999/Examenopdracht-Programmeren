#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include <fstream>


// Constructor & Destructor

Grid::Grid(double xmin_in, double xmax_in, double ymin_in, double ymax_in, int xstep_in, int ystep_in) {
	std::cout << "<<Grid Constructor>>" << std::endl;

	// Input checks
	xstep = checkStep(xstep_in);
	ystep = checkStep(ystep_in);

	if (xmin_in < xmax_in) {
		xmin = xmin_in;
		xmax = xmax_in;
	}
	else {
		std::cerr << "<Error>: Ongeldige x-range ingegeven." << std::endl;
		exit(1);
	};

	if (ymin_in < ymax_in) {
		ymin = ymin_in;
		ymax = ymax_in;
	}
	else {
		std::cerr << "<Error>: Ongeldige y-range ingegeven." << std::endl;
		exit(1);
	};

	// Toon gridparameters op console
	std::cout << "Grid aangemaakt met volgende parameters: \n\tx-range: " << xmin << " tot " << xmax << "\n\ty-range: " << ymin << " tot " << ymax << "\n\tx-stappen: " << xstep << "\n\ty-stappen: " << ystep << std::endl;

};

Grid::~Grid() {
	std::cout << "<<Grid Destructor>>" << std::endl;
};


// Input check functie

int Grid::checkStep(int step) {
	if (step == 0)
	{
		std::cerr << "<Error>: Gridstap kan niet 0 zijn." << std::endl;
		exit(1);
	}
	else if (step < 0) {
		std::cerr << "<Warning>: Gridstap kan niet negatief zijn, we gebruiken de absolute waarde van de input." << std::endl;
		return abs(step);
	}
	else {
		return step;
	}
};


// Essentiële functies

void Grid::addBaseflow(BaseFlow* bfPtr) { // bfPtr is een pointer naar een fundamentele oplossing van ons systeem
	fundSoln.push_back(bfPtr);
};

void Grid::writeStream(std::string filename) {

};

void Grid::writePotential(std::string filename) {

};

void Grid::writeVelocity(std::string filename) {

};
