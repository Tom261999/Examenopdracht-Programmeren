#pragma once
#include "BaseFlow_Tom_Stoops.h"

class Source : public BaseFlow {
public:
	Source(double xval_in, double yval_in, double sterkte_in);
	~Source();

	// Essenitële functies
	double getStreamVal(double xval, double yval);
	double getPotentialVal(double xval, double yval);
	std::vector<double> getVelocityVec(double xval, double yval);
};

