#include <vector>
using namespace std;
#include <ClasesPosix.h>

class PilaAcotada {
private:
	vector<int> pila;
	int tamanioPila;
	mutex_t mutex;
	variable_condicion_t pilaVacia;
	variable_condicion_t pilaLlena;
public:
	PilaAcotada();
	PilaAcotada(int tamaño);
	void PilaAniadir(int valor);
	int PilaSacar();
};

//Definir la clase PilaAcotada

//Zona pública

	//Definir el constructor sin parámetros

	//Definir el constructor con un parámetro para indicar el tamaño máximo de la pila

	//Definir el método PilaAniadir con un parámetro de entrada de tipo entero

	//Definir el método PilaSacar sin parámetros y que retornará un valor entero

//Zona privada

	//Definir el vector pila de tipo entero (usar la case vector, ver el anexo 3 de la práctica)

	//Definir una variable entera para almacenar el tamaño máximo de la pila

	//Definir el mutex

	//Definir dos variables de condición para controlar que la pila esté llena o vacia

//Fin de la clase PilaAcotada
