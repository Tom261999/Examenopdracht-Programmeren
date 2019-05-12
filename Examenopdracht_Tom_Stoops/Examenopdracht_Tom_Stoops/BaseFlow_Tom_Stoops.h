#pragma once
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES // Nodig om M_PI te gebruiken in de afgeleide klassen (is minder werk als ik het gewoon hier include)
#include <math.h>

class BaseFlow {
public:
	// Constructor & Destructor
	BaseFlow(double xval_in, double yval_in, double sterkte_in); // x-, y-waarden, en de sterkte (Q, \Gamma, ...)
	BaseFlow(double sterkte_in); // Uniform & analytische vortexsheet
	BaseFlow(double xval_1_in, double xval_2_in, double yval_in, double sterkte_in, int N_in); // VortexSheet numeriek -> neemt de x waarden van de uiterste twee vortices (op lijn y = yval_in)
	~BaseFlow();

	// Essentiële functies (pure virtual)
	virtual double getStreamVal(double xval, double yval) = 0; // = 0 zoadat pure virtual en deze klasse abstract class zijn, geen implementatie nodig in de source file
	virtual double getPotentialVal(double xval, double yval) = 0;
	virtual std::vector<double> getVelocityVec(double xval, double yval) = 0;

protected:
	double xval;
	double yval;
	double sterkte; // Q, \Gamma, U_\infty, ...
	double alpha; // hoek met x-as voor uniform flow
	double xval2; // additionele xwaarde voor VortexSheet
	int N;

};
