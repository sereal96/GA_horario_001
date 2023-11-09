#pragma once
#include <vector>

#include "Individuo.h"

class Poblacion
{
public:
	Poblacion();
	Poblacion(int poblacionSize);
	~Poblacion();
	
	std::vector<Individuo> getPobladores();
	void setPoblador(int pos, Individuo poblador_);
	void calculaAptitudPoblacion();
	void setAptitudPoblacion(double aptitudP);
	double getAptitudPoblacion();

	

	Individuo getPobladorPorCelda(int posicion_);
	void GeneradorDePoblacion(int cantidad, int numero_de_dias_, int numero_de_periodos_, int numero_de_cursos_, int numero_de_profesores_,
		int numero_de_materias_, int numero_de_aulas_);
	int size();

	Individuo getIndividuoMasApto(int offset);

	void shuffle();
	void ordenarPoblacionDecendente();

private:
	std::vector<Individuo> pobladores;
	double aptitud_Poblacion = -1.0;
};

