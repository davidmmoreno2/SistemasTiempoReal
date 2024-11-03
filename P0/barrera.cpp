#include "barrera.h"

//Implementación del constructor sin parámetros

	//Inicializar el tamaño máximo de la barrera a 10 (llamar al constructor con un parámetro usando 10 como parámetro)
	
//Fin del constructor sin parámetros
Barrera::Barrera() {
	tamanoMaximo = 10;
	hilosActuales = 0;
	mutex.Inicializar();
	condicion.Inicializar();
}


//Implementación del constructor con un parámetro para indicar el tamaño máximo de la barrera

	//Inicializar el tamaño máximo de la barrera al valor introducido por parámetro
	
	//Inicializar el número de hilos actuales en la barrera a 0
	
	//Inicializar el mutex de la clase
	
	//Inicializar la variable de condición de la clase asociándole el manejador del mutex de la clase
	
//Fin del constructor con un parámetro
Barrera::Barrera(int tamano) {
	tamanoMaximo = tamano;
	hilosActuales = 0;
	mutex.Inicializar();
	condicion.Inicializar(mutex.ObtenerManejador());
}


/*Implementación del método Sincronizar. Este método bloqueará el hilo invocante en la barrera si no se ha alcanzado el número indicado
o liberará a todos los hilos si es el último hilo en llegar. Reseteará también la barrera, dejándola lista para  volver a utilizarla

	//Entrar en el mutex
	
	//Incrementar el número de hilos en la barrera
	
	//Si han llegado todos los hilos esperados
	
		//Liberar a todos los hilos de la variable de condición
		
		//Resetear la barrera
			
	//Si no
	
		//Bloquearse en la variable de condición
		
	//Liberar el mutex
	
//Fin del método Sincronizar*/
void Barrera::Sincronizar() {
	mutex.Lock();
	hilosActuales++;
	if (hilosActuales == tamanoMaximo) {
		condicion.Broadcast();
		Resetear();
	} else {
		condicion.Wait();
	}
	mutex.Unlock();
}


/*Implementación del método Resetear sin parámetros. Este método pondrá a cero el número de hilos que han llegado a la barrera.
Si no han llegado todos los hilos esperados a la barrera, no se realizará el reseteo de la misma (esto previene que se resetee la barrera antes de que lleguen todos los hilos)*/

	//Si han llegado a la barrera todos los hilos esperados
	
		//Poner a cero el contador de los hilos
		
//Fin del método Resetear sin parámetros*/
void Barrera::Resetear() {
	if (hilosActuales == tamanoMaximo) {
		hilosActuales = 0;
	}
}

/*Implementación del método Resetear con un parámetro. Este método pondrá a cero el número de hilos que han llegado a la barrera.
Si no han llegado todos los hilos esperados a la barrera, no se realizará el reseteo de la misma (esto previene que se resetee la barrera antes de que lleguen todos los hilos).
por último, cambiará el número de hilos por los que se esperará en la barrera*/

	//Si han llegado a la barrera todos los hilos esperados
	
		//Poner a cero el contador de los hilos
		
		//Cambiar el número de hilos por los que se esperará usando el parámetro de entrada del método
		
//Fin del método Resetear sin parámetros*/
void Barrera::Resetear(int tamano) {
	if (hilosActuales == tamanoMaximo) {
		hilosActuales = 0;
		tamanoMaximo = tamano;
	}
}
