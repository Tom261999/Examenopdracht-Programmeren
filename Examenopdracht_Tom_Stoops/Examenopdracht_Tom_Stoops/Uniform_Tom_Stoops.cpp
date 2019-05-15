#include "pch.h"
#include "Uniform_Tom_Stoops.h"


Uniform::Uniform(double alpha_in, double sterkte_in) : BaseFlow(sterkte_in), alpha(alpha_in) {
	std::cout << "<<Uniform Constructor>>" << std::endl;
};


Uniform::~Uniform() {
	std::cout << "<<Uniform Destructor>>" << std::endl;
};

double Uniform::getStreamVal(double x, double y) const {
	double output = sterkte * (y * cos(alpha) + x * sin(alpha));
	return output;
};

double Uniform::getPotentialVal(double x, double y) const {
	double output = sterkte * (x * cos(alpha) - y * sin(alpha));
	return output;
};

std::vector<double> Uniform::getVelocityVec(double x, double y) const {
	std::vector<double> v;
	v.resize(2, 0);

	v.at(0) = sterkte * cos(alpha);
	v.at(1) = -sterkte * sin(alpha);

	return v;
};

double Uniform::getSterkte() {
	return sterkte;
};