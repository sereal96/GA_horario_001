#include "Grado.h"

Grado::Grado()
{
}

Grado::~Grado()
{
}

Grado::Grado(int id_grado_, std::string nombre_, int id_nivel_)
{
	id_grado = id_grado_;
	nombre = nombre_;
	id_nivel = id_nivel_;
}

int Grado::getIdGrado()
{
	return id_grado;
}

std::string Grado::getNombre()
{
	return nombre;
}

int Grado::getIdNivel()
{
	return id_nivel;
}
