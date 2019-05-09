#include "pch.h"
#include "Source_Tom_Stoops.h"


Source::Source(double xval_in, double yval_in, double sterkte_in) : BaseFlow(xval_in, yval_in, sterkte_in) {
	std::cout << "<<Source Constructor>>" << std::endl;
};


Source::~Source() {
	std::cout << "<<Source Desctructor>>" << std::endl;
}


// Essentiële functies
double BaseFlow::getStreamVal(double xval, double yval) {
	return sterkte / (2 * M_PI)*atan(yval / xval);
};

double BaseFlow::getPotentialVal(double xval, double yval) {
	return -sterkte / (2 * M_PI)*log(xval*xval + yval * yval);
};

std::vector<double> BaseFlow::getVelocityVec(double xval, double yval) {
	std::vector<double> v;
	v.at(1) = sterkte / (2 * M_PI*(xval*xval + yval * yval))*xval;
	v.at(2) = sterkte / (2 * M_PI*(xval*xval + yval * yval))*yval;

	return v;
};