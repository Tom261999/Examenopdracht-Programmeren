#include "pch.h"
#include "Vortex_Tom_Stoops.h"


Vortex::Vortex(double xval_in, double yval_in, double sterkte_in) : BaseFlow(xval_in, yval_in, sterkte_in) {
	std::cout << "<<Vortex Constructor>>" << std::endl;
};


Vortex::~Vortex() {
	std::cout << "<<Vortex Destructor>>" << std::endl;
};

double Vortex::getStreamVal(double x, double y) const {
	double output = sterkte / (4 * M_PI) * log((x - xval) * (x - xval) + (y - yval) * (y - yval));
	return output;
};

double Vortex::getPotentialVal(double x, double y) const {
	double output = -sterkte / (2 * M_PI) * atan((y - yval) / (x - xval));
	return output;
};

std::vector<double> Vortex::getVelocityVec(double x, double y) const {
	std::vector<double> v;
	v.resize(2, 0);

	v.at(0) = sterkte / (2 * M_PI) * (y - yval) / ((x - xval)*(x - xval) + (y - yval)*(y - yval));
	v.at(1) = -sterkte / (2 * M_PI) * (x - xval) / ((x - xval)*(x - xval) + (y - yval)*(y - yval));

	return v;
};
