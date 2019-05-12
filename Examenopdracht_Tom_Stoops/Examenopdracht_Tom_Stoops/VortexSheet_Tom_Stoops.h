#pragma once
#include "BaseFlow_Tom_Stoops.h"

class VortexSheet :	public BaseFlow {
public:
	VortexSheet(double xval_1_in, double xval_2_in, double yval_in, double sterkte_in, int N_in); // Numeriek
	VortexSheet(double sterkte_in, double a_in); // Analytisch
	~VortexSheet();

	// Essentiële functies
	double getStreamVal(double xval, double yval) const;
	double getPotentialVal(double xval, double yval) const;
	std::vector<double> getVelocityVec(double xval, double yval) const;

private:
	int N;
	double a;
	double xval2;
	const std::string type;
	std::vector<double> xloc; // x-waarden van de locaties van de vortices
};

