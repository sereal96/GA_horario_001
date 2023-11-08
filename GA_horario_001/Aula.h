#pragma once

#include <string>

class Aula
{
public:
	Aula();
	~Aula();

	Aula(int id_aula_, std::string numero_, int capacidad_, std::string ubicacion_);
	int geIdAula();
	std::string getNumero();
	int getCapacidad();
	std::string getUbicacion();

private:
	int id_aula;
	std::string numero;
	int capacidad;
	std::string ubicacion;
};

