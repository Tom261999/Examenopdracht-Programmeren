#include "pch.h"
#include "BaseFlow_Tom_Stoops.h"


BaseFlow::BaseFlow(double xval_in, double yval_in, double sterkte_in) {
	std::cout << "<<BaseFlow Constructor>>" << std::endl;
	xval = xval_in;
	yval = yval_in;
	sterkte = sterkte_in;
};

BaseFlow::BaseFlow(double sterkte_in) {
	std::cout << "<<BaseFlow Constructor (Uniform)>>" << std::endl;
	sterkte = sterkte_in;
};

BaseFlow::BaseFlow(double xval_1_in, double xval_2_in, double yval_in, double sterkte_in, int N_in) {
	std::cout << "<<BaseFlow Constructor (VortexSheet Numeriek)>>" << std::endl;
	xval = xval_1_in;
	xval2 = xval_2_in;
	yval = yval_in;
	sterkte = sterkte_in;
	N = N_in;
};

BaseFlow::~BaseFlow() {
	std::cout << "<<BaseFlow Destructor>>" << std::endl;
};
