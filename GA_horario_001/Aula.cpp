#include "Aula.h"

Aula::Aula()
{
}

Aula::~Aula()
{
}

Aula::Aula(int id_aula_, std::string numero_, int capacidad_, std::string ubicacion_)
{
	id_aula = id_aula_;
	numero = numero_;
	capacidad = capacidad_;
	ubicacion = ubicacion_;
}

int Aula::geIdAula()
{
	return id_aula;
}

std::string Aula::getNumero()
{
	return numero;
}

int Aula::getCapacidad()
{
	return capacidad;
}

std::string Aula::getUbicacion()
{
	return ubicacion;
}
