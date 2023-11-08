#include "Dia.h"

Dia::Dia()
{
}

Dia::~Dia()
{
}

Dia::Dia(int id_dia_, std::string nombre_, std::string abrev_)
{
	id_dia = id_dia_;
	nombre = nombre_;
	abrev = abrev_;
}

int Dia::getIdDia()
{
	return id_dia;
}

std::string Dia::getNombre()
{
	return nombre;
}

std::string Dia::getAbrev()
{
	return abrev;
}
