#pragma once

#include <string>

class Profesor
{
public:
	Profesor();
	~Profesor();

	Profesor(int id_profesor_, std::string nombre_, std::string apellido_);
	int getIdProfesor();
	std::string getNombre();
	std::string getApellido();
	

private:
	int id_profesor;
	std::string nombre;
	std::string apellido;
};

