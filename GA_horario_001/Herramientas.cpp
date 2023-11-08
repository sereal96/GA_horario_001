#include "Herramientas.h"



Herramientas::Herramientas()
{
}

Herramientas::~Herramientas()
{
}

std::vector<int> Herramientas::combierteEnteroBinario(int valor)
{
	std::vector<int> vec_binario;

	std::string binary = std::bitset<16>(valor).to_string();
	
	int aux = std::stoi(binary);
	std::string numeroComoString = std::to_string(aux);

	std::vector<int> digits;
	for (char digit : numeroComoString) {
		vec_binario.push_back(digit - '0');
	}	

	return vec_binario;
}

std::vector<int> Herramientas::combierteEnteroBinario8Bits(int valor)
{
	std::vector<int> vec_binario;

	std::string binary = std::bitset<8>(valor).to_string();

	std::vector<int> digits;
	for (char digit : binary) {
		vec_binario.push_back(digit - '0');
	}
	return vec_binario;
}

int Herramientas::combierteBinarioEntero(std::vector<int> valor_vect)
{
	std::string result;

	for (int digit : valor_vect) {
		result += std::to_string(digit);
	}
		
	int integerValue = std::stoi(result, nullptr, 2);


	return integerValue;
}

void Herramientas::printVectBinario(std::vector<int> vector_binario)
{
	// Acceder a los elementos usando iteradores
	std::cout << "Elementos del vector (Binario):" << std::endl;
	for (auto it = vector_binario.begin(); it != vector_binario.end(); ++it) {
		std::cout << *it << " ---- ";
	}
	std::cout << "\n";
}
