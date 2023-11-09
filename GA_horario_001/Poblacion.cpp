#include "Poblacion.h"
#include <algorithm>

struct SortByAptitud
{
	bool operator() (Individuo const& L, Individuo const& R) { return L.aptitud < R.aptitud; }
};

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

std::vector<Individuo> Poblacion::getPobladores()
{
	return pobladores;
}

void Poblacion::setPoblador(int pos, Individuo poblador_)
{
	pobladores[pos] = poblador_;
}

void Poblacion::calculaAptitudPoblacion()
{
	double poblacion = 0.0;
	for (int i = 0; i < pobladores.size(); i++)
	{
		poblacion = poblacion + pobladores[i].getAptitud();
	}
	aptitud_Poblacion = poblacion / pobladores.size();
}

void Poblacion::setAptitudPoblacion(double aptitudP)
{
	aptitud_Poblacion = aptitudP;
}

double Poblacion::getAptitudPoblacion()
{
	return aptitud_Poblacion;
}

Individuo Poblacion::getPobladorPorCelda(int posicion_)
{	
	return pobladores[posicion_];
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

Individuo Poblacion::getIndividuoMasApto(int offset)
{
	std::sort(pobladores.begin(), pobladores.end(), SortByAptitud{});
	return pobladores[offset];
}

void Poblacion::shuffle()
{
	//Random rnd = new Random();
	for (int i = pobladores.size() - 1; i > 0; i--) {
		int index = std::rand() % pobladores.size();//int index = rnd.nextInt(i + 1);
		Individuo a = pobladores[index];
		pobladores[index] = pobladores[i];
		pobladores[i] = a;
	}
}

void Poblacion::ordenarPoblacionDecendente()
{
	std::sort(pobladores.begin(), pobladores.end(), SortByAptitud{});
}
