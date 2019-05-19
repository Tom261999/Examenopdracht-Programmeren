/*
	Inleiding Programmeren: Examenopdracht
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 19-05-2019
 */

#pragma once
#include "pch.h"
#include "Opdrachten_Tom_Stoops.h"

int main() {

	Opdracht_1();
	/*
	Voor opdracht 1 maken we een grid x \in [-2,2] en y \in [-1,1] met 200 en 100 stappen respectievelijk. 
	Voor het eerste onderdeel zullen we source en sink even sterk maken met Q = +- 1, source gelokaliseerd op (-1,0) en de sink op (1,0). 
	Voor het tweede onderdeel gebruiken we dezelfde source maar plaatsen we nu een sink op (1,0) met sterkte Q = 0.25.
	Voor het derde onderdeel maken we verschillende plots voor Q*l = 1 = cte waarbij we voor l waarden uit volgende set nemen: {1, 0.5, 0.25, 0.125} zodat Q uit volgende set waarden komt: {1, 2, 4, 8}.
	De source wordt dan geplaatst op (-l/2,0) en de sink op (l/2,0). We zien hier dan voor l->0 de stroomlijnen van een source-sink doublet optreden.	
	*/

	Opdracht_2();
	/*
	In deze opdracht maken we gebruik van een grid met volgende parameters: x \in [-4,4] en y \in [-2,2] met 400 en 200 stappen respectievelijk.
	We zullen dan een source met sterkte 6 plaatsen op (-1,0) in een uniforme stroom parallel met de x-as met sterkte 1. Door dit grote verschil in sterkte zal de rankine half body zeer duidelijk
	weergegeven worden.
	*/
	
	Opdracht_3();
	/*
	In deze opdracht gebruiken we hetzelfde grid als in opdracht 1.
	Voor het eerste onderdeel plaatsen we source-sink paar op dezelfde posities als in opdracht 1 en plaatsen we daarover een uniforme stroom parallel met de x-as en gelijke sterkte 1 = U_\infty = Q.
	Hierbij zal de Rankine oval gevormd worden op de plots.
	Voor het tweede deel bekijken we ook wat er gebeurt indien de source een sterkte 3 krijgt (Q_source > Q_sink = U_\infty), hierbij zien we een combinatie van een Rankine oval en Rankine half body.
	Dit is ook niet verwonderlijk aangezien je deze constructie kan bekomen door superpositie van de twee scenario's.
	*/

	Opdracht_4();
	/*
	In deze opdracht gebruiken we hetzelfde grid als in opdracht 1.
	We plaatsen voor deze opdracht een source-sink doublet in een uniforme stroom parallel met de x-as met gelijke sterkten \kappa = U_\infty = 1.
	Hierbij zien we dan dat de Rankine oval een cirkel vormt, en we dus een doublet kunnen gebruiken om een cirkelvormig object te simuleren in een fluïdum stroom.
	*/

	Opdracht_5();
	/*
	In deze opdracht maken we een grid met volgende parameters: x \in [-2.5,2.5] en y \in [-1,1] met 300 en 100 stappen respectievelijk.
	In het eerste deel van de opdracht plaatsen we eenvoudigweg een vortex in de oorsprong met sterkte \Gamma = 1. Dit vormt zoals te verwachten is slechts een cirkelvormige stroom.
	Voor het tweede onderdeel van de opdracht nemen we de source uit het eerste deel en plaatsen we daar ook een sink over met gelijke sterkte Q = 1. Niet verwonderlijk zal dit een draaikolk opleveren.
	Voor het derde onderdeel zullen we N vortices equidistant  met gelijke sterktes plaatsen tussen x = -2 en x = 2 (en y = 0), hierbij nemen we N uit volgende set: {3, 4, 5, 10}. We zien dan dat het
	numerieke vortexsheet een interface oplevert tussen twee stroomrichtingen indien we een klein interval rond de oorsprong beschouwen.
	Voor het vierde onderdeel maken we gebruik van een analytische uitdrukking om een oneindig lange rij van equidistante vortices met gelijke sterktes te simuleren. Ook hier zien we dat we zo de
	interface tussen twee fluïda met verschillende stromen kunnen modelleren.
	*/

	Opdracht_6();
	/*
	In deze opdracht maken we gebruik van hetzelfde grid als opdracht 1.
	In het eerste onderdeel onderzoeken we het Magnus effect door een doublet in uniforme stroming te beschouwen met een vortex op dezelfde positie als het doublet. In fysische termen simuleren we zo
	een draaiende cilinder in een uniforme stroming. We gebruiken hiervoor als parameters U_\infty = \kappa = 1 en \Gamma = 2. (Grotere \Gamma geeft duidelijker waarneembaar Magnus effect.)
	Voor het tweede onderdeel bekijken we het gedrag van het systeem beschouwd in vorig onderdeel indien er een theoretisch criterium overschreden wordt. We zien hier dan dat we slechts een asymmetrische
	vortex overhouden.
	*/

	return 0;
};
