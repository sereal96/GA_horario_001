#include "AlgoritmoGenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico()
{
}

AlgoritmoGenetico::~AlgoritmoGenetico()
{
}

AlgoritmoGenetico::AlgoritmoGenetico(int poblacionTamano_, double gradoDeMuatacion_, double crossoverRate_, int elitismoCont_, int tamanoDeTorneo_)
{
	poblacionTamano = poblacionTamano_;
	gradoDeMuatacion = gradoDeMuatacion_;
	crossoverRate = crossoverRate_;
	elitismoCont = elitismoCont_;
	tamanoDeTorneo = tamanoDeTorneo_;
}

Individuo AlgoritmoGenetico::selectParent_Random(Poblacion population_)
{

	// Get individuals
	std::vector<Individuo> individuals = population_.getPobladores();//  getIndividuals();
	// Spin roulette wheel
	//double populationFitness = population_.getPopulationFitness();
	int hasar = std::rand() % population_.size() + 1;
	while (hasar >= individuals.size())
	{
		hasar = std::rand() % population_.size() + 1;
	}
	// Find parent
	return individuals[hasar];

	return Individuo();
}

Individuo AlgoritmoGenetico::selectParent_RouletteWheel(Poblacion population_)
{
	// Get individuals
	std::vector<Individuo> individuals = population_.getPobladores();  //getIndividuals();
	// Spin roulette wheel
	double populationFitness = population_.getAptitudPoblacion();// getPopulationFitness();
	double rouletteWheelPosition = rand() * populationFitness;

	// Find parent
	double spinWheel = 0;
	for (Individuo individual : individuals)
	{
		spinWheel += individual.getAptitud();// getFitness();
		if (spinWheel >= rouletteWheelPosition)
		{
			return individual;
		}
	}
	return individuals[population_.size() - 1];
}

Individuo AlgoritmoGenetico::selectParent_TournamentSelection(Poblacion population_)
{
	// Create tournament
	Poblacion tournament = Poblacion(tamanoDeTorneo);
	// Add random individuals to the tournament

	Poblacion poblacionAux = population_;
	poblacionAux.shuffle();
	//for (int i = 0; i < tournamentSize; i++) 
	bool sw_completo = false;
	int i = 0;
	int a = 0;
	int b = 0;
	while (!sw_completo)
	{
		a = std::rand() % poblacionAux.size() + 1;
		a = std::rand() % poblacionAux.size() + 1;
		if (a >= 0 && a <= (poblacionAux.size() - 1))
		{
			if (a == b)
			{
				a = std::rand() % (poblacionAux.size() - 1) + 1;
			}
		}
		else
		{
			a--;
		}
		b = a;
		Individuo tournamentIndividual = poblacionAux.getPobladorPorCelda(a);
		if (tournamentIndividual.getAptitud() >= -1)//discriminar mutantes TODAVIA A PRUEVA
		{
			tournament.setPoblador(i, tournamentIndividual);
			i++;
		}
		if (i == tamanoDeTorneo)
		{
			sw_completo = true;
		}
	}
	// Return the best
	return tournament.getIndividuoMasApto(tournament.size() - 1);
}

Poblacion AlgoritmoGenetico::crossoverPopulation_1(Poblacion population_, int selecion_padre)
{
	double r;
	// Create new population
	Poblacion newPopulation = Poblacion( population_.size());
	// Loop over current population by fitness
	
	int auxborrar = 0;
	for (int populationIndex = 0; populationIndex < population_.size(); populationIndex++)
	{
		Individuo parent1 = population_.getPobladorPorCelda(populationIndex);
		r = ((double)rand() / (RAND_MAX));
		// Apply crossover to this individual?
		
		if (crossoverRate > r && populationIndex > elitismoCont)
		{
			// Initialize offspring
			Individuo offspring = parent1; // Individuo(parent1.getChromosomeLength());
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


			//Genera una semillar basada en fecha,hora,minuto y segundo
			std::time_t tiempoActual = std::time(0);
			std::tm tiempoInfo;
			// Usar std::localtime_s para obtener la información de tiempo actual
			localtime_s(&tiempoInfo, &tiempoActual);
			unsigned int semilla = tiempoInfo.tm_sec + tiempoInfo.tm_min * 60 + tiempoInfo.tm_hour * 3600 +
				tiempoInfo.tm_mday * 86400 + (tiempoInfo.tm_mon + 1) * 2592000 + (tiempoInfo.tm_year + 1900) * 31104000;
			srand(semilla);

			// Loop over genome
			std::vector<int> auxCursoVector = parent1.getPosicionDelCursoEnVector();
			int geneIndex = 0;
			while (geneIndex < parent1.sizeGenomaS())
			{

			//}
			//for (int geneIndex = 0; geneIndex < parent1.sizeGenomaS(); geneIndex++)
			//{
				
				auto iterador = std::find(auxCursoVector.begin(), auxCursoVector.end(), geneIndex);
				if (iterador == auxCursoVector.end())
				{
					// Use half of parent1's genes and half of parent2's genes
					r = ((double)rand() / (RAND_MAX));
					if (0.5 > r)
					{
						offspring.setGenomaS(geneIndex + 0, parent1.getGenomaS(geneIndex + 0));
						offspring.setGenomaS(geneIndex + 1, parent1.getGenomaS(geneIndex + 1));
						offspring.setGenomaS(geneIndex + 2, parent1.getGenomaS(geneIndex + 2));
						offspring.setGenomaS(geneIndex + 3, parent1.getGenomaS(geneIndex + 3));
						offspring.setGenomaS(geneIndex + 4, parent1.getGenomaS(geneIndex + 4));
					}
					else
					{	
						offspring.setGenomaS(geneIndex + 0, parent2.getGenomaS(geneIndex + 0));
						offspring.setGenomaS(geneIndex + 1, parent2.getGenomaS(geneIndex + 1));
						offspring.setGenomaS(geneIndex + 2, parent2.getGenomaS(geneIndex + 2));
						offspring.setGenomaS(geneIndex + 3, parent2.getGenomaS(geneIndex + 3));
						offspring.setGenomaS(geneIndex + 4, parent2.getGenomaS(geneIndex + 4));
					}
					geneIndex = geneIndex + 4;
					//offspring.calculaAptitudIndividuo();
				}
				else
				{
					offspring.setGenomaS(geneIndex, parent1.getGenomaS(geneIndex));
				}
				geneIndex++;
				// Use half of parent1's genes and half of parent2's genes
				//r = ((double)rand() / (RAND_MAX));
				//if (0.5 > r)
				//{
				//	offspring.setGenomaS(geneIndex, parent1.getGenomaS(geneIndex));
				//}
				//else
				//{					
				//	offspring.setGenomaS(geneIndex, parent2.getGenomaS(geneIndex));
				//}
				//offspring.calculaAptitudIndividuo();
			}
			offspring.calculaAptitudIndividuo();

			// Add offspring to new population
			newPopulation.setPoblador(populationIndex, offspring);
		}
		else
		{
			// Add individual to new population without applying crossover
			newPopulation.setPoblador(populationIndex, parent1);
		}
		//*/
	}
	newPopulation.calculaAptitudPoblacion();
	return newPopulation;
}
