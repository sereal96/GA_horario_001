#pragma once

#include <vector>
#include <string>
#include <bitset>
#include <iostream>

#include <cstdlib> // Incluir la librería para usar srand() y rand()
#include <ctime>

#include <cmath>

#include <unordered_set>//elementos repetidos

class Herramientas
{
public:
	Herramientas();
	~Herramientas();

	/*
	Combierte un valor Natural a su equivalente en binario y lo regresa como vector donde cada valor ocupa un espacion en el vector
	Parámetros:
		- valor: tipo int, valor numerico que se desea comvertir
	Devuelve:
		- vector: tipo std::vector<int> el vector compuesto
	Nota:
	*/
	std::vector<int> combierteEnteroBinario(int valor);


	/*
	Combierte un valor Natural a su equivalente en binario y lo regresa como vector donde cada valor ocupa un espacion en el vector
	Parámetros:
		- valor: tipo int, valor numerico que se desea comvertir
	Devuelve:
		- vector: tipo std::vector<int> el vector compuesto
	Nota:
	*/
	std::vector<int> combierteEnteroBinario8Bits(int valor);



	/*
	Combierte un valor Natural a su equivalente en binario y lo regresa como vector donde cada valor ocupa un espacion en el vector
	Parámetros:
		- valor_vect: std::vector<int> requier un venctor en el que cada casilla tiene que tener el valor 0 o 1
	Devuelve:
		- valor_vect: int devuelve al valor equivalente a su numero natural
	Nota:
	*/
	int combierteBinarioEntero(std::vector<int> valor_vect);

	/*
	* Imprime el vector binario
	*/
	void printVectBinario(std::vector<int> vector_binario);

private:
};

