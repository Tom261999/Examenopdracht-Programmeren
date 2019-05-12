#include "pch.h"
#include "BaseFlow_Tom_Stoops.h"


BaseFlow::BaseFlow(double xval_in, double yval_in, double sterkte_in) {
	std::cout << "<<BaseFlow Constructor (standaard)>>" << std::endl;
	xval = xval_in;
	yval = yval_in;
	sterkte = sterkte_in;
};

BaseFlow::BaseFlow(double sterkte_in) {
	std::cout << "<<BaseFlow Constructor (minimaal)>>" << std::endl;
	sterkte = sterkte_in;
};

BaseFlow::~BaseFlow() {
	std::cout << "<<BaseFlow Destructor>>" << std::endl;
};
