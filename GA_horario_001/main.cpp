#include <string>

#include "Herramientas.h"
#include "Individuo.h"
#include "Poblacion.h"

std::string aux = "";



int main(int argc, char* args[])
{
	Herramientas h1;// = new Herramientas();
	
	h1.combierteEnteroBinario8Bits(20);

	Individuo i1;
	i1.crearGenomaS(5, 6, 2, 20, 5, 20); //3   10=>10+9+8+7+6+5+4+3+2+1 = 55
	i1.printindividuo();
	i1.calculaAptitudIndividuo();
	//std::cout << "\n";
	//std::cout << std::to_string(i1.getAptitud());


	
	

	int poblacionTamano = 1; //populationSize = 100;
	double gradoDeMuatacion = 0.01;// mutationRate = 0.01;
	double crossoverRate = 0.9;
	int elitismoCont = 2;// elitismCount = 2;
	int tamanoDeTorneo = 5;// tournamentSize = 5;

	Poblacion pob;
	int numero_de_dias = 5;
	int numero_de_periodos = 6;
	int numero_de_cursos = 2;
	int numero_de_profesores = 20;
	int numero_de_materias = 5;
	int numero_de_aulas = 20;
	pob.GeneradorDePoblacion(poblacionTamano, numero_de_dias, numero_de_periodos, numero_de_cursos, numero_de_profesores, numero_de_materias, numero_de_aulas);


	// Keep track of current generation
	int generation = 1;
	// Start evolution loop
	// TODO: Add termination condition
	while (generation <= 10)//(ga.isTerminationConditionMet(generation, 1000) == false && ga.isTerminationConditionMet(population) == false)
	{

		//System.out.println("G" + generation + " Best fitness: " + population.getFittest(0).getFitness());

		// Apply crossover
		//population = ga.crossoverPopulation_1(population, 3);

		// TODO: Apply mutation
		//population = ga.mutatePopulation(population, timetable);

		// TODO: Evaluate population


		// Increment the current generation
		generation++;

		//aux = "Generacion " + std::to_string(generation) + " fitnes " + std::to_string(population.populationFitness) + "\n";
		//OutputDebugStringA(aux.c_str());
	}

	//print resultados


	//*/

	return 0;
}