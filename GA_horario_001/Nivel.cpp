#include "Nivel.h"

Nivel::Nivel()
{
}

Nivel::~Nivel()
{
}

Nivel::Nivel(int id_nivel_, std::string nombre_)
{
	id_nivel = id_nivel_;
	nombre = nombre_;
}

int Nivel::getIdNivel()
{
	return id_nivel;
}

std::string Nivel::getNombre()
{
	return nombre;
}
