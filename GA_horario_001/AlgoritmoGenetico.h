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
	AlgoritmoGenetico(int poblacionTamano, double gradoDeMuatacion, double crossoverRate, int elitismoCont, int tamanoDeTorneo);


	//Metodos de apareamiento
	Poblacion crossoverPopulation_1(Poblacion population_, int selecion_padre);

private:
	int poblacionTamano;
	double gradoDeMuatacion;
	double crossoverRate;
	int elitismoCont;
	int tamanoDeTorneo;
};

