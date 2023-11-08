#pragma once

#include <string>

class Grado
{
public:
	Grado();
	~Grado();

	Grado(int id_grado_, std::string nombre_, int id_nivel_);
	int getIdGrado();
	std::string getNombre();
	int getIdNivel();

private:
	int id_grado;
	std::string nombre;
	int id_nivel;
};

