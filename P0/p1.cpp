#include "pila_acotada.h"
#include <stdio.h>

#define REPETICIONES 50
#define NUM_HILOS 5

void imprimir_lectura(int hilo, int elem){
	printf("El hilo %d ha leído el valor %d de la pila\n", hilo, elem);
}

void imprimir_escritura(int hilo, int elem){
	printf("El hilo %d ha añadido el valor %d a la pila\n", hilo, elem);
}

/*
Definir un tipo de datos DatosHilos_t que sea una estructura con dos campos:
- Identificador de hilo de puntero a hilo_t: este campo almacenará la dirección de memoria de la clase que almacena los datos del hilo para poder usarlos dentro de la función
- Pila acotada de tipo puntero a PilaAcotada: este campo servirá para que todos los hilos compartan la misma pila acotada (de ahí que sea un puntero)
Para definir un tipo se usa la palabra reservada typedef, mientras que para definir una estructura se usa la palabra reservada struct. Por tanto, para definir un
tipo estructura se deben incluir ambas palabras reservadas de la forma "typedef struct { campos de la estructura } NombreDelTipo;"
*/
typedef struct {
	hilo_t *hilo;
	PilaAcotada *pila;
}DatosHilos_t;


//Definir la función hilo_productor para la creación de hilos productores siguiendo el formato específico de este tipo de funciones (ver apuntes del tema 2 o el anexo de la práctica 1)

	//Definir una variable de tipo DatosHilos_t

	//Asignar el contenido del parámetro de entrada a la variable anterior siguiento la forma indicada en clase (ver apuntes del tema 2 o el anexo de la práctica 1)

	/*
	Llamar REPETICIONES veces al método PilaAniadir del campo relativo a la pila acotada mostrando un mensaje con el número que se introducirá y el identificador del hilo
	Como en la estructura DatosHilos_t los campos son punteros, para usar sus métodos usaremos '->' en lugar de '.'
	*/

//Fin hilo_productor
void *hilo_productor(void *aux){
	DatosHilos_t datos=*((DatosHilos_t*)aux);
	for (int i=0; i<REPETICIONES; i++) {
		datos.pila->PilaAniadir(i);
		imprimir_escritura(datos.hilo->ObtenerIdentificador(), i);
	}
	return NULL;
}


//Definir la función hilo_consumidor para la creación de hilos consumidores siguiendo el formato específico de este tipo de funciones (ver apuntes del tema 2 o el anexo de la práctica 1)

	//Definir una variable de tipo DatosHilos_t

	//Asignar el contenido del parámetro de entrada a la variable anterior siguiento la forma indicada en clase (ver apuntes del tema 2 o el anexo de la práctica 1)

	/*
	Llamar REPETICIONES veces al método PilaSacar del campo relativo a la pila acotada mostrando un mensaje con el número leído y el identificador del hilo
	Como en la estructura DatosHilos_t los campos son punteros, para usar sus métodos usaremos '->' en lugar de '.'
	*/

//Fin hilo_consumidor
void *hilo_consumidor(void *aux){
	DatosHilos_t datos=*((DatosHilos_t*)aux);
	for (int i=0; i<REPETICIONES; i++) {
		int elem = datos.pila->PilaSacar();
		imprimir_lectura(datos.hilo->ObtenerIdentificador(), elem);
	}
	return NULL;
}


int main (void) {
	//Definir una variable PilaAcotada inicializándola a 20
	PilaAcotada pila(20);

	//Definir dos vectores de tipo DatosHilos_t y de tamaño NUM_HILOS para almacenar los datos de los productores y de los consumidores (no usar la clase vector)
	DatosHilos_t productores[NUM_HILOS];
	DatosHilos_t consumidores[NUM_HILOS];

	//Crear dos vectores de tipo hilo_t y de tamaño NUM_HILOS para almacenar los objetos hilo_t de los productores y de los consumidores (no usar la clase vector)
	hilo_t hiloProductor[NUM_HILOS];
	hilo_t hiloConsumidor[NUM_HILOS];

	/*
	Lanzar los NUM_HILOS productores y consumidores. Para lanzar cada hilo, hay que hacer los siguientes pasos:
		1. Asignar al campo relativo al identificador del hilo de la posición i-ésimo de los vectores de tipo DatosHilos_t (productores/consumidores) 
			i-ésimo de los vectores de hilos de productores/consumidores según corresponda
		2. Asignar al campo relativo a la pila acotada de la posición i-ésimo de los vectores de tipo DatosHilos_t (productores/consumidores) la dirección de memoria
			de la variable de tipo PilaAcotada definida al comienzo de la función main (poner & delante de la variable para acceder a su dirección de memoria)
		3. Asignar al hilo i-ésimo de los productores/consumidores la función hilo_productor/hilo_consumidor y la dirección de memoria del dato i-ésimo del 
		productor/consumidor según corresponda
		4. Lanzar el hilo productor/consumidor -iésimo
	*/
	for (int i=0; i<NUM_HILOS; i++) {
		productores[i].hilo=&hiloProductor[i];
		productores[i].pila=&pila;
		productores[i].hilo->AsignarFuncionYDato(hilo_productor, &productores[i]);
		productores[i].hilo->Lanzar();
		
		consumidores[i].hilo=&hiloConsumidor[i];
		consumidores[i].pila=&pila;
		consumidores[i].hilo->AsignarFuncionYDato(hilo_consumidor, &consumidores[i]);
		consumidores[i].hilo->Lanzar();
	}

	//Esperar a que terminen todos los productores y los consumidores
	for (int i=0; i<NUM_HILOS; i++) {
		hiloProductor[i].Join();
		hiloConsumidor[i].Join();
	}

	return 0;
}
