#include "pila_acotada.h"

PilaAcotada::PilaAcotada(){
	tamanioPila = 10;
	mutex.Inicializar();
	pilaVacia.Inicializar(mutex.ObtenerManejador());
	pilaLlena.Inicializar(mutex.ObtenerManejador());
}
//Implementación del constructor sin parámetros

	//Llamar al constructor con un parámetro usando 10 como parámetro

//Fin del constructor sin parámetros

PilaAcotada::PilaAcotada(int tamaño){
	tamanioPila = tamaño;
	mutex.Inicializar();
	pilaVacia.Inicializar(mutex.ObtenerManejador());
	pilaLlena.Inicializar(mutex.ObtenerManejador());
}
//Implementación del constructor con un parámetro para indicar el tamaño máximo de la pila

	//Inicializar el tamaño máximo de la pila con el parámetro de entrada del constructor

	//Inicializar el mutex de la clase
	
	//Inicializar las dos variables de condición de la clase
	
	//Asociar el mutex de la clase a las dos variables de condición de la clase. Para ello, hay que pasar el manejador del mutex al método AsociarManejadorMutex de las variables de condición

//fin del constructor con un parámetro

void PilaAcotada::PilaAniadir(int valor){
	mutex.Lock();
	while (pila.size() == tamanioPila){
		pilaLlena.Wait();
	}
	pila.push_back(valor);
	mutex.Unlock();
	pilaVacia.Signal();
}
//Implementación del método PilaAniadir con un parámetro de entrada de tipo entero

	//Acceder a la región crítica a través del mutex

	//Mientras la pila esté llena, bloquearse en la variable de condición de la pila llena

	//Añadir elem en la cima de la pila

	//Liberar el mutex

	//Liberar, al menos, un hilo de la variable de condición de la pila vacia

//Fin del método PilaAniadir

int PilaAcotada::PilaSacar(){
	mutex.Lock();
	while (pila.size() == 0){
		pilaVacia.Wait();
	}
	int elem = pila.back();
	pila.pop_back();
	mutex.Unlock();
	pilaLlena.Signal();
	return elem;
}
//Implementación del método PilaSacar sin parámetros y que retorna un entero

	//Acceder a la región crítica a través del mutex

	//Mientras la pila esté vacía, bloquearse en la variable de condición de la pila vacia

	//Definir una variable entera y guardar ahí el valor contenido en la cima de la pila

	//Eliminar el elemento contenido en la cima de la pila

	//Liberar el mutex

	//Liberar, al menos, un hilo de la variable de condición de la pila llena

	//Devolver el elemento leído

//Fin del método PilaSacar

