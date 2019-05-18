#pragma once
#include "BaseFlow_Tom_Stoops.h"

class Source : public BaseFlow {
public:
	Source(double xval_in, double yval_in, double sterkte_in);
	~Source();

	// get-functies, const omdat ze geen waarden aanpassen
	double getStreamVal(double x, double y) const;
	double getPotentialVal(double x, double y) const;
	std::vector<double> getVelocityVec(double x, double y) const;
};

