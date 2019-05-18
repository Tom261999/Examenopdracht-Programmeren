#pragma once
#include "BaseFlow_Tom_Stoops.h"
class Vortex :	public BaseFlow {
public:
	Vortex(double xval_in, double yval_in, double sterkte_in);
	~Vortex();

	// get-functies, vergelijkingen gegeven in de opdracht
	double getStreamVal(double x, double y) const;
	double getPotentialVal(double x, double y) const;
	std::vector<double> getVelocityVec(double x, double y) const;
};

