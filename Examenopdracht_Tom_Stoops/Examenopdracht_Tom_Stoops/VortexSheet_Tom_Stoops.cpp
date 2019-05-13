#include "pch.h"
#include "VortexSheet_Tom_Stoops.h"


// Numerieke constructor
VortexSheet::VortexSheet(double xval_1_in, double xval_2_in, double yval_in, double sterkte_in, int N_in) : BaseFlow(xval_1_in, yval_in, sterkte_in), type("numeriek") {
	std::cout << "<<VortexSheet Constructor (Numeriek)>>" << std::endl;

	// Check N
	if (N_in < 0) {
		std::cerr << "<Warning>: N kan niet negatief zijn, we werken verder met absolute waarde van input." << std::endl;
		N = abs(N_in);
	}
	else if (N_in == 1) {
		std::cerr << "<Error>: N moet ten minste 2 zijn, voor een enkele vortex gebruik klasse Vortex!" << std::endl;
		exit(1);
	}
	else if (N_in == 0) {
		std::cerr << "<Error>: N kan niet 0 zijn!" << std::endl;
		exit(1);
	}
	else {
		N = N_in;
	}

	if (xval2 == xval) {
		std::cerr << "<Error>: Ongeldige x-waarde voor de laatste vortex ingegeven!" << std::endl;
		exit(1);
	}
	else {
		xval2 = xval_2_in;
	}

	a = (xval2 - xval) / (N-1);
	xloc.resize(N, 0);

	for (int i = 0; i < N; i++) {
		xloc.at(i) = xval + (i * a);
	}
};

VortexSheet::VortexSheet(double sterkte_in, double a_in) : BaseFlow(sterkte_in), type("analytisch") {
	std::cout << "<<VortexSheet Constructor (Analytisch)>>" << std::endl;

	if (a_in < 0) {
		std::cerr << "<Warning>: a moet positief zijn, wer werken verder met de absolute waarde." << std::endl;
		a = abs(a_in);
	}
	else if (a_in == 0) {
		std::cerr << "<Error>: a kan niet 0 zijn!" << std::endl;
		exit(1);
	}
	else {
		a = a_in;
	}
}; 

VortexSheet::~VortexSheet() {
	std::cout << "<<VortexSheet Deconstructor>>" << std::endl;
};


// Essentiële functies

double VortexSheet::getStreamVal(double x, double y) const {
	double output = 0;
	if (type == "numeriek") {		
		for (int i = 0; i < N; i++) {
			output += sterkte / (4 * M_PI) * log((x - xloc.at(i)) * (x - xloc.at(i)) + (y - yval) * (y - yval));
		}
	}
	else if (type == "analytisch") {
		output = sterkte / (4 * M_PI) * log(cosh((2 * M_PI*y / a)) - cos(2 * M_PI*x / a));
	}
	else {
		std::cerr << "<Error>: Onverwacht type!" << std::endl;
		exit(1);
	}
	return output;
}

double VortexSheet::getPotentialVal(double x, double y) const {
	double output = 0;
	if (type == "numeriek") {
		for (int i = 0; i < N; i++) {
			output += -sterkte / (2 * M_PI) * atan((y - yval) / (x - xloc.at(i)));
		}
	}
	else if (type == "analytisch") {
		output = nan(0); // Uitdrukking niet gegeven, geeft NaN terug.
	}
	else {
		std::cerr << "<Error>: Onverwacht type!" << std::endl;
		exit(1);
	}
	return output;
};

std::vector<double> VortexSheet::getVelocityVec(double x, double y) const {
	std::vector<double> v;
	v.resize(2, 0);

	if (type == "numeriek") {
		for (int i = 0; i < N; i++) {
			v.at(0) += sterkte / (2 * M_PI) * (y - yval) / ((x - xloc.at(i))*(x - xloc.at(i)) + (y - yval)*(y - yval));
			v.at(1) += -sterkte / (2 * M_PI) * (x - xloc.at(i)) / ((x - xloc.at(i))*(x - xloc.at(i)) + (y - yval)*(y - yval));
		}
	}
	else if (type == "analytisch") {
		v.at(0) = sterkte / (2 * a) * sinh((2 * M_PI * y) / a) / (cosh((2 * M_PI * y) / a) - cos((2 * M_PI * x) / a));
		v.at(1) = -sterkte / (2 * a) * sin((2 * M_PI * x) / a) / (cosh((2 * M_PI * y) / a) - cos((2 * M_PI * x) / a));
	}
	else {
		std::cerr << "<Error>: Onverwacht type!" << std::endl;
		exit(1);
	}

	return v;
};