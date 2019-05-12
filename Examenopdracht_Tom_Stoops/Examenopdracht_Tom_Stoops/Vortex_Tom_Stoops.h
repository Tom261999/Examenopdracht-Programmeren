#pragma once
#include "BaseFlow_Tom_Stoops.h"
class Vortex :	public BaseFlow {
public:
	Vortex(double xval_in, double yval_in, double sterkte_in);
	~Vortex();

	// Essentiële functies
	double getStreamVal(double xval, double yval) const;
	double getPotentialVal(double xval, double yval) const;
	std::vector<double> getVelocityVec(double xval, double yval) const;
};

