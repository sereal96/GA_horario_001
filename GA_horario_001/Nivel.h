#pragma once

#include <string>

class Nivel
{
public:
	Nivel();
	~Nivel();

	Nivel(int id_nivel_, std::string nombre_);
	int getIdNivel();
	std::string getNombre();
	

private:
	int id_nivel;
	std::string nombre;
};

