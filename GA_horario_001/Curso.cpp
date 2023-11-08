#include "Curso.h"

Curso::Curso()
{
}

Curso::~Curso()
{
}

Curso::Curso(int id_curso_, std::string nombre_, int id_nivel_, int id_grado_)
{
	id_curso = id_curso_;
	nombre = nombre_;
	id_nivel = id_nivel_;
	id_grado = id_grado_;
}

int Curso::getIdCurso()
{
	return id_curso;
}

std::string Curso::getNombre()
{
	return nombre;
}

int Curso::getIdNivel()
{
	return id_nivel;
}

int Curso::getIdGrado()
{
	return id_grado;
}
