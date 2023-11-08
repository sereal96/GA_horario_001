#pragma once

#include <string>

class Curso
{
public:
	Curso();
	~Curso();

	Curso(int id_curso_, std::string nombre_, int id_nivel_, int id_grado_);
	int getIdCurso();
	std::string getNombre();
	int getIdNivel();
	int getIdGrado();

private:
	int id_curso;
	std::string nombre;
	int id_nivel;
	int id_grado;
};

