#include <ClasesPosix.h>

//Definir la clase Barrera
class Barrera {
	public:
		Barrera();
		Barrera(int tamano);
		void Sincronizar();
		void Resetear();
		void Resetear(int tamano);
	private:
		int tamanoMaximo;
		int hilosActuales;
		mutex_t mutex;
		variable_condicion_t condicion;
};

//Zona pública

	//Definir un constructor sin parámetros
	
	//Definir un constructor con un parámetro para indicar el número de hilos que se sincronizarán en la barrera
	
	/*Definir el método Sincronizar que bloqueará al hilo invocante en la barrera (no han llegado todos)
	o liberará a todos los hilos bloqueados (es el último hilo en llegar)*/
	
	//Definir el método Resetear sin parámetro para resetear la barrera
	
	//Definir el método Resetear con un parámetro entero para resetear la barrera cambiando el número de hilos
	
//Zona privada

	//Definir una variable entera para almacenar el número de hilos que deben llegar a la barrera antes de dejarlos pasar
	
	//Definir una variable entera para almacenar cuántos hilos han llegado ya a la barrera
	
	//Definir el mutex (usar la clase mutex_t)
	
	//Definir la variable de condición (usar la clase variable_condicion_t)
	
//Fin de la clase