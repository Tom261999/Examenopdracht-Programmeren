#include "pch.h"
#include "Opdrachten_Tom_Stoops.h"
#include "Grid_Tom_Stoops.h"
#include "BaseFlow_Tom_Stoops.h"
#include "Source_Tom_Stoops.h"
#include "Uniform_Tom_Stoops.h"
#include "Vortex_Tom_Stoops.h"
#include "Doublet_Tom_Stoops.h"
#include "VortexSheet_Tom_Stoops.h"

void Opdracht_1() {
	Grid opdr1(-2, 2, -1, 1, 200, 100);

	// Deel 1: Q_1 = Q_2
	std::cout << "\n\t-----------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 1: Deel 1: Source-Sink met Q_1 = Q_2 = 1 |" << std::endl;
	std::cout << "\t-----------------------------------------------------" << std::endl;

	Source bron(-1, 0, 1);
	Source put(1, 0, -1);
	opdr1.addBaseFlow(&bron);
	opdr1.addBaseFlow(&put);

	std::cout << "-- Data wegschrijven naar bestanden met signature: 'O1_D1' --" << std::endl;
	opdr1.writeStream("O1_D1_stream");
	opdr1.writePotential("O1_D1_potential");
	opdr1.writeVelocity("O1_D1_vectors");


	// Deel 2: Q_1 > Q_2
	std::cout << "\n\t------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 1: Deel 2: Source-Sink met Q_1 = 1 > Q_2 = 0.25 |" << std::endl;
	std::cout << "\t------------------------------------------------------------" << std::endl;
	opdr1.clearBaseFlow();

	Source put2(1, 0, -0.25);
	opdr1.addBaseFlow(&bron);
	opdr1.addBaseFlow(&put2);

	std::cout << "-- Data wegschrijven met signature: 'O1_D2' --" << std::endl;
	opdr1.writeStream("O1_D2_stream");
	opdr1.writePotential("O1_D2_pressure");
	opdr1.writeVelocity("O1_D2_vectors");


	// Deel 3: Q_ 1 = Q_ 2 && Q*l = cte
	std::cout << "\n\t--------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 1: Deel 3: Source-Sink met Q_1 = Q_2 && Q*l = cte |" << std::endl;
	std::cout << "\t--------------------------------------------------------------" << std::endl;
	opdr1.clearBaseFlow();

	std::cout << "-- We zorgen dat Q*l = 1 => gelijkwaardig aan een doublet met sterkte 1 voor l->0. --" << std::endl;
	std::vector<double> l = { 1, 0.5, 0.25, 0.125 };
	std::vector<double> Q = { 1, 2, 4, 8 };

	std::cout << "-- Data wegschrijven met signature: 'O1_D3_i' waar 'i' de ide iteratie. --" << std::endl;
	for (int i = 0; i < Q.size(); i++) {
		std::cout << "||Iteratie " << i+1 << "||" << std::endl;
		Source doublet_bron((-l.at(i) / 2), 0, Q.at(i));
		Source doublet_put((l.at(i) / 2), 0, (-Q.at(i)));
		opdr1.addBaseFlow(&doublet_bron);
		opdr1.addBaseFlow(&doublet_put);

		opdr1.writeStream("O1_D3_" + std::to_string(i+1) + "_stream");
		opdr1.writePotential("O1_D3_" + std::to_string(i+1) + "_potential");
		opdr1.writeVelocity("O1_D3_" + std::to_string(i+1) + "_vectors");
		opdr1.clearBaseFlow();
	}




};