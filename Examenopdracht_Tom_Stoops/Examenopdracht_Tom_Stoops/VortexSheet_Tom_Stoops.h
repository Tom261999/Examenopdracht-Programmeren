#pragma once
#include "BaseFlow_Tom_Stoops.h"

class VortexSheet :	public BaseFlow {
public:
	VortexSheet(double xval_in, double yval_in, double sterkte_in, int N_in); // Numeriek
	VortexSheet(double xval_in, double yval_in, double sterkte_in, double a_in); // Analytisch
	~VortexSheet();

	// Essentiële functies
	double getStreamVal(double xval, double yval);
	double getPotentialVal(double xval, double yval);
	std::vector<double> getVelocityVec(double xval, double yval);

private:
	int N;
	double a;
	std::string type;
};

