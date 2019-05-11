#include "pch.h"
#include "BaseFlow_Tom_Stoops.h"


BaseFlow::BaseFlow(double xval_in, double yval_in, double sterkte_in) {
	std::cout << "<<BaseFlow Constructor>>" << std::endl;
	xval = xval_in;
	yval = yval_in;
	sterkte = sterkte_in;
};

BaseFlow::BaseFlow(double alpha_in, double sterkte_in) {
	std::cout << "<<BaseFlow Constructor (Uniform)>>" << std::endl;
	alpha = alpha_in;
	sterkte = sterkte_in;
};

BaseFlow::BaseFlow(double xval_in, double yval_in, double sterkte_in, int N) {
	std::cout << "<<BaseFlow Constructor (VortexSheet Numeriek)>>" << std::endl;
};

BaseFlow::~BaseFlow() {
	std::cout << "<<BaseFlow Destructor>>" << std::endl;
};
