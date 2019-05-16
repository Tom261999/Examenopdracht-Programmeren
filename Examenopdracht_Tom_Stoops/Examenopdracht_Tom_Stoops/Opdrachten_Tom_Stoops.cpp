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
	std::cout << "\n\n\t==================================" << std::endl;
	std::cout << "\t|| Opdracht 1: Source-Sink paar ||" << std::endl;
	std::cout << "\t==================================" << std::endl;
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
	opdr1.writePotential("O1_D2_potential");
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

		doublet_bron.~Source();
		doublet_put.~Source();
		opdr1.clearBaseFlow();
	}
};

void Opdracht_2() {

	std::cout << "\n\t=========================================" << std::endl;
	std::cout << "\t|| Opdracht 2: Source in Uniforme flow ||" << std::endl;
	std::cout << "\t=========================================" << std::endl;
	Grid opdr2(-4, 4, -2, 2, 200, 100);

	Source bron(-1, 0, 6);
	Uniform stroming(0, 1);
	opdr2.addBaseFlow(&bron);
	opdr2.addBaseFlow(&stroming);

	std::cout << "-- Data wegschrijven met signature: 'O2' --" << std::endl;
	opdr2.writeStream("O2_stream");
	opdr2.writePotential("O2_potential");
	opdr2.writeVelocity("O2_vectors");
};

void Opdracht_3() {
	std::cout << "\n\n\t===================================================" << std::endl;
	std::cout << "\t|| Opdracht 3: Source-Sink paar in Uniforme flow ||" << std::endl;
	std::cout << "\t===================================================" << std::endl;
	Grid opdr3(-2, 2, -1, 1, 200, 100);

	// Deel 1: Q_1 = Q_2 = U_infty
	std::cout << "\n\t---------------------------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 3: Deel 1: Source-Sink paar in Uniforme flow met Q_1 = Q_2 = U_infty |" << std::endl;
	std::cout << "\t---------------------------------------------------------------------------------" << std::endl;

	Source bron(-1, 0, 1);
	Source put(1, 0, -1);
	Uniform stroom(0, 1);
	opdr3.addBaseFlow(&bron);
	opdr3.addBaseFlow(&put);
	opdr3.addBaseFlow(&stroom);

	std::cout << "-- Data wegschrijven met signature: 'O3_D1' --" << std::endl;
	opdr3.writeStream("O3_D1_stream");
	opdr3.writePotential("O3_D1_potential");
	opdr3.writeVelocity("O3_D1_vectors");
	opdr3.writeCp("O3_D1_drukcoeff", &stroom);

	// Deel 2: Q_1 > Q_2 = U_infty
	std::cout << "\n\t---------------------------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 3: Deel 2: Source-Sink paar in Uniforme flow met Q_1 > Q_2 = U_infty |" << std::endl;
	std::cout << "\t---------------------------------------------------------------------------------" << std::endl;
	opdr3.clearBaseFlow();

	Source bron2(-1, 0, 3);
	opdr3.addBaseFlow(&bron2);
	opdr3.addBaseFlow(&put);
	opdr3.addBaseFlow(&stroom);

	std::cout << "-- Data wegschrijven met signature: 'O3_D2' --" << std::endl;
	opdr3.writeStream("O3_D2_stream");
	opdr3.writePotential("O3_D2_potential");
	opdr3.writeVelocity("O3_D2_vectors");

	/* // Overbodig!
	// Deel 3: U_infty = Q_1 > Q_2
	std::cout << "\n\t---------------------------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 3: Deel 3: Source-Sink paar in Uniforme flow met U_infty = Q_1 > Q_2 |" << std::endl;
	std::cout << "\t---------------------------------------------------------------------------------" << std::endl;
	opdr3.clearBaseFlow();

	Source bron3(-1, 0, 4);
	Uniform stroom3(0, 4);
	opdr3.addBaseFlow(&bron3);
	opdr3.addBaseFlow(&put);
	opdr3.addBaseFlow(&stroom3);

	std::cout << "-- Data wegschrijven met signature: 'O3_D3' --" << std::endl;
	opdr3.writeStream("O3_D3_stream");
	opdr3.writePotential("O3_D3_potential");
	opdr3.writeVelocity("O3_D3_vectors");
	*/
};

void Opdracht_4() {
	std::cout << "\n\n\t==========================================" << std::endl;
	std::cout << "\t|| Opdracht 4: Doublet in Uniforme flow ||" << std::endl;
	std::cout << "\t==========================================" << std::endl;
	Grid opdr4(-2, 2, -1, 1, 200, 100);

	Doublet bronput(0, 0, 1);
	Uniform stroom(0, 1);
	opdr4.addBaseFlow(&bronput);
	opdr4.addBaseFlow(&stroom);

	std::cout << "-- Data wegschrijven met signature: 'O4' --" << std::endl;
	opdr4.writeStream("O4_stream");
	opdr4.writePotential("O4_potential");
	opdr4.writeVelocity("O4_vectors");
	opdr4.writeCp("O4_drukcoeff", &stroom);
};

void Opdracht_5() {
	std::cout << "\n\n\t==========================" << std::endl;
	std::cout << "\t|| Opdracht 5: Vortices ||" << std::endl;
	std::cout << "\t==========================" << std::endl;
	Grid opdr5(-2.5, 2.5, -1, 1, 300, 100);

	std::cout << "\n\t------------------------------" << std::endl;
	std::cout << "\t| Opdracht 5: Deel 1: Vortex |" << std::endl;
	std::cout << "\t------------------------------" << std::endl;

	Vortex vort(0, 0, 1);
	opdr5.addBaseFlow(&vort);

	std::cout << "-- Data wegschrijven met signature: 'O5_D1' --" << std::endl;
	opdr5.writeStream("O5_D1_stream");
	opdr5.writePotential("O5_D1_potential");
	opdr5.writeVelocity("O5_D1_vectors");

	std::cout << "\n\t---------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 5: Deel 2: Vortex & Sink (op zelfde positie) |" << std::endl;
	std::cout << "\t---------------------------------------------------------" << std::endl;
	
	Source put(0, 0, -1);
	opdr5.addBaseFlow(&put);

	std::cout << "-- Data wegschrijven met signature: 'O5_D2' --" << std::endl;
	opdr5.writeStream("O5_D2_stream");
	opdr5.writePotential("O5_D2_potential");
	opdr5.writeVelocity("O5_D2_vectors");

	std::cout << "\n\t----------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 5: Deel 3: N Vortices met sterkte Gamma |" << std::endl;
	std::cout << "\t----------------------------------------------------" << std::endl;
	opdr5.clearBaseFlow();

	std::cout << "-- We verhogen het aantal vortices tussen x = -2 en x = 2 langs y = 0. --" << std::endl;
	std::vector<int> N = { 3, 4, 5, 10 };

	std::cout << "-- Data wegschrijven met signature: 'O1_D3_i' waar 'i' de ide iteratie. --" << std::endl;
	for (int i = 0; i < N.size(); i++) {
		std::cout << "||Iteratie " << i + 1 << "||" << std::endl;
		VortexSheet vortsheet(-2, 2, 0, 1, N.at(i));
		opdr5.addBaseFlow(&vortsheet);

		opdr5.writeStream("O5_D3_" + std::to_string(i + 1) + "_stream");
		opdr5.writePotential("O5_D3_" + std::to_string(i + 1) + "_potential");
		opdr5.writeVelocity("O5_D3_" + std::to_string(i + 1) + "_vectors");

		vortsheet.~VortexSheet();
		opdr5.clearBaseFlow();
	}

	std::cout << "\n\t------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 5: Deel 4: Analytische VortexSheet met a =  0.5 |" << std::endl;
	std::cout << "\t------------------------------------------------------------" << std::endl;

	VortexSheet vortsheetAnalytisch(1, 0.5);
	opdr5.addBaseFlow(&vortsheetAnalytisch);

	std::cout << "-- Data wegschrijven met signature: 'O5_D4' --" << std::endl;
	opdr5.writeStream("O5_D4_stream");
	opdr5.writePotential("O5_D4_potential");
	opdr5.writeVelocity("O5_D4_vectors");
};

void Opdracht_6() {
	std::cout << "\n\n\t====================================" << std::endl;
	std::cout << "\t|| Opdracht 6: Lift op een Vortex ||" << std::endl;
	std::cout << "\t====================================" << std::endl;
	Grid opdr6(-2, 2, -1, 1, 200, 100);

	std::cout << "\n\t--------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 6: Deel 1: Kappa = U_infty = 1 en Gamma = 2 |" << std::endl;
	std::cout << "\t--------------------------------------------------------" << std::endl;

	Uniform stroom(0, 1);
	Doublet bronput(0, 0, 1);
	Vortex vort(0, 0, 2);
	opdr6.addBaseFlow(&stroom);
	opdr6.addBaseFlow(&bronput);
	opdr6.addBaseFlow(&vort);	

	std::cout << "-- Data wegschrijven met signature: 'O6_D1' --" << std::endl;
	opdr6.writeStream("O6_D1_stream");
	opdr6.writePotential("O6_D1_potential");
	opdr6.writeVelocity("O6_D1_vectors");

	std::cout << "\n\t-------------------------------------------------------------------" << std::endl;
	std::cout << "\t| Opdracht 6: Deel 2: U_infty = kappa = 1, Gamma 10 * pi > 8 * pi |" << std::endl;
	std::cout << "\t-------------------------------------------------------------------" << std::endl;
	opdr6.clearBaseFlow();

	Vortex vort2(0, 0, 10 * M_PI);
	opdr6.addBaseFlow(&stroom);
	opdr6.addBaseFlow(&bronput);
	opdr6.addBaseFlow(&vort2);

	std::cout << "-- Data wegschrijven met signature: 'O6_D2' --" << std::endl;
	opdr6.writeStream("O6_D2_stream");
	opdr6.writePotential("O6_D2_potential");
	opdr6.writeVelocity("O6_D2_vectors");
};