#pragma once
#include <iostream>
#include <vector>
#include "BaseFlow_Tom_Stoops.h"

class Grid {
public:
	// Constructor & Destructor
	Grid(double xmin, double xmax, double ymin, double ymax, int xstep, int ystep);
	~Grid();

	void addBaseflow(BaseFlow*);


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
	std::vector<BaseFlow*> grid; // gebruik hier xstep*ystep als lengte vd totale vector; positie (x,y) is dan gegeven door de .at(i) met "i = (y-1)*xstep+x"
};