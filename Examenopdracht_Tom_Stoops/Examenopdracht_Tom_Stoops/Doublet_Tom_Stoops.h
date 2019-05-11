#pragma once
#include "BaseFlow_Tom_Stoops.h"
class Doublet :	public BaseFlow {
public:
	Doublet(double xval_in, double yval_in, double sterkte_in);
	~Doublet();

	// Essentiële functies
	double getStreamVal(double xval, double yval);
	double getPotentialVal(double xval, double yval);
	std::vector<double> getVelocityVec(double xval, double yval);
};

