#include "AlgoritmoGenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico()
{
}

AlgoritmoGenetico::~AlgoritmoGenetico()
{
}

Poblacion AlgoritmoGenetico::crossoverPopulation_1(Poblacion population_, int selecion_padre)
{
	double r;
	// Create new population
	Poblacion newPopulation = Poblacion( population_.size());
	// Loop over current population by fitness
	/*
	int auxborrar = 0;
	for (int populationIndex = 0; populationIndex < population_.size(); populationIndex++)
	{
		Individuo parent1 = population_.getFittest(populationIndex);
		r = ((double)rand() / (RAND_MAX));
		// Apply crossover to this individual?
		if (crossoverRate > r && populationIndex > elitismoCont)
		{
			// Initialize offspring
			Individuo offspring = Individuo(parent1.getChromosomeLength());
			// Find second parent					
			Individuo parent2;
			switch (selecion_padre)
			{
			case 1:
				parent2 = selectParent_Random(population_);
				break;
			case 2:
				parent2 = selectParent_RouletteWheel(population_);
				break;
			case 3:
				parent2 = selectParent_TournamentSelection(population_);
				break;

			default:
				parent2 = selectParent_Random(population_);
				break;
			}

			// Loop over genome
			for (int geneIndex = 0; geneIndex < parent1.getChromosomeLength(); geneIndex++)
			{
				// Use half of parent1's genes and half of parent2's genes
				r = ((double)rand() / (RAND_MAX));
				if (0.5 > r)
				{
					offspring.setGene(geneIndex, parent1.getGene(geneIndex));
				}
				else
				{
					offspring.setGene(geneIndex, parent2.getGene(geneIndex));
				}
			}
			// Add offspring to new population
			newPopulation.setIndividual(populationIndex, offspring);
		}
		else
		{
			// Add individual to new population without applying crossover
			newPopulation.setIndividual(populationIndex, parent1);
		}
	}
	return newPopulation;
	*/
	return Poblacion();
}
