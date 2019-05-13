#include "pch.h"
#include "Grid_Tom_Stoops.h"
#include <fstream>
#include <iomanip>


// Constructor & Destructor

Grid::Grid(double xmin_in, double xmax_in, double ymin_in, double ymax_in, int xstep_in, int ystep_in) {
	std::cout << "<<Grid Constructor>>" << std::endl;

	// Input checks
	xstep = checkStep(xstep_in);
	ystep = checkStep(ystep_in);

	if (xmin_in < xmax_in) {
		xmin = xmin_in;
		xmax = xmax_in;
	}
	else {
		std::cerr << "<Error>: Ongeldige x-range ingegeven." << std::endl;
		exit(1);
	};

	if (ymin_in < ymax_in) {
		ymin = ymin_in;
		ymax = ymax_in;
	}
	else {
		std::cerr << "<Error>: Ongeldige y-range ingegeven." << std::endl;
		exit(1);
	};

	// Toon gridparameters op console
	std::cout << "Grid aangemaakt met volgende parameters: \n\tx-range: " << xmin << " tot " << xmax << "\n\ty-range: " << ymin << " tot " << ymax << "\n\tx-stappen: " << xstep << "\n\ty-stappen: " << ystep << std::endl;

	// Maak de assen
	for (int i = 0; i < xstep; i++)	{
		xaxis.push_back(xmin + i * (xmax - xmin) / xstep);
	};

	for (int i = 0; i < ystep; i++) {
		yaxis.push_back(ymin + i * (ymax - ymin) / ystep);
	};
};

Grid::~Grid() {
	std::cout << "<<Grid Destructor>>" << std::endl;
};


// Input check functie

int Grid::checkStep(int step) {
	if (step == 0)
	{
		std::cerr << "<Error>: Gridstap kan niet 0 zijn." << std::endl;
		exit(1);
	}
	else if (step < 0) {
		std::cerr << "<Warning>: Gridstap kan niet negatief zijn, we gebruiken de absolute waarde van de input." << std::endl;
		return abs(step);
	}
	else {
		return step;
	}
};


// Essentiële functies

void Grid::addBaseFlow(BaseFlow* bfPtr) { // bfPtr is een pointer naar een fundamentele oplossing van ons systeem
	fundSoln.push_back(bfPtr);
};

void Grid::clearBaseFlow() { // maakt de vector met fundamentele oplossingen leeg
	fundSoln.clear();
};

void Grid::writeStream(std::string filename) const {
	filename += ".txt";
	filename = "Output\\" + filename; // zorgt voor een handiger output pad -> zo komen ze niet allemaal naast de header- en source-files!!
	std::ofstream File(filename, std::ios::out);

	if (!File) {
		std::cerr << "<Error>: Outputfile niet gevonden." << std::endl;
		exit(1);
	}
	else {
		for (int j = 0; j < ystep; j++) {
			for (int i = 0; i < xstep; i++) {

				double value = 0;

				for (int k = 0; k < fundSoln.size(); k++) {
					double x = xaxis.at(i);
					double y = yaxis.at(j);
					BaseFlow* soln = fundSoln.at(k);

					value += soln->getStreamVal(x, y);
				}

				if (isnan(value)) {
					File << "NaN\t";
				}
				else {
					File << std::fixed << std::setprecision(4) << value << "\t";
				}
			}

			File << "\n";
		}
	}
};

void Grid::writePotential(std::string filename) const {
	filename += ".txt";
	filename = "Output\\" + filename;
	std::ofstream File(filename, std::ios::out);

	if (!File) {
		std::cerr << "<Error>: Outputfile niet gevonden." << std::endl;
		exit(1);
	}
	else {
		for (int j = 0; j < ystep; j++) {
			for (int i = 0; i < xstep; i++) {

				double value = 0;

				for (int k = 0; k < fundSoln.size(); k++) {
					double x = xaxis.at(i);
					double y = yaxis.at(j);
					BaseFlow* soln = fundSoln.at(k);

					value += soln->getPotentialVal(x, y);
				}

				if (isnan(value)) {
					File << "NaN\t";
				}
				else {
					File << std::fixed << std::setprecision(4) << value << "\t";
				}
			}

			File << "\n";
		}
	}
};

void Grid::writeVelocity(std::string filename) const {
	// Voor x component
	std::string xname = filename + "_x.txt";
	xname = "Output\\" + xname;
	std::ofstream xFile(xname, std::ios::out);

	if (!xFile) {
		std::cerr << "<Error>: Outputfile niet gevonden." << std::endl;
		exit(1);
	}
	else {
		for (int j = 0; j < ystep; j++) {
			for (int i = 0; i < xstep; i++) {

				double value = 0;

				for (int k = 0; k < fundSoln.size(); k++) {
					double x = xaxis.at(i);
					double y = yaxis.at(j);
					BaseFlow* soln = fundSoln.at(k);

					value += soln->getVelocityVec(x, y).at(0);
				}

				if (isnan(value)) {
					xFile << "NaN\t";
				}
				else {
					xFile << std::fixed << std::setprecision(4) << value << "\t";
				}
			}

			xFile << "\n";
		}
	}

	// Voor y component
	std::string yname = filename + "_y.txt";
	yname = "Output\\" + yname;
	std::ofstream yFile(yname, std::ios::out);

	if (!yFile) {
		std::cerr << "<Error>: Outputfile niet gevonden." << std::endl;
		exit(1);
	}
	else {
		for (int j = 0; j < ystep; j++) {
			for (int i = 0; i < xstep; i++) {

				double value = 0;

				for (int k = 0; k < fundSoln.size(); k++) {
					double x = xaxis.at(i);
					double y = yaxis.at(j);
					BaseFlow* soln = fundSoln.at(k);

					value += soln->getVelocityVec(x, y).at(1);
				}

				if (isnan(value)) {
					yFile << "NaN\t";
				}
				else {
					yFile << std::fixed << std::setprecision(4) << value << "\t";
				}
			}

			yFile << "\n";
		}
	}
};
