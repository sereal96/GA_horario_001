#pragma once

#include <string>

class Materia
{
public:
	Materia();
	~Materia();

	Materia(int id_materia_, std::string nombre_, std::string nivel_, std::string grado_);
	int getIdMateria();
	std::string getNombre();
	std::string getNivel();
	std::string getGrado();

private:
	int id_materia;
	std::string nombre;
	std::string nivel;
	std::string grado;
};

