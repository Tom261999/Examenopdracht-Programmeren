#include "pch.h"
#include "VortexSheet_Tom_Stoops.h"


VortexSheet::VortexSheet(double xval_in, double yval_in, double sterkte_in) : BaseFlow(xval_in, yval_in, sterkte_in) {
	std::cout << "<<VortexSheet Constructor>>" << std::endl;
};


VortexSheet::~VortexSheet() {
	std::cout << "<<VortexSheet Deconstructor>>" << std::endl;
};
