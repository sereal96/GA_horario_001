#include "Individuo.h"
#include <algorithm>
#include <random>

bool operator==(const AuxAulaDiaHora& lhs, const AuxAulaDiaHora& rhs) {
	return lhs.Aula == rhs.Aula && lhs.Dia == rhs.Dia && lhs.Hora == rhs.Hora;
}

bool operator==(const AuxAulaHoraProfesor& lhs, const AuxAulaHoraProfesor& rhs) {
	return lhs.Profesor == rhs.Profesor && lhs.Dia == rhs.Dia && lhs.Hora == rhs.Hora;
}

bool operator==(const AuxAulaDiaHoraProfesor& lhs, const AuxAulaDiaHoraProfesor& rhs) {
	return lhs.Profesor == rhs.Profesor && lhs.Dia == rhs.Dia && lhs.Hora == rhs.Hora && lhs.Profesor == rhs.Profesor;
}

Individuo::Individuo()
{
}

Individuo::~Individuo()
{
}

Individuo::Individuo(std::vector<int> cromosoma_)
{
	//cromosoma = cromosoma_;
}

double Individuo::getAptitud()
{
	return aptitud;
}
/// <summary>
/// 
/// </summary>
/// <param name="numero_de_dias"></param>
/// <param name="numero_de_periodos"></param>
/// <param name="numero_de_cursos"></param>
/// <param name="numero_de_profesores"></param>
/// <param name="numero_de_materias"></param>
/// <param name="numero_de_aulas"></param>
void Individuo::calcularAptitud(int numero_de_dias, int numero_de_periodos, int numero_de_cursos, int numero_de_profesores,
	int numero_de_materias, int numero_de_aulas)
{
	setAptitudCurso(1.0); //Siempre sera uno por ser un parametro controlado por la institucion


	/*
	double error_curso = 0.0;
	int fitnes_Curso = cantidadDeCursos();
	double aptitud_curso_aux = 1.0;
	if ((fitnes_Curso - numero_de_cursos)==0)
	{
		setAptitudCurso(1.0);
	}
	else
	{
		double aux = std::abs((fitnes_Curso - numero_de_cursos));
		error_curso = (100.0 / numero_de_cursos) * aux;
		setAptitudCurso(1.0 - (error_curso / 100.0));		
	}*/

	int fitnes_ideal_curso_x_dia_x_periodo = numero_de_cursos * numero_de_dias * numero_de_periodos; // 2x5x7 = 70

	//std::cout << "\n";
	for (const categoria& a : genomaS)
	{
		int valor = cantidadDiaHoraAulaRepetidos(a);
		//std::cout << valor << "\n";

	}

	


	int borrar = 0;

}

void Individuo::setAptitud(double aptitud_)
{
	aptitud = aptitud_;
}

std::vector<int> Individuo::getCromosomaCurso()
{
	return cromosoma_curso;
}

void Individuo::crearCromosomaCurso(int cromosoma_curso_, int limite_superior_curso)
{
	if (cromosoma_curso_ <= limite_superior_curso)
	{
		this->setCromosomaCurso(h1.combierteEnteroBinario8Bits(cromosoma_curso_));
	}
	else
	{
		std::cout << "error supera al limite";
	}
}

void Individuo::setCromosomaCurso(std::vector<int> cromosoma_curso_)
{
	cromosoma_curso = cromosoma_curso_;
}

std::vector<int> Individuo::getCromosomaProfesor()
{
	return cromosoma_profesor;
}

void Individuo::crearCromosomaProfesor(int cromosoma_profesor_, int limite_superior_profe)
{
	if (cromosoma_profesor_ <= limite_superior_profe)
	{
		this->setCromosomaProfesor(h1.combierteEnteroBinario8Bits(cromosoma_profesor_));
	}
	else
	{
		std::cout << "error supera al limite";
	}
}

void Individuo::setCromosomaProfesor(std::vector<int> cromosoma_profesor_)
{
	cromosoma_profesor = cromosoma_profesor_;
}

std::vector<int> Individuo::getCromosomaMateria()
{
	return cromosoma_materia;
}

void Individuo::crearCromosomaMateria(int cromosoma_materia_, int limite_superior_mate)
{
	if (cromosoma_materia_ <= limite_superior_mate)
	{
		this->setCromosomaMateria(h1.combierteEnteroBinario8Bits(cromosoma_materia_));
	}
	else
	{
		std::cout << "error supera al limite";
	}
}

void Individuo::setCromosomaMateria(std::vector<int> cromosoma_materia_)
{
	cromosoma_materia = cromosoma_materia_;
}

std::vector<int> Individuo::getCromosomaDia()
{
	return cromosoma_dia;
}

void Individuo::crearCromosomaDia(int cromosoma_dia_, int limite_superior_dia)
{
	if (cromosoma_dia_ <= limite_superior_dia)
	{
		this->setCromosomaDia(h1.combierteEnteroBinario8Bits(cromosoma_dia_));
	}
	else
	{
		std::cout << "error supera al limite";
	}
}

void Individuo::setCromosomaDia(std::vector<int> cromosoma_dia_)
{
	cromosoma_dia = cromosoma_dia_;
}

std::vector<int> Individuo::getCromosomaHora()
{
	return cromosoma_hora;
}

void Individuo::crearCromosomaHora(int cromosoma_hora_, int limite_superior_hora)
{
	if (cromosoma_hora_ <= limite_superior_hora)
	{
		this->setCromosomaHora(h1.combierteEnteroBinario8Bits(cromosoma_hora_));
	}
	else
	{
		std::cout << "error supera al limite";
	}
}

void Individuo::setCromosomaHora(std::vector<int> cromosoma_hora_)
{
	cromosoma_hora = cromosoma_hora_;
}

std::vector<int> Individuo::getCromosomaAula()
{
	return cromosoma_aula;
}

void Individuo::crearCromosomaAula(int cromosoma_aula_, int limite_superior_aula)
{
	if (cromosoma_aula_ <= limite_superior_aula)
	{
		this->setCromosomaAula(h1.combierteEnteroBinario8Bits(cromosoma_aula_));
	}
	else
	{
		std::cout << "error supera al limite";
	}
}

void Individuo::setCromosomaAula(std::vector<int> cromosoma_aula_)
{
	cromosoma_aula = cromosoma_aula_;
}

/*
std::vector<std::vector<int>> Individuo::getGenoma()
{
	return genoma;
}

void Individuo::crearGenoma(int numero_de_dias, int numero_de_periodos, int numero_de_cursos)
{
	int cantidad_cromosomas = numero_de_dias * numero_de_periodos;// *numero_de_cursos;

	//crearCromosomaCurso(10, 18);
	//h1.printVectBinario(i1.getCromosomaCurso());

	for (int nc = 0; nc < numero_de_cursos; nc++)
	{
		int datosCurso = rand() % 20 + 1;;
		int limitiCurso = rand() % 20 + 1;;
		crearCromosomaCurso(datosCurso, limitiCurso);
		std::vector<int> cromoCursoAux = getCromosomaCurso();

		setCromosomaEnGenoma(cromoCursoAux);
		for (int i = 0; i < cantidad_cromosomas; i++)
		{
			crearCromosomaAula(14, 18);
			std::vector<int> cromoAulaAux = getCromosomaAula();
			setCromosomaEnGenoma(cromoAulaAux);			

			crearCromosomaDia(5, 18);
			std::vector<int> cromoDiaAux = getCromosomaDia();
			setCromosomaEnGenoma(cromoDiaAux);

			crearCromosomaHora(8, 18);
			std::vector<int> cromoHoraAux = getCromosomaHora();
			setCromosomaEnGenoma(cromoHoraAux);

			crearCromosomaMateria(9, 18);
			std::vector<int> cromoMateriaAux = getCromosomaMateria();
			setCromosomaEnGenoma(cromoMateriaAux);

			crearCromosomaProfesor(9, 18);
			std::vector<int> cromoProfesorAux = getCromosomaProfesor();
			setCromosomaEnGenoma(cromoProfesorAux);
		}
	}

	/*
	for (int i = 0; i < cantidad_cromosomas; i++)
	{
		i1.crearCromosomaCurso(10, 18);
		h1.printVectBinario(i1.getCromosomaCurso());
	}
	*/
//}


/*
void Individuo::setGenoma(std::vector<std::vector<int>> genoma_)
{
	genoma = genoma_;
}

void Individuo::setCromosomaEnGenoma(std::vector<int> cromosoma_)
{
	genoma.push_back(cromosoma_);
}

std::vector<int> Individuo::getCromosomaEnGenoma(int posicion_)
{
	if (posicion_ >= 0)
	{
		return genoma[posicion_];
	}
	return std::vector<int>();
}
*/


std::vector<categoria> Individuo::getGenomaS()
{
	return genomaS;
}

categoria Individuo::getGenomaS(int pos)
{
	return genomaS[pos];
}

void Individuo::crearGenomaS(int numero_de_dias, int numero_de_periodos, int numero_de_cursos)
{
	int cantidad_cromosomas = numero_de_dias * numero_de_periodos;// *numero_de_cursos;

	//crearCromosomaCurso(10, 18);
	//h1.printVectBinario(i1.getCromosomaCurso());

	for (int nc = 0; nc < numero_de_cursos; nc++)
	{
		int datosCurso = rand() % 20 + 1;;
		int limitiCurso = rand() % 20 + 1;;
		crearCromosomaCurso(datosCurso, limitiCurso);
		std::vector<int> cromoCursoAux = getCromosomaCurso();

		categoria c1;
		c1.titulo = "Curso";
		c1.codigo_genetico = cromoCursoAux;
		c1.valor = std::to_string(datosCurso); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
		setCromosomaEnGenomaS(c1);
		for (int i = 0; i < cantidad_cromosomas; i++)
		{
			crearCromosomaAula(14, 18);
			std::vector<int> cromoAulaAux = getCromosomaAula();
			categoria c2;
			c2.titulo = "Aula";
			c2.codigo_genetico = cromoAulaAux;
			c2.valor = std::to_string(14); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
			setCromosomaEnGenomaS(c2);

			crearCromosomaDia(5, 18);
			std::vector<int> cromoDiaAux = getCromosomaDia();
			categoria c3;
			c3.titulo = "Dia";
			c3.codigo_genetico = cromoDiaAux;
			c3.valor = std::to_string(5); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
			setCromosomaEnGenomaS(c3);

			crearCromosomaHora(8, 18);
			std::vector<int> cromoHoraAux = getCromosomaHora();
			categoria c4;
			c4.titulo = "Hora";
			c4.codigo_genetico = cromoHoraAux;
			c4.valor = std::to_string(8); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
			setCromosomaEnGenomaS(c4);

			crearCromosomaMateria(9, 18);
			std::vector<int> cromoMateriaAux = getCromosomaMateria();
			categoria c5;
			c5.titulo = "Materia";
			c5.codigo_genetico = cromoMateriaAux;
			c5.valor = std::to_string(9); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
			setCromosomaEnGenomaS(c5);

			crearCromosomaProfesor(9, 18);
			std::vector<int> cromoProfesorAux = getCromosomaProfesor();
			categoria c6;
			c6.titulo = "Profesor";
			c6.codigo_genetico = cromoProfesorAux;
			c6.valor = std::to_string(9); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
			setCromosomaEnGenomaS(c6);
		}
	}

}

void Individuo::crearGenomaS(int numero_de_dias_, int numero_de_periodos_, int numero_de_cursos_, int numero_de_profesores_, 
	int numero_de_materias_, int numero_de_aulas_)
{
	setTodosLosProfesoryPeriodo(numero_de_profesores_, numero_de_dias_, numero_de_periodos_);

	numero_de_dias = numero_de_dias_;
	numero_de_periodos = numero_de_periodos_;
	numero_de_cursos = numero_de_cursos_;
	numero_de_profesores = numero_de_profesores_;
	numero_de_materias = numero_de_materias_;
	numero_de_aulas = numero_de_aulas_;

	//Genera una semillar basada en fecha,hora,minuto y segundo
	std::time_t tiempoActual = std::time(0);
	std::tm tiempoInfo;
	// Usar std::localtime_s para obtener la información de tiempo actual
	localtime_s(&tiempoInfo, &tiempoActual);
	unsigned int semilla = tiempoInfo.tm_sec + tiempoInfo.tm_min * 60 + tiempoInfo.tm_hour * 3600 +
		tiempoInfo.tm_mday * 86400 + (tiempoInfo.tm_mon + 1) * 2592000 + (tiempoInfo.tm_year + 1900) * 31104000;
	srand(semilla);




	int cantidad_cromosomas = numero_de_dias * numero_de_periodos;// *numero_de_cursos;

	int posv = 0;
	bool saludAula = false;
	bool saludProfesor = false;
	bool saludAulaProfesor = false;

	bool saludDiaPeriodoAula = false;

	bool saludProfesorPeriodo = false;

	int ContLimite = 0;
	std::vector<int> dia_x_periodo;
	int resCorrect = 0;
	while (resCorrect < 5) //!saludAula & !saludProfesor & !saludAulaProfesor & !saludDiaPeriodoAula & !saludProfesorPeriodo)//!saludAula && 
	{
		posv = 0;
		genomaS.clear();
		posicion_del_curso_en_vector.clear();
		posicion_del_dia_en_vector.clear();
		posicion_del_hora_en_vector.clear();
		posicion_del_aula_en_vector.clear();
		dia_x_periodo.clear();
		for (int nc = 0; nc < numero_de_cursos; nc++)
		{
			int datosCurso = nc + 1;// rand() % numero_de_cursos + 1;
			int limitiCurso = numero_de_cursos; // rand() % 20 + 1;
			crearCromosomaCurso(datosCurso, limitiCurso);
			std::vector<int> cromoCursoAux = getCromosomaCurso();

			categoria c1;
			c1.titulo = "Curso";
			c1.codigo_genetico = cromoCursoAux;
			c1.valor = std::to_string(datosCurso); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
			setCromosomaEnGenomaS(c1);

			setPosicionDelCursoEnVector(posv);
			
			for (int i = 0; i < cantidad_cromosomas; i++)
			{
				//lugar fisico donde se pasan clases
				int datosAula = rand() % numero_de_aulas + 1;
				int limitiAulas = numero_de_aulas; // rand() % 20 + 1;
				crearCromosomaAula(datosAula, limitiAulas);
				std::vector<int> cromoAulaAux = getCromosomaAula();
				categoria c2;
				c2.titulo = "Aula";
				c2.codigo_genetico = cromoAulaAux;
				c2.valor = std::to_string(datosAula); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
				setCromosomaEnGenomaS(c2);
				posv++;
				setPosicionDelAulaEnVector(posv);

				int datosDias = rand() % numero_de_dias + 1;
				int limitiDias = numero_de_dias; // rand() % 20 + 1;
				crearCromosomaDia(datosDias, limitiDias);
				std::vector<int> cromoDiaAux = getCromosomaDia();
				categoria c3;
				c3.titulo = "Dia";
				c3.codigo_genetico = cromoDiaAux;
				c3.valor = std::to_string(datosDias); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
				setCromosomaEnGenomaS(c3);
				posv++;
				setPosicionDelDiaEnVector(posv);

				int datosPeriodos = rand() % numero_de_periodos + 1;
				int limitiPeriodos = numero_de_periodos; // rand() % 20 + 1;
				crearCromosomaHora(datosPeriodos, limitiPeriodos);
				std::vector<int> cromoHoraAux = getCromosomaHora();
				categoria c4;
				c4.titulo = "Hora";
				c4.codigo_genetico = cromoHoraAux;
				c4.valor = std::to_string(datosPeriodos); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
				setCromosomaEnGenomaS(c4);
				posv++;
				setPosicionDeHoraEnVector(posv);

				std::string fecha = c2.valor + c3.valor + c4.valor;
				int fecha_aux = std::stoi(fecha);
				dia_x_periodo.push_back(fecha_aux);

				//cantidad de materias que puede dar el colegio
				int datosMaterias = rand() % numero_de_materias + 1;
				int limitiMaterias = numero_de_materias; // rand() % 20 + 1;
				crearCromosomaMateria(datosMaterias, limitiMaterias);
				std::vector<int> cromoMateriaAux = getCromosomaMateria();
				categoria c5;
				c5.titulo = "Materia";
				c5.codigo_genetico = cromoMateriaAux;
				c5.valor = std::to_string(datosMaterias); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
				setCromosomaEnGenomaS(c5);
				posv++;
				//int datosProfesores = rand() % numero_de_profesores + 1;
				
				//////////////////////////////////////////////////////////
				int datosProfesores = -1;
				bool swPr = true;
				AuxProfesorPeriodo encontrado;
				std::string id_buscado = "";
				while (swPr)
				{
					datosProfesores = rand() % numero_de_profesores + 1;
					id_buscado = std::to_string(datosProfesores);
					
					// Buscar el elemento con id_profesor = "125"
					for (const auto& elemento : listade_Profesor_Periodo)
					{
						if (elemento.id_profesor == id_buscado)
						{
							encontrado = elemento;
							break; // Salir del bucle si se encuentra el elemento
						}
					}
					if ((std::stoi(encontrado.ini_hora) <= datosPeriodos) & (datosPeriodos <= std::stoi(encontrado.fin_hora)))
					{
						swPr = false;
					}
				}
				//////////////////////////////////////////////////////////

				int limitiProfesores = numero_de_profesores; // rand() % 20 + 1;
				crearCromosomaProfesor(datosProfesores, limitiProfesores);
				std::vector<int> cromoProfesorAux = getCromosomaProfesor();
				categoria c6;
				c6.titulo = "Profesor";
				c6.codigo_genetico = cromoProfesorAux;
				c6.valor = std::to_string(datosProfesores); //Nota es el valor que se usa en crearCromosoalXXX( 'valor' , Limte)
				setCromosomaEnGenomaS(c6);
				posv++;
			}
			posv++;
		}

		const auto duplicate = std::adjacent_find(dia_x_periodo.begin(), dia_x_periodo.end());
		if (duplicate != dia_x_periodo.end())
		{
			//std::cout << "Elemento duplicado = " << *duplicate << "\n";
			saludDiaPeriodoAula = false;
		}
		else
		{
			saludDiaPeriodoAula = true;
		}
			


		//calcularAptitud(numero_de_dias, numero_de_periodos, numero_de_cursos, numero_de_profesores, numero_de_materias, numero_de_aulas);
		saludAula = saludCromosomasAula();
		saludProfesor = saludCromosomasProfesor();
		saludAulaProfesor = saludCromosomasAulaDiaHoraProfesor();
		saludProfesorPeriodo = saludCromosomasProfesorPeriodo();
		
		resCorrect = 0;
		if (saludAula) { 
			resCorrect++; 
		}
		if (saludProfesor) { 
			resCorrect++; 
		}
		if (saludAulaProfesor) { 
			resCorrect++; 
		}
		if (saludProfesorPeriodo) { 
			resCorrect++; 
		}
		if (saludDiaPeriodoAula) { 
			resCorrect++; 
		}

		if (saludAula)// == 1)
		{
			int sss = 0;
		}

		if (saludProfesor)// == 2)
		{
			int sss = 0;
		}

		if (saludAulaProfesor)// == 3)
		{
			int sss = 0;
		}

		if (saludProfesorPeriodo)// == 4)
		{
			int sss = 0;
		}

		ContLimite++;
		//std::cout << ContLimite;
		if (ContLimite >= 2500)
		{
			break;
		}
	}
	int borrar = 0;
}

void Individuo::setGenomaS(std::vector<categoria> genomaS_)
{
	genomaS = genomaS_;
}

void Individuo::setCromosomaEnGenomaS(categoria cromosomaS_)
{
	genomaS.push_back(cromosomaS_);
}

categoria Individuo::getCromosomaEnGenomaS(int posicionS_)
{
	if (posicionS_ >= 0)
	{
		return genomaS[posicionS_];
	}	
	return categoria();
}

void Individuo::setPosicionDelCursoEnVector(int valor_)
{
	posicion_del_curso_en_vector.push_back(valor_);
}

std::vector<int> Individuo::getPosicionDelCursoEnVector()
{
	return posicion_del_curso_en_vector;
}

void Individuo::setPosicionDelDiaEnVector(int valor_)
{
	posicion_del_dia_en_vector.push_back(valor_);
}

std::vector<int> Individuo::getPosicionDelDiaEnVector()
{
	return posicion_del_dia_en_vector;
}

void Individuo::setPosicionDeHoraEnVector(int valor_)
{
	posicion_del_hora_en_vector.push_back(valor_);
}

std::vector<int> Individuo::getPosicionDeHoraEnVector()
{
	return posicion_del_hora_en_vector;
}

void Individuo::setPosicionDelAulaEnVector(int valor_)
{
	posicion_del_aula_en_vector.push_back(valor_);
}

std::vector<int> Individuo::getPosicionDelAulaEnVector()
{
	return posicion_del_aula_en_vector;
}

int Individuo::cantidadDeCursos()
{
	std::vector<int> posAux = getPosicionDelCursoEnVector();
	int sum = 0;
	int num = 0;
	for (int i = 0; i < posAux.size(); i++)
	{
		categoria cateAux = getGenomaS(posAux[i]);		
		num = std::stoi(cateAux.valor);
		sum = sum + num;
	}
	return sum;
}

int Individuo::cantidadDeCursosEntero()
{
	std::vector<int> posAux = getPosicionDelCursoEnVector();
	int sum = 0;
	int num = 0;
	for (int i = 0; i < posAux.size(); i++)
	{
		categoria cateAux = getGenomaS(posAux[i]);
		num = std::stoi(cateAux.valor);
		sum = sum + num;
	}
	return sum;
}

void Individuo::setAptitudCurso(double aptitud_curso_)
{
	aptitud_curso = aptitud_curso_;
}

double Individuo::getAptitudCurso()
{
	return aptitud_curso;
}

void Individuo::setAptitudDia(double aptitud_dia_)
{
	aptitud_dia = aptitud_dia_;
}

double Individuo::getAptitudDia()
{
	return aptitud_dia;
}

void Individuo::setAptitudHora(double aptitud_hora_)
{
	aptitud_hora = aptitud_hora_;
}

double Individuo::getAptitudHora()
{
	return aptitud_hora;
}

int Individuo::cantidadDiaHoraAulaRepetidos(const categoria& objetivo_)
{
	int count = 0;

	for (const categoria& c : genomaS) 
	{
		if (c.codigo_genetico == objetivo_.codigo_genetico && c.titulo == objetivo_.titulo && c.valor == objetivo_.valor) 
		{
			count++;
		}
	}
	return count;
}


/*struct AuxProfesorPeriodo
{
	std::string id_profesor;
	std::string id_periodo;
	std::string ini_hora;
	std::string fin_hora;
};*/


void Individuo::setTodosLosProfesoryPeriodo(int numero_de_profesores_, int numero_de_dias_, int numero_de_periodos_)
{
	//con esta funcion se crea la lista con los datos de la tabla "profesor_periodo"
	//en este caso se usar datos fabricados
	//Hay que llenar esto con datos de la BD

	int numero_periodos = numero_de_dias_ * numero_de_periodos_;
	
	for (int i = 0; i < numero_de_profesores_; i++)
	{
		int aux = (rand() % numero_de_periodos_) + 1;

		int ini_hora = 1;
		int fin_hora = 0;

		//while (ini_hora >= fin_hora)
		//{
		//	ini_hora = (rand() % numero_de_periodos_) + 1;
		//	fin_hora = (rand() % numero_de_periodos_) + 1;
		//}
		ini_hora = 1;
		fin_hora = numero_de_periodos_;
		AuxProfesorPeriodo ProfesorPeriodo;
		ProfesorPeriodo.id_profesor = std::to_string(i+1);
		ProfesorPeriodo.ini_hora = std::to_string(ini_hora);
		ProfesorPeriodo.fin_hora = std::to_string(fin_hora);
		ProfesorPeriodo.id_periodo = "0";
		listade_Profesor_Periodo.push_back(ProfesorPeriodo);
	}

	int test = 0;
	

}



bool Individuo::saludCromosomasAula()
{
	std::vector<AuxAulaDiaHora> vector_AuxAulaDiaHora;

	for (size_t i = 0; i < posicion_del_aula_en_vector.size()-1; ++i) 
	{
		if (genomaS[i].titulo == "Aula")
		{
			if (genomaS[i+1].titulo == "Dia")
			{
				if (genomaS[i + 2].titulo == "Hora")
				{
					AuxAulaDiaHora aux;
					aux.Aula = genomaS[i+0].valor;
					aux.Dia = genomaS[i+1].valor;
					aux.Hora = genomaS[i+2].valor;
					vector_AuxAulaDiaHora.push_back(aux);
				}
			}
		}		
	}

	std::vector<AuxAulaDiaHora> repeatedElements;

	for (size_t i = 0; i < vector_AuxAulaDiaHora.size(); ++i) 
	{
		for (size_t j = i + 1; j < vector_AuxAulaDiaHora.size(); ++j) 
		{
			if (vector_AuxAulaDiaHora[i] == vector_AuxAulaDiaHora[j]) 
			{
				repeatedElements.push_back(vector_AuxAulaDiaHora[i]);
				break; // No need to keep looking for more duplicates of this element.
			}
		}
	}

	if (!repeatedElements.empty()) 
	{
		//std::cout << " Se encontraron Aulas en la misma hora, dia y curso repetidos:" << std::endl;
		//for (const AuxAulaDiaHora& element : repeatedElements) {
		//	std::cout << "a: " << element.Aula << ", b: " << element.Dia << ", c: " << element.Hora << std::endl;
		//}
		return false;
	}
	else 
	{
		//std::cout << "No tiene elementos repetidos (hora, dia y curso)." << std::endl;
	}
	return true;
}

bool Individuo::saludCromosomasProfesor()
{
	std::vector<AuxAulaHoraProfesor> vector_AuxAulaHoraProfesor;

	for (size_t i = 0; i < posicion_del_aula_en_vector.size() - 1; ++i)
	{
		if (genomaS[i].titulo == "Aula")
		{
			if (genomaS[i + 1].titulo == "Dia")
			{
				if (genomaS[i + 2].titulo == "Hora")
				{
					if (genomaS[i + 4].titulo == "Profesor")
					{
						AuxAulaHoraProfesor aux;
						
						aux.Dia = genomaS[i + 1].valor;
						aux.Hora = genomaS[i + 2].valor;
						aux.Profesor = genomaS[i + 4].valor;
						vector_AuxAulaHoraProfesor.push_back(aux);
					}
					
				}
			}
		}
	}

	std::vector<AuxAulaHoraProfesor> repeatedElements;

	for (size_t i = 0; i < vector_AuxAulaHoraProfesor.size(); ++i) 
	{
		for (size_t j = i + 1; j < vector_AuxAulaHoraProfesor.size(); ++j) 
		{
			if (vector_AuxAulaHoraProfesor[i] == vector_AuxAulaHoraProfesor[j]) 
			{
				repeatedElements.push_back(vector_AuxAulaHoraProfesor[i]);
				break; // No need to keep looking for more duplicates of this element.
			}
		}
	}

	if (!repeatedElements.empty()) 
	{
		//std::cout << " Se encontraron Aulas en la misma hora, dia y Profesor repetidos:" << std::endl;
		//for (const AuxAulaDiaHora& element : repeatedElements) {
		//	std::cout << "a: " << element.Aula << ", b: " << element.Dia << ", c: " << element.Hora << std::endl;
		//}
		return false;
	}
	else {
		//std::cout << "No tiene elementos repetidos (hora, dia y Profesor)." << std::endl;
	}
	return true;
}

bool Individuo::saludCromosomasAulaDiaHoraProfesor()
{
	std::vector<AuxAulaDiaHoraProfesor> vector_AulaDiaHoraProfesor;

	for (size_t i = 0; i < posicion_del_aula_en_vector.size() - 1; ++i)
	{
		if (genomaS[i].titulo == "Aula")
		{
			if (genomaS[i + 1].titulo == "Dia")
			{
				if (genomaS[i + 2].titulo == "Hora")
				{
					if (genomaS[i + 4].titulo == "Profesor")
					{
						AuxAulaDiaHoraProfesor aux;

						aux.Aula = genomaS[i + 0].valor;
						aux.Dia = genomaS[i + 1].valor;
						aux.Hora = genomaS[i + 2].valor;					

						aux.Profesor = genomaS[i + 4].valor;
						vector_AulaDiaHoraProfesor.push_back(aux);
					}

				}
			}
		}
	}

	std::vector<AuxAulaDiaHoraProfesor> repeatedElements;

	for (size_t i = 0; i < vector_AulaDiaHoraProfesor.size(); ++i)
	{
		for (size_t j = i + 1; j < vector_AulaDiaHoraProfesor.size(); ++j) 
		{
			if (vector_AulaDiaHoraProfesor[i] == vector_AulaDiaHoraProfesor[j]) 
			{
				repeatedElements.push_back(vector_AulaDiaHoraProfesor[i]);
				break; // No need to keep looking for more duplicates of this element.
			}
		}
	}

	if (!repeatedElements.empty()) 
	{
		//std::cout << " Se encontraron Aulas en la misma hora, dia, aula y Profesor repetidos:" << std::endl;
		//for (const AuxAulaDiaHora& element : repeatedElements) {
		//	std::cout << "a: " << element.Aula << ", b: " << element.Dia << ", c: " << element.Hora << std::endl;
		//}
		return false;
	}
	else 
	{
		//std::cout << "No tiene elementos repetidos (hora, dia, aula y Profesor)." << std::endl;
	}
	return true;
}

bool Individuo::saludCromosomasProfesorPeriodo()
{
	//listade_Profesor_Periodo;

	std::vector<AuxAulaDiaHoraProfesor> vector_AulaDiaHoraProfesor;

	int profesor_fuera_horario = 0;

	for (size_t i = 0; i < posicion_del_aula_en_vector.size() - 1; ++i)
	{
		if (genomaS[i].titulo == "Aula")
		{
			if (genomaS[i + 1].titulo == "Dia")
			{
				if (genomaS[i + 2].titulo == "Hora")
				{
					if (genomaS[i + 4].titulo == "Profesor")
					{
						AuxAulaDiaHoraProfesor aux;

						aux.Aula = genomaS[i + 0].valor;
						aux.Dia = genomaS[i + 1].valor;
						aux.Hora = genomaS[i + 2].valor;

						aux.Profesor = genomaS[i + 4].valor;
						vector_AulaDiaHoraProfesor.push_back(aux);

						std::string id_buscado = genomaS[i + 4].valor;
						AuxProfesorPeriodo encontrado;
						// Buscar el elemento con id_profesor = "125"
						for (const auto& elemento : listade_Profesor_Periodo) 
						{
							if (elemento.id_profesor == id_buscado) 
							{
								encontrado = elemento;
								break; // Salir del bucle si se encuentra el elemento
							}
						}
						if ( (std::stoi(encontrado.ini_hora) <= std::stoi(aux.Hora)) & 
							 (std::stoi(aux.Hora) <= std::stoi(encontrado.fin_hora)) )
						{
							profesor_fuera_horario++;
						}

					}

				}
			}
		}
	}

	if (profesor_fuera_horario > 0)
	{
		//std::cout << " Se encontro un choque fuera de horario de un profesor" << std::endl;		
		return false;
	}
	else
	{
		//std::cout << " No hay fuera de horario" << std::endl;
		return true;
	}
	
	return true;
}

void Individuo::printindividuo()
{
	
	std::cout << "\n";
	std::cout << "\n";

	std::vector<std::vector <std::vector<categoria>>> cursos;	
	for (int nc = 0; nc < numero_de_cursos; nc++)
	{		
		std::vector <std::vector<categoria>> semanas;
		for (int np = 0; np < numero_de_periodos; np++)
		{
			std::vector<categoria> num_horas;
			for (int nd = 0; nd < numero_de_dias; nd++)
			{
				categoria ct;
				ct.titulo = "dia = " + std::to_string(nd) + " - periodo = " + std::to_string(np);
				ct.valor = "dia = " + std::to_string(nd) + " - periodo = " + std::to_string(np);
				num_horas.push_back(ct);
			}
			semanas.push_back(num_horas);
		}
		cursos.push_back(semanas);
	}

	std::vector<std::vector <std::vector<categoria>>> cursosAux;
	cursosAux = cursos;

	int curso_aux = 0;
	for (int pos_Curso : posicion_del_curso_en_vector)
	{
		std::cout << "pos_Curso = "<<std::to_string(pos_Curso) << "\n";


		for (int i = 0; i < posicion_del_curso_en_vector[1] -1;i=i+5 )
		{
			categoria c0 = genomaS[pos_Curso + i + 1]; //Aula
			categoria c1 = genomaS[pos_Curso + i + 2]; //Dia
			categoria c2 = genomaS[pos_Curso + i + 3]; //Hora
			categoria c3 = genomaS[pos_Curso + i + 4]; //Materia
			categoria c4 = genomaS[pos_Curso + i + 5]; //Profesor

			std::cout << std::to_string(i) <<"---"<< c0.titulo << c0.valor << "  " << c1.titulo << c1.valor << "  " << c2.titulo << c2.valor << "  " << c3.titulo << c3.valor << "  " << c4.titulo << c4.valor << "\n";			
			//aula , periodo dia
			cursos[curso_aux][std::stoi(c2.valor)-1][std::stoi(c1.valor)-1].titulo = "____________" + c0.valor + " " + c1.valor + " " + c2.valor + " " + c3.valor + " " + c4.valor;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			for (int c0i = 0; c0i < c0.codigo_genetico.size(); c0i++)
			{
				esqueleto.push_back(std::to_string(c0.codigo_genetico[c0i]));
			}
			esqueleto.push_back("-");
			for (int c0i = 0; c0i < c1.codigo_genetico.size(); c0i++)
			{
				esqueleto.push_back(std::to_string(c1.codigo_genetico[c0i]));
			}
			esqueleto.push_back("-");
			for (int c0i = 0; c0i < c2.codigo_genetico.size(); c0i++)
			{
				esqueleto.push_back(std::to_string(c2.codigo_genetico[c0i]));
			}
			esqueleto.push_back("-");
			for (int c0i = 0; c0i < c3.codigo_genetico.size(); c0i++)
			{
				esqueleto.push_back(std::to_string(c3.codigo_genetico[c0i]));
			}
			esqueleto.push_back("-");
			for (int c0i = 0; c0i < c4.codigo_genetico.size(); c0i++)
			{
				esqueleto.push_back(std::to_string(c4.codigo_genetico[c0i]));
			}
			esqueleto.push_back("-");
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		}
		curso_aux++;
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";
	}

	int contT = 1;
	for (int nc = 0; nc < numero_de_cursos; nc++)
	{
		std::cout << "\n \n ----------CURSO  " + std::to_string(nc) + "---------\n";
		for (int np = 0; np < numero_de_periodos; np++)
		{
			//std::vector<categoria> num_horas;
			std::string aux_linea_semana = "";
			std::string aux_punteada = "";
			for (int nd = 0; nd < numero_de_dias; nd++)
			{;
				aux_linea_semana = aux_linea_semana +  cursos[nc][np][nd].titulo + "  ||  ";
				aux_punteada = aux_punteada + "----------------------------";
			}
			std::cout << aux_punteada << "\n";
			std::cout << aux_linea_semana << "\n";
		}
	}
}

int Individuo::calculaAptitudIndividuo()
{
	std::vector<std::vector <std::vector<categoria>>> cursos;
	for (int nc = 0; nc < numero_de_cursos; nc++)
	{
		std::vector <std::vector<categoria>> semanas;
		for (int np = 0; np < numero_de_periodos; np++)
		{
			std::vector<categoria> num_horas;
			for (int nd = 0; nd < numero_de_dias; nd++)
			{
				categoria ct;
				ct.titulo = "xx";
				ct.valor = "xx";
				num_horas.push_back(ct);
			}
			semanas.push_back(num_horas);
		}
		cursos.push_back(semanas);
	}

	std::vector<std::vector <std::vector<categoria>>> cursosAux;
	cursosAux = cursos;

	int curso_aux = 0;
	for (int pos_Curso : posicion_del_curso_en_vector)
	{
		//std::cout << "pos_Curso = " << std::to_string(pos_Curso) << "\n";
		for (int i = 0; i < posicion_del_curso_en_vector[1] - 1; i = i + 5)
		{
			categoria c0 = genomaS[pos_Curso + i + 1]; //Aula
			categoria c1 = genomaS[pos_Curso + i + 2]; //Dia
			categoria c2 = genomaS[pos_Curso + i + 3]; //Hora
			categoria c3 = genomaS[pos_Curso + i + 4]; //Materia
			categoria c4 = genomaS[pos_Curso + i + 5]; //Profesor


			//std::cout << std::to_string(i) << "---" << c0.titulo << c0.valor << "  " << c1.titulo << c1.valor << "  " << c2.titulo << c2.valor << "  " << c3.titulo << c3.valor << "  " << c4.titulo << c4.valor << "\n";
			//aula , periodo dia
			cursos[curso_aux][std::stoi(c2.valor) - 1][std::stoi(c1.valor) - 1].titulo = "____________" + c0.valor + " " + c1.valor + " " + c2.valor + " " + c3.valor + " " + c4.valor;
		}
		curso_aux++;
	}


	int contErrores = 0;
	for (int nc = 0; nc < numero_de_cursos; nc++)
	{
		//std::cout << "\n \n ----------CURSO  " + std::to_string(nc) + "---------\n";
		for (int np = 0; np < numero_de_periodos; np++)
		{
			//std::vector<categoria> num_horas;
			//std::string aux_linea_semana = "";
			//std::string aux_punteada = "";
			for (int nd = 0; nd < numero_de_dias; nd++)
			{
				//aux_linea_semana = aux_linea_semana + cursos[nc][np][nd].titulo + "  ||  ";
				if (cursos[nc][np][nd].titulo._Equal("xx"))
				{
					contErrores++;
				}
				//aux_punteada = aux_punteada + "----------------------------";
			}
		}
	}

	int aptitudColegio = (numero_de_cursos * numero_de_periodos * numero_de_dias) - contErrores;

	setAptitud(aptitudColegio);

	std::cout << "aptitud: " << std::to_string(aptitudColegio) <<" contErrores:" << std::to_string(contErrores) << "cantidad: " << std::to_string((numero_de_cursos * numero_de_periodos * numero_de_dias))<<"\n";
	return 0;
}
