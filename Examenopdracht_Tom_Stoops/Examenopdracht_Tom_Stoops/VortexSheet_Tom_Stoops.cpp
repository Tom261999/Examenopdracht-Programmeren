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
VortexSheet::VortexSheet(double xval_in, double yval_in, double sterkte_in, int N_in) : BaseFlow(xval_in, yval_in, sterkte_in, N_in) {
	type = "numeriek";

	// Check N
	if (N < 0) {
		std::cerr << "<Warning>: N kan niet negatief zijn, we werken verder met absolute waarde van input." << std::endl;
		N = abs(N_in);
	}
	else if (N == 0) {
		std::cerr << "<Error>: N kan niet 0 zijn!" << std::endl;
		exit(1);
	}
	else {
		N = N_in;
	}

	asteps
}



VortexSheet::~VortexSheet() {
	std::cout << "<<VortexSheet Deconstructor>>" << std::endl;
};


// Essentiële functies
double VortexSheet::getStreamVal(double x, double y) {
	double output = 0;
	return output;
};

double VortexSheet::getPotentialVal(double x, double y) {
	double output = 0;
	return output;
};

std::vector<double> VortexSheet::getVelocityVec(double x, double y) {
	std::vector<double> v;
	v.resize(2, 0);

	v.at(0) = 0;
	v.at(1) = 0;

	return v;
};