#pragma once
#include "BaseFlow_Tom_Stoops.h"
class Uniform :	public BaseFlow {
public:
	Uniform(double alpha_in, double sterkte_in);
	~Uniform();

	// Essenitële functies
	double getStreamVal(double xval, double yval);
	double getPotentialVal(double xval, double yval);
	std::vector<double> getVelocityVec(double xval, double yval);

private:
	double alpha;
};

