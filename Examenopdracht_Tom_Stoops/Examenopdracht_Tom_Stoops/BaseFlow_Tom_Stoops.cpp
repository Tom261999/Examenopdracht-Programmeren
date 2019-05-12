#include "pch.h"
#include "BaseFlow_Tom_Stoops.h"


BaseFlow::BaseFlow(double xval_in, double yval_in, double sterkte_in) : xval(xval_in), yval(yval_in), sterkte(sterkte_in) {
	std::cout << "<<BaseFlow Constructor (Standaard)>>" << std::endl;
};

BaseFlow::BaseFlow(double sterkte_in) : sterkte(sterkte_in) {
	std::cout << "<<BaseFlow Constructor (Minimaal)>>" << std::endl;
};

BaseFlow::~BaseFlow() {
	std::cout << "<<BaseFlow Destructor>>" << std::endl;
};
