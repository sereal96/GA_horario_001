#include "Poblacion.h"

Poblacion::Poblacion()
{
}

Poblacion::Poblacion(int poblacionSize)
{
	std::vector<Individuo> populationAux(poblacionSize);
	pobladores = populationAux;
}

Poblacion::~Poblacion()
{
}

void Poblacion::GeneradorDePoblacion(int cantidad, int numero_de_dias_, int numero_de_periodos_, int numero_de_cursos_, int numero_de_profesores_,
	int numero_de_materias_, int numero_de_aulas_)
{
	for (int i = 0; i < cantidad; i++)
	{
		Individuo i1;
		i1.crearGenomaS(numero_de_dias_, numero_de_periodos_, numero_de_cursos_, numero_de_profesores_, numero_de_materias_, numero_de_aulas_);
		std::cout << "individuo " << std::to_string(i) << " añadido.\n";
		i1.calculaAptitudIndividuo();
		pobladores.push_back(i1);
	}
}

int Poblacion::size()
{
	return pobladores.size();
}
