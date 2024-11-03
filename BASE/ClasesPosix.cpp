#include "ClasesPosix.h"
#include "Identificador.h"
#include <stdio.h>

Identificador_t Identificador;

/*
**********************************************************
********************** Clase hilo_t **********************
**********************************************************
*/

// Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación del hilo

// Guardar el resultado de Identificador.ObtenerId() en el atributo de clase que almacena el identificador del hilo

// Inicialización de los atributos de creación del hilo

// Inicialización de la función del hilo a NULL

// Inicialización de los datos de la función del hilo a NULL

// fin del constructor
hilo_t::hilo_t()
{
	idHilo = Identificador.ObtenerId();
	pthread_attr_init(&atributoH);
	funcionAsig = nullptr;
	dato = nullptr;
}

// Implementación del destructor sin parámetros. Este método destruirá los atributos de creación del hilo y liberará la memoria de los atributos de la clase

// Destrucción de los atributos de creación del hilo

// Fin del destructor
hilo_t::~hilo_t()
{
	pthread_attr_destroy(&atributoH);
}

// Implementación del método Lanzar. Este método se encargará de lanzar un hilo usando la función y los datos almacenados en la clase

// Si la función asociada existe (no es NULL)

/*Crear un hilo usando como parámetros la dirección de memoria al manejador del hilo, la dirección de memoria a los atributos de creación del hilo, la función del hilo y los datos del hilo.
Se devolverá el resultado de la llamada a pthread_create*/

// Si la función asociada no existe

// Devolver -1

// Fin de Lanzar
int hilo_t::Lanzar()
{
	if (funcionAsig != nullptr)
	{
		pthread_create(&manejador, &atributoH, funcionAsig, dato);
		return 0;
	}
	else
		return -1;
}

// Implementación del método AsignarFuncion. Asignará el parámetro recibido al atributo que almacena la función del hilo

// Asignar el parámetro del método al atributo de la clase que almacena la función asociada

// Fin de AsignarFuncion
void hilo_t::AsignarFuncion(void *(*hilo)(void *))
{
	funcionAsig = hilo;
}

// Implementación del método AsignarDato. Asignará el parámetro recibido al atributo que almacena los datos que se usarán con la función del hilo

// Asignar el parámetro del método al atributo de la clase que almacena el parámetro que se usará con la función asociada

// fin de AsignarDato
void hilo_t::AsignarDato(void *dat)
{
	dato = dat;
}

// Implementación del método AsignarFuncionYDato. Este método llamará a los métodos AsignarFuncion y AsignarDato con cada uno de sus parámetros

// Llamar a AsignarFuncion

// Llamar a AsignarDato

// Fin de AsignarFuncionYDato
void hilo_t::AsignarFuncionYDato(void *(*hilo)(void *), void *dat)
{
	AsignarFuncion(hilo);
	AsignarDato(dat);
}

// Implementación del método Join sin parámetros. Este método esperará por el hilo indicado por el manejador de la clase y retornará el valor devuelto por dicho hilo.

// Definir una variable de tipo puntero a void (debe ser puntero a void para permitir que se pueda devolver cualquier tipo de dato). No hay que reservar memoria.

// Esperar por el hilo asociado a la clase

// Devolver la variable definida en la primera línea del método.

// Fin de Join
void *hilo_t::Join()
{
	void *resultado;
	pthread_join(manejador, &resultado);
	return resultado;
}

// Implementación de método ObtenerManejador sin parámetros. Este método devolverá el valor del manejador del hilo asociado a la clase.

// Devolver el manejador del hilo

// Fin de ObtenerManejador
pthread_t hilo_t::ObtenerManejador()
{
	return manejador;
}

// Implementación de método ObtenerIdentificaror sin parámetros. Este método devolverá el valor del identificador del hilo asociado a la clase.

// Devolver el identificador del hilo

// Fin de ObtenerIdentificaror
int hilo_t::ObtenerIdentificador()
{
	return idHilo;
}

/*
**********************************************************
********************** Clase mutex_t *********************
**********************************************************
*/

// Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación del mutex

// Inicialización de los atributos de creación del mutex

// fin del constructor
mutex_t::mutex_t()
{
	pthread_mutexattr_init(&datosMutex);
}

// Implementación del destructor sin parámetros. Este método liberará la memoria de los atributos de la clase y destruirá el mutex y los atributos de creación del mutex

// Destrucción del mutex

// Destrucción de los atributos de creación del mutex

// fin del destructor
mutex_t::~mutex_t()
{
	pthread_mutex_destroy(&manejadorMutex);
	pthread_mutexattr_destroy(&datosMutex);
}

// Implementación del método Inicializar sin parámetros. Este método se encargará de inicializar el mutex usando los atributos de creación del mutex

/*Inicializar el mutex asociado a la clase usando como parámetros el manejador del mutex y los atributos de creación del mutex.
Debe retornar el valor que devuelva la función pthread_mutex_init*/

// Fin de Inicializar
int mutex_t::Inicializar()
{
	return pthread_mutex_init(&manejadorMutex, &datosMutex);
}

// Implementación del método Lock sin parámetros. Este método se encargará de acceder al mutex asociado a la clase usando el manejador del mutex de la clase

// Acceder al mutex con el manejador de la clase. Debe retornar el valor devuelto por dicha función.

// Fin de Lock
int mutex_t::Lock()
{
	return pthread_mutex_lock(&manejadorMutex);
}

// Implementación del método Unlock sin parámetros. Este método se encargará de liberar el mutex asociado a la clase usando el manejador del mutex de la clase

// Liberar el mutex asociado a la clase usando como parámetro el manejador del mutex. Debe retornar el valor devuelto por dicha función.

// Fin de Unlock
int mutex_t::Unlock()
{
	return pthread_mutex_unlock(&manejadorMutex);
}

// Implementación del método ObtenerManejador sin parámetros. Este método se encargará devolver el manejador del mutex de la clase

// Devolver el puntero al manejador del mutex de la clase, para lo que usaremos el operador & delante del nombre del mutex de la clase.

// Fin de ObtenerManejador
pthread_mutex_t *mutex_t::ObtenerManejador()
{
	return &manejadorMutex;
}

/*
**********************************************************
*************** Clase variable_condicion_t ***************
**********************************************************
*/

// Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación de la variable de condición

// Inicialización de los atributos de creación de la variable de condición

// Fin del constructor
variable_condicion_t::variable_condicion_t()
{
	pthread_condattr_init(&datosCondicion);
}

/*Implementación del destructor sin parámetros. Este método destruirá la variable de condición y los atributos de creación de la variable de condición
y liberará la memoria de los atributos de la clase*/

// Destrucción de la variable de condición

// Destrucción de los atributos de creación de la variable de condición

// Fin del destructor
variable_condicion_t::~variable_condicion_t()
{
	pthread_cond_destroy(&manejadorCondicion);
	pthread_condattr_destroy(&datosCondicion);
}

// Implementación del método Inicializar sin parámetros. Este método se encargará de inicializar la variable de condición usando los atributos de creación la variable de condición

// Inicializar la variable de condición usando los atributos de clase manejador y atributos de creación la variable de condición. Debe retornar el valor que devuelva dicha función*/

// Fin de Inicializar
int variable_condicion_t::Inicializar()
{
	return pthread_cond_init(&manejadorCondicion, &datosCondicion);
}

/*Implementación del método Inicializar con un parámetro de tipo puntero a pthread_mutex_t. Este método se encargará de asociar el mutex recibido por parámetro a la clase
(usar el método AsociarManejadorMutex) así como de inicializar la variable de condición usando los atributos de creación la variable de condición*/

// Llamar a AsociarManejadorMutex con el parámetro de entrada.

// Inicializar la variable de condición usando los atributos de clase manejador y atributos de creación la variable de condición. Debe retornar el valor que devuelva dicha función

// Fin de inicializar
int variable_condicion_t::Inicializar(pthread_mutex_t *condicion)
{
	AsociarManejadorMutex(condicion);
	return pthread_cond_init(&manejadorCondicion, &datosCondicion);
}

/*Implementación del método AsociarManejadorMutex con un parámetro de tipo puntero a pthread_mutex_t. Este método se encargará de asignar el parámetro de entrada de la función al
atributo de la clase que va a almacenar el mutex asociado. No es necesario reservar memoria para dicho atributo ya que, aunque es un puntero, también lo es el
parámetro de entrada. Al ser ambas variables punteros, el mutex asociado y el parámetro de entrada acabarán apuntando a la misma dirección de memoria.*/

// Asignar el parámetro de entrada al parámetro que almacenará el mutex asociado.

// Fin de AsociarManejadorMutex
void variable_condicion_t::AsociarManejadorMutex(pthread_mutex_t *condicion)
{
	this->variableCondicion = condicion;
}

// Implementación del método Wait sin parámetros. Este método se encargará de bloquear el hilo invocante en la variable de condición de la clase.

/*Llamar a la función de bloqueo en una variable de condición con los atributos de la clase manejador de la variable de condición y mutex asociado.
El método retornará el valor que devuelva dicha función.*/

// Fin de Wait
int variable_condicion_t::Wait()
{
	return pthread_cond_wait(&manejadorCondicion, variableCondicion);
}

/*Implementación del método TimedWait con un parámetro de tipo struct timespec. Este método se encargará de bloquear el hilo en la variable de condición de la clase
como máximo hasta el instante indicado por el parámetro de entrada.*/

/*Llamar a la función de bloqueo en una variable de cindición con límite temporal con los atributos de la clase manejador de la variable de condición, el mutex asociado
junto con el paránetro de entrada. El método retornará el valor que devuelva dicha función.*/

// Fin de TimedWait
int variable_condicion_t::TimedWait(timespec tiempo)
{
	return pthread_cond_timedwait(&manejadorCondicion, variableCondicion, &tiempo);
}

// Implementación del método Signal sin parámetros. Este método se encargará de liberar (al menos) un hilo bloqueado en la variable de condición de la clase.

/*Llamar a la función de liberación de (al menos) un hilo bloqueado en la variable de condición con el atributo de la clase manejador de la variable.
El método retornará el valor que devuelva dicha función.*/

// Fin de Signal
int variable_condicion_t::Signal()
{
	return pthread_cond_signal(&manejadorCondicion);
}

// Implementación del método Broadcast sin parámetros. Este método se encargará de liberar todos los hilos bloqueados en la variable de condición de la clase.

/*Llamar a la de liberación de todos los hilos bloqueados en cla variable de condición de la clase con el atributo de la clase manejador de la variable de condición.
El método retornará el valor que devuelva dicha función.*/

// Fin de Broadcast
int variable_condicion_t::Broadcast()
{
	return pthread_cond_broadcast(&manejadorCondicion);
}