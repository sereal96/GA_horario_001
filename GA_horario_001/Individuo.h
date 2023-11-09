#pragma once

#include <vector>

#include "Herramientas.h"

struct categoria {
	std::string titulo;
	std::vector<int> codigo_genetico;
	std::string valor;
};

struct AuxAulaDiaHora
{
	std::string Aula;
	std::string Dia;
	std::string Hora;
};

struct AuxAulaHoraProfesor
{	
	std::string Dia;
	std::string Hora;
	std::string Profesor;
};

struct AuxAulaDiaHoraProfesor
{
	std::string Aula;
	std::string Dia;
	std::string Hora;
	std::string Profesor;
};

struct AuxProfesorPeriodo
{
	std::string id_profesor;
	std::string id_periodo;
	std::string ini_hora;
	std::string fin_hora;
};

//el individuo estara a nivel de "curso" ej:Yellow
class Individuo
{


public:
	Individuo();
	~Individuo();
	Individuo(std::vector<int> cromosoma_);
	double getAptitud();
	void calcularAptitud(int numero_de_dias, int numero_de_periodos, int numero_de_cursos, int numero_de_profesores,
		int numero_de_materias, int numero_de_aulas);
	void setAptitud(double aptitud_);

	/*
	Parámetros:
		- 
	Devuelve:
		
	Nota:
		
	*/
	std::vector<int> getCromosomaCurso();
	void crearCromosomaCurso(int cromosoma_curso_, int limite_superior_curso);
	void setCromosomaCurso(std::vector<int> cromosoma_curso_);

	std::vector<int> getCromosomaProfesor();
	void crearCromosomaProfesor(int cromosoma_profesor_, int limite_superior_profe);
	void setCromosomaProfesor(std::vector<int> cromosoma_profesor_);

	std::vector<int> getCromosomaMateria();
	void crearCromosomaMateria(int cromosoma_materia_, int limite_superior_mate);
	void setCromosomaMateria(std::vector<int> cromosoma_materia_);

	std::vector<int> getCromosomaDia();
	void crearCromosomaDia(int cromosoma_dia_, int limite_superior_dia);
	void setCromosomaDia(std::vector<int> cromosoma_dia_);

	std::vector<int> getCromosomaHora();
	void crearCromosomaHora(int cromosoma_hora_, int limite_superior_hora);
	void setCromosomaHora(std::vector<int> cromosoma_hora_);

	std::vector<int> getCromosomaAula();
	void crearCromosomaAula(int cromosoma_aula_, int limite_superior_aula);
	void setCromosomaAula(std::vector<int> cromosoma_aula_);


	std::vector<categoria> getGenomaS();
	categoria getGenomaS(int pos);
	void setGenomaS(int pos, categoria valor);
	int sizeGenomaS();
	

	void crearGenomaS(int numero_de_dias, int numero_de_periodos, int numero_de_cursos);
	void crearGenomaS(int numero_de_dias_, int numero_de_periodos_, int numero_de_cursos_,
					  int numero_de_profesores_, int numero_de_materias_, int numero_de_aulas_);
	void setGenomaS(std::vector<categoria> genomaS_);
	void setCromosomaEnGenomaS(categoria cromosomaS_);
	categoria getCromosomaEnGenomaS(int posicionS_);

	
	void setPosicionDelCursoEnVector(int valor_);
	std::vector<int> getPosicionDelCursoEnVector();

	void setPosicionDelDiaEnVector(int valor_);
	std::vector<int> getPosicionDelDiaEnVector();

	void setPosicionDeHoraEnVector(int valor_);
	std::vector<int> getPosicionDeHoraEnVector();

	void setPosicionDelAulaEnVector(int valor_);
	std::vector<int> getPosicionDelAulaEnVector();

	int cantidadDeCursos();
	int cantidadDeCursosEntero();
	
	void setAptitudCurso(double aptitud_curso_);
	double getAptitudCurso();	

	void setAptitudProfesor(double aptitud_profesor_);
	double getAptitudProfesor();

	void setAptitudMateria(double aptitud_materia_);
	double getAptitudMateria();

	void setAptitudDia(double aptitud_dia_);
	double getAptitudDia();

	void setAptitudHora(double aptitud_hora_);
	double getAptitudHora();

	void setaptitudAula(double aptitud_aula_);
	double getaptitudAula();

	void setTodosLosProfesoryPeriodo(int numero_de_profesores_, int numero_de_dias_, int numero_de_periodos_);

	int cantidadDiaHoraAulaRepetidos(const categoria& objetivo_);

	bool saludCromosomasAula();
	bool saludCromosomasProfesor();
	bool saludCromosomasAulaDiaHoraProfesor();
	bool saludCromosomasProfesorPeriodo();

	void printindividuo();

	int calculaAptitudIndividuo();

	
	int getNumeroDeDias();
	int getNumeroDePeriodos();
	int getNumeroDeCursos();
	int getNumeroDeProfesores();
	int getNumeroDeMaterias();
	int getNumeroDeAulas();

	Herramientas h1;

	std::vector<std::string> esqueleto;
	std::vector<std::string> generado;
	double aptitud = -1;
private:
	//Genoma compuesto por cromosomas
	std::vector<int> cromosoma_curso; //Curso es el nombre
	std::vector<int> cromosoma_profesor;
	std::vector<int> cromosoma_materia;
	std::vector<int> cromosoma_dia;
	std::vector<int> cromosoma_hora;
	std::vector<int> cromosoma_aula; //Aula es el lugar fisico donde un curso se encuentra

	//std::vector<std::vector<int>> genoma;
	std::vector <categoria> genomaS;
	//double aptitud = -1;

	double aptitud_curso = -1;
	double aptitud_profesor = -1;
	double aptitud_materia = -1;
	double aptitud_dia = -1;
	double aptitud_hora = -1;
	double aptitud_aula = -1;
	
	int numero_de_dias;
	int numero_de_periodos;
	int numero_de_cursos;
	int numero_de_profesores;
	int numero_de_materias;
	int numero_de_aulas;
	
	
	//variables amigables para no calcular en el futuro
	std::vector<int> posicion_del_curso_en_vector;
	std::vector<int> posicion_del_dia_en_vector;
	std::vector<int> posicion_del_hora_en_vector;
	std::vector<int> posicion_del_aula_en_vector;
	

	std::vector<AuxProfesorPeriodo> listade_Profesor_Periodo;
};

