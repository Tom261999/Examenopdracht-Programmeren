/*
	Inleiding Programmeren: Examenopdracht
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 19-05-2019
 */

#pragma once
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES // Nodig om M_PI te gebruiken in de afgeleide klassen (Als ik dit hier plaats moet ik dit niet in iedere klasse herhalen.)
#include <math.h>

class BaseFlow {
public:
	// Constructor & Destructor
	BaseFlow(double xval_in, double yval_in, double sterkte_in); // x-, y-waarden, en de sterkte (Q, \Gamma, ...)
	BaseFlow(double sterkte_in); // Minimale constructor, gebruikt voor Uniform en analytisch VortexSheet
	~BaseFlow();

	// Essentiële functies (pure virtual)
	virtual double getStreamVal(double xval, double yval) const = 0; // pure virtual functions opdat deze in afgeleide klassen gedefinieerd worden en BaseFlow een abstracte klasse wordt, er is geen implementatie nodig in de source file
	virtual double getPotentialVal(double xval, double yval) const = 0;
	virtual std::vector<double> getVelocityVec(double xval, double yval) const = 0;

protected: // protcted zodat afgeleide klassen hier mee kunnen werken
	const double xval;
	const double yval;
	const double sterkte; // Algemene sterktefactor, in afgeleide klassen komt dit overeen met: Q, \Gamma, U_\infty, ...

};
