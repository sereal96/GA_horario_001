#pragma once
#include <vector>

#include "Individuo.h"

class Poblacion
{
public:
	Poblacion();
	Poblacion(int poblacionSize);
	~Poblacion();
	

	void GeneradorDePoblacion(int cantidad, int numero_de_dias_, int numero_de_periodos_, int numero_de_cursos_, int numero_de_profesores_,
		int numero_de_materias_, int numero_de_aulas_);
	int size();

private:
	std::vector<Individuo> pobladores;
};

