#pragma once

#include <string>

class Dia
{
public:
	Dia();
	~Dia();
	Dia(int id_dia_, std::string nombre_, std::string abrev_);
	
	int getIdDia();
	std::string getNombre();
	std::string getAbrev();

private:
	int id_dia = 0;
	std::string nombre = "";
	std::string abrev ="";
};

