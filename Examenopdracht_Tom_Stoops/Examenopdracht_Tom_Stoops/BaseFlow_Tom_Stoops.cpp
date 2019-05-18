#include "pch.h"
#include "BaseFlow_Tom_Stoops.h"


BaseFlow::BaseFlow(double xval_in, double yval_in, double sterkte_in) : xval(xval_in), yval(yval_in), sterkte(sterkte_in) { // initialiseert de protected members van BaseFlow
	std::cout << "<<BaseFlow Constructor (Standaard)>>" << std::endl;
};

BaseFlow::BaseFlow(double sterkte_in) : sterkte(sterkte_in), xval(nan(0)), yval(nan(0)) { // minimale constructor initialiseert alleen de sterkte, de andere waarden worden op NaN gezet (deze moeten geinitialiseerd worden want de members zijn const!)
	std::cout << "<<BaseFlow Constructor (Minimaal)>>" << std::endl;
};

BaseFlow::~BaseFlow() {
	std::cout << "<<BaseFlow Destructor>>" << std::endl;
};
