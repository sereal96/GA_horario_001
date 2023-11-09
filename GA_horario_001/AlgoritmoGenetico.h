#pragma once

#include "Poblacion.h"
#include "Individuo.h"

#include <vector>
#include <algorithm>

class AlgoritmoGenetico
{
public:
	AlgoritmoGenetico();
	~AlgoritmoGenetico();
	AlgoritmoGenetico(int poblacionTamano_, double gradoDeMuatacion_, double crossoverRate_, int elitismoCont_, int tamanoDeTorneo_);

	//Selecion de progenitores
	Individuo selectParent_Random(Poblacion population_);								// 1
	Individuo selectParent_RouletteWheel(Poblacion population_);						// 2
	Individuo selectParent_TournamentSelection(Poblacion population_);					// 3

	//Metodos de apareamiento
	Poblacion crossoverPopulation_1(Poblacion population_, int selecion_padre);
	

private:
	int poblacionTamano;
	double gradoDeMuatacion;
	double crossoverRate;
	int elitismoCont;
	int tamanoDeTorneo;
};

