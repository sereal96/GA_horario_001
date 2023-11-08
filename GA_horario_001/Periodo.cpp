#include "Periodo.h"

Periodo::Periodo()
{
}

Periodo::~Periodo()
{
}

Periodo::Periodo(int id_periodo_, std::string nombre_, std::string abrev_, std::string hora_inicio_, std::string hora_fin_)
{
	id_periodo = id_periodo_;
	nombre = nombre_;
	abrev = abrev_;
	hora_inicio = hora_inicio_;
	hora_fin = hora_fin_;
}

int Periodo::getIdPeriodo()
{
	return id_periodo;
}

std::string Periodo::getNombre()
{
	return nombre;
}

std::string Periodo::getAbrev()
{
	return abrev;
}

std::string Periodo::getHoraInicio()
{
	return hora_inicio;
}

std::string Periodo::getHoraFin()
{
	return hora_fin;
}
