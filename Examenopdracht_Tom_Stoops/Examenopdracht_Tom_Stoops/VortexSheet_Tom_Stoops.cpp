#include "pch.h"
#include "VortexSheet_Tom_Stoops.h"
/*
/////////////////////////////////////////////////////////////////// NOPE CONSTRUCTOR MAKEN VOOR ANALYTISCH EN VOOR NUMERIEK -> DUBBELE OVERLOAD
VortexSheet::VortexSheet(double yval_in, int N_in, std::string type_in) : BaseFlow::BaseFlow(yval_in, N_in) {
	std::cout << "<<VortexSheet Constructor>>" << std::endl;

	// Check N waarde
	if (N_in == 0) {
		std::cerr << "<Error>: Waarde van N kan niet 0 zijn!" << std::endl;
		exit(1);
	}
	else if (N_in < 0) {
		std::cerr << "<Warning>: Waarde van N kan niet negatief zijn, we werken verder met de absolute waarde." << std::endl;
		N = abs(N_in);
	}
	else {
		N = N_in;
	}

	// Splits analytisch/numeriek
	if (type_in == "Analytisch" || type_in == "analytisch" || type_in == "A" || type_in == "a") {
		std::cout << "Analytische oplossing" << std::endl;
		type = type_in;
	}
	else if (type_in == "Numeriek" || type_in == "numeriek" || type_in == "N" || type_in == "n") {
		std::cout << "Numerieke oplossing" << std::endl;
		type = type_in;
	}
	else {
		std::cerr << "<Error>: Ongeldig type ingegeven!" << std::endl;
		exit(1);
	}
};
*/

// Numerieke constructor
VortexSheet::VortexSheet(double xval_1_in, double xval_2_in, double yval_in, double sterkte_in, int N_in) : BaseFlow(xval_1_in, xval_2_in, yval_in, sterkte_in, N_in) {
	type = "numeriek";

	// Check N
	if (N < 0) {
		std::cerr << "<Warning>: N kan niet negatief zijn, we werken verder met absolute waarde van input." << std::endl;
		N = abs(N_in);
	}
	else if (N == 1) {
		std::cerr << "<Error>: N moet ten minste 2 zijn, voor een enkele vortex gebruik klasse Vortex!" << std::endl;
		exit(1);
	}
	else if (N == 0) {
		std::cerr << "<Error>: N kan niet 0 zijn!" << std::endl;
		exit(1);
	}
	else {
		N = N_in;
	}

	a = (xval2 - xval) / (N-1);
	xloc.resize(N, 0);
	for (int i = 0; i < N; i++) {
		xloc.at(i) = xval + (i * a);
	}
};

VortexSheet::VortexSheet(double sterkte_in, double a_in) : BaseFlow(sterkte_in) {
	std::cout << "<<VortexSheet Constructor (Analytisch)>>" << std::endl;
	type = "analytisch";
	a = a_in; // nog een check voor a!
}; 

VortexSheet::~VortexSheet() {
	std::cout << "<<VortexSheet Deconstructor>>" << std::endl;
};


// Essentiële functies

double VortexSheet::getStreamVal(double x, double y) {
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
		std::cerr << "<Error>: Onverwacht type" << std::endl;
		exit(1);
	}
	return output;
}

double VortexSheet::getPotentialVal(double x, double y) {
	double output = 0;
	if (type == "numeriek") {
		for (int i = 0; i < N; i++) {
			output += -sterkte / (2 * M_PI) * atan((y - yval) / (x - xloc.at(i)));
		}
	}
	else if (type == "analytisch") {
		output = 0; // geen uitdrukking gegeven!
	}
	else {
		std::cerr << "<Error>: Onverwacht type" << std::endl;
		exit(1);
	}
	return output;
};

std::vector<double> VortexSheet::getVelocityVec(double x, double y) {
	std::vector<double> v;
	v.resize(2, 0);

	if (type == "numeriek") {
		for (int i = 0; i < N; i++) {
			v.at(0) += sterkte / (2 * M_PI) * (y - yval) / ((x - xloc.at(i))*(x - xloc.at(i)) + (y - yval)*(y - yval));
			v.at(1) += -sterkte / (2 * M_PI) * (x - xloc.at(i)) / ((x - xloc.at(i))*(x - xloc.at(i)) + (y - yval)*(y - yval));
		}
	}
	else if (type == "analytisch") {
		v.at(0) = sterkte / (2 * a) * sinh((2 * M_PI*y) / a) / (cosh((2 * M_PI*y) / a) - cos((2 * M_PI*x) / a));
		v.at(1) = -sterkte / (2 * a) * sin((2 * M_PI*x) / a) / (cosh((2 * M_PI*y) / a) - cos((2 * M_PI*x) / a));
	}
	else {
		std::cerr << "<Error>: Onverwacht type" << std::endl;
		exit(1);
	}

	return v;
};