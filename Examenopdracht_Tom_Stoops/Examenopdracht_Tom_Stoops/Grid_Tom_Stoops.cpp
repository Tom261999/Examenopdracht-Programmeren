#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include <iostream>


// Constructor & Destructor

Grid::Grid(float xmin_in, float xmax_in, float ymin_in, float ymax_in, int xstep_in, int ystep_in) {
	std::cout << "<<Grid Constructor>>" << std::endl;

	// Input checks
	xstep = checkStep(xstep_in);
	ystep = checkStep(ystep_in);

	if (checkRange(xmin_in, xmax_in) == true) {
		xmin = xmin_in;
		xmax = xmax_in;
	}
	else {
		exit(1);
	};

	if (checkRange(ymin_in, ymax_in) == true) {
		ymin = ymin_in;
		ymax = ymax_in;
	}
	else {
		exit(1);
	}

	// Toon gridparameters op console
	std::cout << "Grid aangemaakt met volgende parameters: \n\tx-range: " << xmin << " tot " << xmax << "\n\ty-range: " << ymin << " tot " << ymax << "\n\tx-stappen: " << xstep << "\n\tystappen: " << ystep << std::endl;
	

};

Grid::~Grid() {
	std::cout << "<<Grid Destructor>>" << std::endl;
};


// Input check functies

float Grid::checkStep(float step) {
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

bool Grid::checkRange(float min, float max) {
	if (min < max) {
		return true;
	}
	else {
		std::cerr << "<Error>: Ongeldige range ingegeven." << std::endl;
		return false;
	}
};