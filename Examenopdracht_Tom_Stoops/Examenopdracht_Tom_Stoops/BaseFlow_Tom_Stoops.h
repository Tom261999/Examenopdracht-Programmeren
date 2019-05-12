#pragma once
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES // Nodig om M_PI te gebruiken in de afgeleide klassen (is minder werk als ik het gewoon hier definieer)
#include <math.h>

class BaseFlow {
public:
	// Constructor & Destructor
	BaseFlow(double xval_in, double yval_in, double sterkte_in); // x-, y-waarden, en de sterkte (Q, \Gamma, ...)
	BaseFlow(double sterkte_in); // Minimale constructor
	~BaseFlow();

	// Essentiële functies (pure virtual)
	virtual double getStreamVal(double xval, double yval) const = 0; // = 0 zoadat pure virtual en deze klasse abstract class zijn, geen implementatie nodig in de source file
	virtual double getPotentialVal(double xval, double yval) const = 0;
	virtual std::vector<double> getVelocityVec(double xval, double yval) const = 0;

protected:
	double xval; // deze kunnen geen const zijn omdat de minimale constructor deze niet initialiseert!
	double yval;
	const double sterkte; // Q, \Gamma, U_\infty, ...

};
