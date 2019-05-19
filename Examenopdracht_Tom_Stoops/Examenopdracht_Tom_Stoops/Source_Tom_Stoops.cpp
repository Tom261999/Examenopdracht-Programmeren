/*
	Inleiding Programmeren: Examenopdracht
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 19-05-2019
 */

#include "pch.h"
#include "Source_Tom_Stoops.h"


Source::Source(double xval_in, double yval_in, double sterkte_in) : BaseFlow(xval_in, yval_in, sterkte_in) { // gebruik BaseFlow constructor om de BaseFlow members te initialiseren
	std::cout << "<<Source Constructor>>" << std::endl;
};


Source::~Source() {
	std::cout << "<<Source Desctructor>>" << std::endl;
}


// get-functies, vergelijkingen gegeven in opdracht
double Source::getStreamVal(double x, double y) const {
	double output = sterkte / (2 * M_PI) * atan((y - yval) / (x - xval));
	return output;
};

double Source::getPotentialVal(double x, double y) const {
	double output = sterkte / (2 * M_PI) * log((x - xval) * (x - xval) + (y - yval) * (y - yval));
	return output;
};

std::vector<double> Source::getVelocityVec(double x, double y) const {
	std::vector<double> v;
	v.resize(2, 0); // maakt vector 'v' 2 plaatsen lang en zet deze waarden op 0.

	v.at(0) = sterkte * (x - xval) / (2 * M_PI*((x - xval) * (x - xval) + (y - yval) * (y - yval)));
	v.at(1) = sterkte * (y - yval) / (2 * M_PI*((x - xval) * (x - xval) + (y - yval) * (y - yval)));

	return v;
};