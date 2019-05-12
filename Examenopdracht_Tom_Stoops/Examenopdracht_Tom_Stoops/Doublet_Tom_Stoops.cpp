#include "pch.h"
#include "Doublet_Tom_Stoops.h"


Doublet::Doublet(double xval_in, double yval_in, double sterkte_in) : BaseFlow(xval_in, yval_in, sterkte_in) {
	std::cout << "<<Doublet Constructor>>" << std::endl;
};


Doublet::~Doublet() {
	std::cout << "<<Doublet Desconstructor>>" << std::endl;
};

// Essentiële functies
double Doublet::getStreamVal(double x, double y) const {
	double output = -sterkte / (2 * M_PI) * (y - yval) / ((x - xval)*(x - xval) + (y - yval)*(y - yval));
	return output;
};

double Doublet::getPotentialVal(double x, double y) const {
	double output = -sterkte / (2 * M_PI) * (x - xval) / ((x - xval)*(x - xval) + (y - yval)*(y - yval));
	return output;
};

std::vector<double> Doublet::getVelocityVec(double x, double y) const {
	std::vector<double> v;
	v.resize(2, 0);

	v.at(0) = -sterkte / (2 * M_PI) * ((x - xval)*(x - xval) - (y - yval)*(y - yval)) / (((x - xval)*(x - xval) + (y - yval)*(y - yval))*((x - xval)*(x - xval) + (y - yval)*(y - yval)));
	v.at(1) = -sterkte / (2 * M_PI) * (x - xval)*(y - yval) / (((x - xval)*(x - xval) + (y - yval)*(y - yval))*((x - xval)*(x - xval) + (y - yval)*(y - yval)));

	return v;
};