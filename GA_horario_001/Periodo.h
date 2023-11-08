#pragma once

#include <string>

class Periodo
{
public:
	Periodo();
	~Periodo();

	Periodo(int id_periodo_, std::string nombre_, std::string abrev_, std::string hora_inicio_, std::string hora_fin_);
	int getIdPeriodo();
	std::string getNombre();
	std::string getAbrev();
	std::string getHoraInicio();
	std::string getHoraFin();


private:
	int id_periodo;
	std::string nombre;
	std::string abrev;
	std::string hora_inicio;
	std::string hora_fin;
};

