#include "Materia.h"

Materia::Materia()
{
}

Materia::~Materia()
{
}

Materia::Materia(int id_materia_, std::string nombre_, std::string nivel_, std::string grado_)
{
	id_materia = id_materia_;
	nombre = nombre_;
	nivel = nivel_;
	grado = grado_;
}

int Materia::getIdMateria()
{
	return id_materia;
}

std::string Materia::getNombre()
{
	return nombre;
}

std::string Materia::getNivel()
{
	return nivel;
}

std::string Materia::getGrado()
{
	return grado;
}
