/*
	Inleiding Programmeren: Examenopdracht
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 19-05-2019
 */

#pragma once
#include "BaseFlow_Tom_Stoops.h"
class Doublet :	public BaseFlow {
public:
	Doublet(double xval_in, double yval_in, double sterkte_in);
	~Doublet();

	// get-functies
	double getStreamVal(double x, double y) const;
	double getPotentialVal(double x, double y) const;
	std::vector<double> getVelocityVec(double x, double y) const;
};

