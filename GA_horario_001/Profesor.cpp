#include "Profesor.h"

Profesor::Profesor()
{
}

Profesor::~Profesor()
{
}

Profesor::Profesor(int id_profesor_, std::string nombre_, std::string apellido_)
{
	id_profesor = id_profesor_;
	nombre = nombre_;
	apellido = apellido_;
}

int Profesor::getIdProfesor()
{
	return id_profesor;
}

std::string Profesor::getNombre()
{
	return nombre;
}

std::string Profesor::getApellido()
{
	return apellido;
}
