/*
	Inleiding Programmeren: Examenopdracht
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 19-05-2019
 */

#pragma once
#include "BaseFlow_Tom_Stoops.h"
class Uniform :	public BaseFlow {
public:
	Uniform(double alpha_in, double sterkte_in);
	~Uniform();

	// get-functies
	double getStreamVal(double x, double y) const;
	double getPotentialVal(double x, double y) const;
	std::vector<double> getVelocityVec(double x, double y) const;

	double getSterkte() const; // Deze is nodig om de drukcoefficient te bepalen, daar de sterkte U_\infty gelijk is aan de snelheid op oneindig V_\infty

private:
	const double alpha; // Uniform heeft een extra parameter nodig: alpha, de hoek dat de stroomzin maakt met de x-as
};