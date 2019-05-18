#pragma once
#include "BaseFlow_Tom_Stoops.h"

class VortexSheet :	public BaseFlow {
public:
	VortexSheet(double xval_1_in, double xval_2_in, double yval_in, double sterkte_in, int N_in); // Numeriek: plaatst een vortex op (xval,yval) en (xval2,yval) en bepaalt met behulp van het aantal vortices N de afstand a tussen de vortices 
	VortexSheet(double sterkte_in, double a_in); // Analytisch: neemt enkel de sterkte en afstand tussen de vortices als input; exacte locatie van vortices onbelangrijk daar het systeem translatieinvariant is langs de x-as
	~VortexSheet();

	// get-functies, numeriek: som van vector vergelijkingen gegeven in de opdracht; analytisch: vergelijkingen gegeven in de opdracht.
	double getStreamVal(double x, double y) const;
	double getPotentialVal(double x, double y) const;
	std::vector<double> getVelocityVec(double x, double y) const;

private: // extra members voor deze klasse, geen const daar niet alle members geinitialiseerd worden voor de numerieke of analytische gevallen
	int N; // aantal vortices (enkel numeriek)
	double a; // afstand tussen de vortices (ingegeven voor analytisch, berekend door constructor voor numeriek)
	double xval2; // positie van Nde vortex
	const std::string type; // string bevat type "analytisch" of "numeriek", deze zal in de get-functies bepalen op welke manier de gevraagde waarden bepaald worden
	std::vector<double> xloc; // x-waarden van de locaties van de vortices voor numeriek vortexsheet
};

